#include <verilated.h>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cerrno>
#include <chrono>
#include <vector>
#include <string>

#include "VysyxSoCFull.h"

static std::vector<uint8_t> flash_img;
static std::vector<uint8_t> sdram_img(16 * 1024 * 1024, 0);
static constexpr uint32_t TIMER_MMIO_OFF = 0x00ffff00u;
static std::string uart_log;
static const char *expected_output = nullptr;
static bool expected_seen = false;
static bool program_halted = false;
static bool uart_seen = false;
static uint64_t commit_count = 0;
static uint64_t cpu_tick_count = 0;
static uint64_t bus_tick_count = 0;
static uint64_t flash_read_count = 0;
static uint64_t flash_write_count = 0;
static uint64_t sdram_read_count = 0;
static uint64_t sdram_write_count = 0;
static uint64_t sim_cycle_count = 0;
static uint32_t last_pc = 0;
static uint32_t last_inst = 0;
static uint32_t last_state = 0;
static uint32_t last_ifu_rdata = 0;
static uint32_t last_ifu_resp = 0;
static uint32_t last_lsu_resp = 0;
static bool trace_commit = false;

extern "C" void flash_read(int addr, int *data) {
  flash_read_count++;
  uint32_t off = static_cast<uint32_t>(addr);
  uint32_t value = 0;
  if (off == TIMER_MMIO_OFF || off == TIMER_MMIO_OFF + 4) {
    value = (off == TIMER_MMIO_OFF) ? static_cast<uint32_t>(sim_cycle_count)
                                    : static_cast<uint32_t>(sim_cycle_count >> 32);
    *data = static_cast<int>(value);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (off + static_cast<uint32_t>(i) < flash_img.size()) {
      value |= static_cast<uint32_t>(flash_img[off + i]) << (i * 8);
    }
  }
  *data = static_cast<int>(value);
  if (trace_commit && (flash_read_count <= 40 || (flash_read_count % 10000) == 0)) {
    std::fprintf(stderr, "soc: flash_read #%lu addr=0x%08x data=0x%08x\n",
        static_cast<unsigned long>(flash_read_count), off, value);
  }
}

extern "C" void flash_write(int addr, int data, int strb) {
  flash_write_count++;
  uint32_t off = static_cast<uint32_t>(addr);
  uint32_t value = static_cast<uint32_t>(data);
  uint32_t mask = static_cast<uint32_t>(strb);
  uint32_t end = off + 4;
  if (end > flash_img.size()) {
    flash_img.resize(end, 0);
  }
  for (int i = 0; i < 4; i++) {
    if ((mask & (1u << i)) != 0) {
      flash_img[off + static_cast<uint32_t>(i)] = static_cast<uint8_t>(value >> (i * 8));
    }
  }
  if (trace_commit && (flash_write_count <= 40 || (flash_write_count % 10000) == 0)) {
    std::fprintf(stderr, "soc: flash_write #%lu addr=0x%08x data=0x%08x strb=0x%x\n",
        static_cast<unsigned long>(flash_write_count), off, value, mask & 0xf);
  }
}

extern "C" int soc_sdram_read(int addr) {
  sdram_read_count++;
  uint32_t off = (static_cast<uint32_t>(addr) & ~3u) & static_cast<uint32_t>(sdram_img.size() - 1);
  uint32_t value = 0;
  for (int i = 0; i < 4; i++) {
    value |= static_cast<uint32_t>(sdram_img[(off + static_cast<uint32_t>(i)) & (sdram_img.size() - 1)])
        << (i * 8);
  }
  if (trace_commit && (sdram_read_count <= 40 || (sdram_read_count % 10000) == 0)) {
    std::fprintf(stderr, "soc: sdram_read #%lu addr=0x%08x data=0x%08x\n",
        static_cast<unsigned long>(sdram_read_count), static_cast<uint32_t>(addr), value);
  }
  return static_cast<int>(value);
}

extern "C" void soc_sdram_write(int addr, int data, int strb) {
  sdram_write_count++;
  uint32_t off = (static_cast<uint32_t>(addr) & ~3u) & static_cast<uint32_t>(sdram_img.size() - 1);
  uint32_t value = static_cast<uint32_t>(data);
  uint32_t mask = static_cast<uint32_t>(strb);
  for (int i = 0; i < 4; i++) {
    if ((mask & (1u << i)) != 0) {
      sdram_img[(off + static_cast<uint32_t>(i)) & (sdram_img.size() - 1)] =
          static_cast<uint8_t>(value >> (i * 8));
    }
  }
  if (trace_commit && (sdram_write_count <= 40 || (sdram_write_count % 10000) == 0)) {
    std::fprintf(stderr, "soc: sdram_write #%lu addr=0x%08x data=0x%08x strb=0x%x\n",
        static_cast<unsigned long>(sdram_write_count), static_cast<uint32_t>(addr),
        value, mask & 0xf);
  }
}

