#include <verilated.h>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cerrno>
#include <vector>

#include "VNPC.h"

static constexpr uint32_t RESET_VECTOR = 0x80000000u;
static constexpr uint32_t MEM_SIZE = 128u * 1024u * 1024u;
static constexpr uint32_t SERIAL_PORT = 0xa00003f8u;
static constexpr uint32_t RTC_ADDR = 0xa0000048u;

static std::vector<uint8_t> pmem(MEM_SIZE);
static uint64_t g_cycles = 0;

static bool in_pmem(uint32_t addr) {
  return addr >= RESET_VECTOR && addr < RESET_VECTOR + MEM_SIZE;
}

static uint32_t host_read(uint32_t addr, int len) {
  uint32_t off = addr - RESET_VECTOR;
  uint32_t ret = 0;
  for (int i = 0; i < len; i++) {
    ret |= static_cast<uint32_t>(pmem[off + i]) << (i * 8);
  }
  return ret;
}

static void host_write(uint32_t addr, uint32_t data, int len) {
  uint32_t off = addr - RESET_VECTOR;
  for (int i = 0; i < len; i++) {
    pmem[off + i] = (data >> (i * 8)) & 0xffu;
  }
}

extern "C" int pmem_read(int raddr, char len) {
  uint32_t addr = static_cast<uint32_t>(raddr);
  int n = static_cast<int>(len);

  if (in_pmem(addr) && in_pmem(addr + n - 1)) {
    return static_cast<int>(host_read(addr, n));
  }

  if (addr == RTC_ADDR || addr == RTC_ADDR + 4) {
    uint64_t us = g_cycles;
    return static_cast<int>((addr == RTC_ADDR) ? (uint32_t)us : (uint32_t)(us >> 32));
  }

  std::fprintf(stderr, "npc: invalid read addr=0x%08x len=%d\n", addr, n);
  return 0;
}

extern "C" void pmem_write(int waddr, int wdata, char len) {
  uint32_t addr = static_cast<uint32_t>(waddr);
  uint32_t data = static_cast<uint32_t>(wdata);
  int n = static_cast<int>(len);

  if (addr == SERIAL_PORT) {
    std::fputc(data & 0xffu, stderr);
    std::fflush(stderr);
    return;
  }

  if (in_pmem(addr) && in_pmem(addr + n - 1)) {
    host_write(addr, data, n);
    return;
  }

  std::fprintf(stderr, "npc: invalid write addr=0x%08x data=0x%08x len=%d\n", addr, data, n);
}

static void load_img(const char *path) {
  FILE *fp = std::fopen(path, "rb");
  if (fp == nullptr) {
    std::perror(path);
    std::exit(1);
  }

  std::fseek(fp, 0, SEEK_END);
  long size = std::ftell(fp);
  std::fseek(fp, 0, SEEK_SET);
  if (size < 0 || static_cast<uint64_t>(size) > MEM_SIZE) {
    std::fprintf(stderr, "npc: bad image size %ld\n", size);
    std::exit(1);
  }

  size_t nread = std::fread(pmem.data(), 1, size, fp);
  std::fclose(fp);
  if (nread != static_cast<size_t>(size)) {
    std::fprintf(stderr, "npc: failed to read image\n");
    std::exit(1);
  }

  std::fprintf(stderr, "npc: image %s, size = %ld\n", path, size);
}

static uint64_t get_max_cycles() {
  const char *env = std::getenv("NPC_MAX_CYCLES");
  if (env == nullptr || *env == '\0') {
    return 0;
  }

  errno = 0;
  char *end = nullptr;
  uint64_t value = std::strtoull(env, &end, 0);
  if (errno != 0 || end == env || *end != '\0') {
    std::fprintf(stderr, "npc: bad NPC_MAX_CYCLES value '%s'\n", env);
    std::exit(1);
  }
  return value;
}

int main(int argc, char **argv) {
  if (argc < 2 || argv[1] == nullptr || std::strlen(argv[1]) == 0) {
    std::fprintf(stderr, "Usage: %s IMAGE\n", argv[0]);
    return 1;
  }

  load_img(argv[1]);

  VerilatedContext context;
  VNPC top{&context};

  top.clk = 0;
  top.reset = 1;
  top.eval();
  top.clk = 1;
  top.eval();
  top.clk = 0;
  top.reset = 0;
  top.eval();

  const uint64_t max_cycles = get_max_cycles();
  while (!context.gotFinish() && !top.halt && (max_cycles == 0 || g_cycles < max_cycles)) {
    top.clk = 1;
    top.eval();
    top.clk = 0;
    top.eval();
    g_cycles++;
  }

  if (!top.halt) {
    if (max_cycles != 0 && g_cycles >= max_cycles) {
      std::fprintf(stderr, "npc: timeout after %lu cycles at pc=0x%08x\n",
          static_cast<unsigned long>(g_cycles), top.pc_out);
    } else {
      std::fprintf(stderr, "npc: stopped without trap at pc=0x%08x after %lu cycles\n",
          top.pc_out, static_cast<unsigned long>(g_cycles));
    }
    return 1;
  }

  uint32_t code = top.halt_code;
  std::fprintf(stderr, "npc: %s at pc=0x%08x after %lu cycles\n",
      code == 0 ? "HIT GOOD TRAP" : "HIT BAD TRAP",
      top.pc_out, static_cast<unsigned long>(g_cycles));
  return code == 0 ? 0 : 1;
}