extern "C" void soc_uart_putc(int ch) {
  uart_seen = true;
  char c = static_cast<char>(ch & 0xff);
  if (uart_log.size() < (1u << 20)) {
    uart_log.push_back(c);
  }
  if (expected_output != nullptr && *expected_output != '\0' && !expected_seen) {
    expected_seen = uart_log.find(expected_output) != std::string::npos;
  }
  std::fputc(c, stderr);
  std::fflush(stderr);
}

extern "C" void soc_cpu_commit(int pc, int inst) {
  commit_count++;
  last_pc = static_cast<uint32_t>(pc);
  last_inst = static_cast<uint32_t>(inst);
  if (last_inst == 0x00100073u) {
    program_halted = true;
  }
  if (trace_commit) {
    std::fprintf(stderr, "soc: commit #%lu pc=0x%08x inst=0x%08x\n",
        static_cast<unsigned long>(commit_count), last_pc, last_inst);
  }
}

extern "C" void soc_cpu_tick(int reset, int state, int pc, int ifu_resp, int ifu_rdata, int lsu_resp) {
  cpu_tick_count++;
  last_state = static_cast<uint32_t>(state);
  last_pc = static_cast<uint32_t>(pc);
  last_ifu_resp = static_cast<uint32_t>(ifu_resp);
  last_ifu_rdata = static_cast<uint32_t>(ifu_rdata);
  last_lsu_resp = static_cast<uint32_t>(lsu_resp);
  if (trace_commit && (cpu_tick_count <= 80 || (cpu_tick_count % 10000) == 0)) {
    std::fprintf(stderr,
        "soc: tick #%lu reset=%d state=%u pc=0x%08x ifu_resp=%d ifu_rdata=0x%08x lsu_resp=%d\n",
        static_cast<unsigned long>(cpu_tick_count), reset, last_state, last_pc,
        ifu_resp, last_ifu_rdata, lsu_resp);
  }
}

extern "C" void soc_bus_tick(
    int reset, int cpu_reset,
    int cpu_arvalid, int cpu_arready, int cpu_araddr,
    int cpu_rvalid, int cpu_rready, int cpu_rdata,
    int buf_arvalid, int buf_arready, int buf_araddr,
    int apb_psel, int apb_penable, int apb_pready, int apb_paddr, int apb_prdata,
    int spi_psel, int spi_penable, int spi_pready, int spi_prdata) {
  bus_tick_count++;
  if (!trace_commit) {
    return;
  }

  if (bus_tick_count <= 120 || (bus_tick_count % 10000) == 0) {
    std::fprintf(stderr,
        "soc: bus #%lu rst=%d crst=%d cpu_ar=%d/%d@0x%08x cpu_r=%d/%d=0x%08x "
        "buf_ar=%d/%d@0x%08x apb=%d/%d/%d@0x%08x=0x%08x spi=%d/%d/%d=0x%08x\n",
        static_cast<unsigned long>(bus_tick_count), reset, cpu_reset,
        cpu_arvalid, cpu_arready, static_cast<uint32_t>(cpu_araddr),
        cpu_rvalid, cpu_rready, static_cast<uint32_t>(cpu_rdata),
        buf_arvalid, buf_arready, static_cast<uint32_t>(buf_araddr),
        apb_psel, apb_penable, apb_pready, static_cast<uint32_t>(apb_paddr),
        static_cast<uint32_t>(apb_prdata),
        spi_psel, spi_penable, spi_pready, static_cast<uint32_t>(spi_prdata));
  }
}

static uint64_t get_max_cycles() {
  const char *env = std::getenv("SOC_MAX_CYCLES");
  if (env == nullptr || *env == '\0') {
    return 200000000ull;
  }

  errno = 0;
  char *end = nullptr;
  uint64_t value = std::strtoull(env, &end, 0);
  if (errno != 0 || end == env || *end != '\0') {
    std::fprintf(stderr, "soc: bad SOC_MAX_CYCLES value '%s'\n", env);
    std::exit(1);
  }
  return value;
}

static void print_ipc_stats(uint64_t cycles) {
  double ipc = cycles == 0 ? 0.0 : static_cast<double>(commit_count) / static_cast<double>(cycles);
  std::fprintf(stderr, "soc: total cycles = %lu, total instructions = %lu, IPC = %.6f\n",
      static_cast<unsigned long>(cycles), static_cast<unsigned long>(commit_count), ipc);
}

static void print_host_elapsed(std::chrono::steady_clock::time_point start) {
  auto elapsed = std::chrono::steady_clock::now() - start;
  double seconds = std::chrono::duration<double>(elapsed).count();
  std::fprintf(stderr, "soc: host elapsed time = %.3f s\n", seconds);
}

static void load_flash(const char *path) {
  FILE *fp = std::fopen(path, "rb");
  if (fp == nullptr) {
    std::perror(path);
    std::exit(1);
  }

  std::fseek(fp, 0, SEEK_END);
  long size = std::ftell(fp);
  std::fseek(fp, 0, SEEK_SET);
  if (size < 0) {
    std::fprintf(stderr, "soc: bad image size %ld\n", size);
    std::exit(1);
  }

  flash_img.assign(static_cast<size_t>(size), 0);
  size_t nread = std::fread(flash_img.data(), 1, flash_img.size(), fp);
  std::fclose(fp);
  if (nread != flash_img.size()) {
    std::fprintf(stderr, "soc: failed to read flash image\n");
    std::exit(1);
  }

  std::fprintf(stderr, "soc: flash image %s, size = %ld\n", path, size);
}

int main(int argc, char **argv) {
  if (argc < 2 || argv[1] == nullptr || std::strlen(argv[1]) == 0) {
    std::fprintf(stderr, "Usage: %s FLASH_IMAGE\n", argv[0]);
    return 1;
  }

  load_flash(argv[1]);
  uint64_t max_cycles = get_max_cycles();
  trace_commit = std::getenv("SOC_TRACE") != nullptr;
  expected_output = std::getenv("SOC_EXPECT");

  VerilatedContext context;
  VysyxSoCFull top{&context};

  top.clock = 0;
  top.reset = 1;
  top.externalPins_uart_rx = 1;
  for (int i = 0; i < 20; i++) {
    top.clock = 0;
    top.eval();
    top.clock = 1;
    top.eval();
  }
  top.clock = 0;
  top.reset = 0;
  top.eval();

  uint64_t cycles = 0;
  sim_cycle_count = 0;
  auto host_start = std::chrono::steady_clock::now();
  while (!context.gotFinish() && cycles < max_cycles && !program_halted && !expected_seen) {
    sim_cycle_count = cycles;
    top.clock = 0;
    top.eval();
    top.clock = 1;
    top.eval();
    cycles++;
    sim_cycle_count = cycles;
  }

  if (context.gotFinish()) {
    std::fprintf(stderr, "\nsoc: stopped by Verilator after %lu cycles\n",
        static_cast<unsigned long>(cycles));
    print_ipc_stats(cycles);
    print_host_elapsed(host_start);
    return 1;
  }

  if (program_halted) {
    std::fprintf(stderr,
        "\nsoc: program halted after %lu cycles, commits=%lu ticks=%lu"
        " last_pc=0x%08x last_inst=0x%08x\n",
        static_cast<unsigned long>(cycles), static_cast<unsigned long>(commit_count),
        static_cast<unsigned long>(cpu_tick_count), last_pc, last_inst);
    print_ipc_stats(cycles);
    print_host_elapsed(host_start);
    if (expected_output != nullptr && *expected_output != '\0') {
      return expected_seen ? 0 : 1;
    }
    return 0;
  }

  if (expected_output != nullptr && *expected_output != '\0') {
    std::fprintf(stderr, "\nsoc: expected output \"%s\" %s after %lu cycles\n",
        expected_output, expected_seen ? "seen" : "not seen",
        static_cast<unsigned long>(cycles));
    print_ipc_stats(cycles);
    print_host_elapsed(host_start);
    return expected_seen ? 0 : 1;
  }

  std::fprintf(stderr,
        "\nsoc: reached cycle limit %lu%s, commits=%lu ticks=%lu state=%u"
        " last_pc=0x%08x last_inst=0x%08x ifu_resp=%u ifu_rdata=0x%08x lsu_resp=%u"
      " flash_reads=%lu flash_writes=%lu sdram_reads=%lu sdram_writes=%lu\n",
      static_cast<unsigned long>(cycles), uart_seen ? "" : " without UART output",
      static_cast<unsigned long>(commit_count), static_cast<unsigned long>(cpu_tick_count),
      last_state, last_pc, last_inst, last_ifu_resp, last_ifu_rdata, last_lsu_resp,
      static_cast<unsigned long>(flash_read_count), static_cast<unsigned long>(flash_write_count),
      static_cast<unsigned long>(sdram_read_count),
      static_cast<unsigned long>(sdram_write_count));
  print_ipc_stats(cycles);
  print_host_elapsed(host_start);
  return uart_seen ? 0 : 1;
}
