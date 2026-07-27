#include <verilated.h>

#ifndef NPC_SOC
#define NPC_SOC 0
#endif

#if NPC_SOC
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
using SimTop = VysyxSoCFull;
#else
#include "Vysyx_22040000.h"
#include "Vysyx_22040000___024root.h"
using SimTop = Vysyx_22040000;
#endif

#include <fcntl.h>
#include <unistd.h>

#include <cerrno>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

constexpr uint32_t PMEM_BASE = 0x80000000u;
constexpr uint32_t PMEM_SIZE = 128u * 1024u * 1024u;
constexpr uint32_t SERIAL_ADDR = 0xa00003f8u;
constexpr uint32_t UART16550_ADDR = 0x10000000u;
constexpr uint32_t RTC_ADDR = 0xa0000048u;
constexpr uint32_t CLINT_BASE = 0x02000000u;
constexpr uint32_t CLINT_MTIME = CLINT_BASE + 0xbff8u;

std::string hex32(uint32_t value) {
  char buf[16];
  std::snprintf(buf, sizeof(buf), "0x%08" PRIx32, value);
  return buf;
}

std::vector<uint8_t> read_file(const std::string &path) {
  std::ifstream in(path, std::ios::binary);
  if (!in) {
    throw std::runtime_error("cannot open image " + path);
  }
  in.seekg(0, std::ios::end);
  std::streamoff size = in.tellg();
  in.seekg(0, std::ios::beg);
  std::vector<uint8_t> data(size);
  if (size > 0) {
    in.read(reinterpret_cast<char *>(data.data()), size);
  }
  return data;
}

std::string choose_image(int argc, char **argv) {
  std::string image;
  for (int i = 1; i < argc; i++) {
    std::string arg(argv[i]);
    if (arg.rfind("--", 0) == 0) continue;
    image = arg;
  }
  if (!image.empty()) return image;
  const char *env_img = std::getenv("IMG");
  if (env_img && env_img[0] != '\0') return env_img;
  return "../ysyx-rt-thread/rt-thread-am/bsp/abstract-machine/build/rtthread-riscv32e-npc.bin";
}

uint64_t max_cycles_from_env() {
  const char *env = std::getenv("NPC_MAX_CYCLES");
  if (!env || env[0] == '\0') env = std::getenv("NPC_MAX_INSN");
  if (!env || env[0] == '\0') return 1000000000ull;
  char *end = nullptr;
  uint64_t value = std::strtoull(env, &end, 0);
  return end && *end == '\0' && value != 0 ? value : 1000000000ull;
}

void set_stdin_nonblock() {
  int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
  if (flags >= 0) {
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
  }
}

struct PerfStats {
  uint64_t cycles = 0;
  uint64_t instret = 0;
  uint64_t ic_accesses = 0;
  uint64_t ic_misses = 0;
  uint64_t ic_miss_cycles = 0;
};

#if NPC_SOC

std::vector<uint8_t> soc_pmem;
PerfStats soc_stats;
std::string soc_output_window;
bool soc_output_good_trap = false;
bool soc_output_bad_trap = false;
bool soc_microbench_started_flag = false;
bool soc_halt_seen = false;
uint32_t soc_halt_code = 0;

bool soc_in_pmem(uint32_t addr, size_t len = 1) {
  uint64_t off = uint64_t(addr) - PMEM_BASE;
  return addr >= PMEM_BASE && off + len <= soc_pmem.size();
}

void soc_check_output_trap() {
  constexpr size_t keep = 128;
  if (soc_output_window.size() > keep) {
    soc_output_window.erase(0, soc_output_window.size() - keep);
  }
  if (soc_output_window.find("HIT GOOD TRAP") != std::string::npos) {
    soc_output_good_trap = true;
  }
  if (soc_output_window.find("HIT BAD TRAP") != std::string::npos) {
    soc_output_bad_trap = true;
  }
  if (soc_output_window.find("======= Running MicroBench") != std::string::npos) {
    soc_microbench_started_flag = true;
  }
}

void soc_putc(uint8_t byte) {
  std::fputc(static_cast<char>(byte), stdout);
  std::fflush(stdout);
  soc_output_window.push_back(static_cast<char>(byte));
  soc_check_output_trap();
}

uint32_t soc_load_word(uint32_t addr) {
  if (soc_in_pmem(addr, 4)) {
    uint32_t value = 0;
    uint32_t off = addr - PMEM_BASE;
    value |= uint32_t(soc_pmem[off + 0]) << 0;
    value |= uint32_t(soc_pmem[off + 1]) << 8;
    value |= uint32_t(soc_pmem[off + 2]) << 16;
    value |= uint32_t(soc_pmem[off + 3]) << 24;
    return value;
  }

  if (addr >= CLINT_MTIME && addr < CLINT_MTIME + 8) {
    uint64_t value = soc_stats.cycles;
    return (addr & 4) ? uint32_t(value >> 32) : uint32_t(value);
  }

  if (addr >= RTC_ADDR && addr < RTC_ADDR + 8) {
    uint64_t value = soc_stats.cycles;
    return (addr & 4) ? uint32_t(value >> 32) : uint32_t(value);
  }

  return 0;
}

void soc_store_word(uint32_t addr, uint32_t data, uint8_t wstrb) {
  if (!soc_in_pmem(addr, 4)) return;

  uint32_t off = addr - PMEM_BASE;
  for (int i = 0; i < 4; i++) {
    if (wstrb & (1u << i)) {
      soc_pmem[off + i] = uint8_t(data >> (8 * i));
    }
  }
}

void load_soc_image(std::vector<uint8_t> image) {
  if (image.size() > PMEM_SIZE) {
    throw std::runtime_error("image is larger than simulated pmem");
  }
  soc_pmem.assign(PMEM_SIZE, 0);
  std::memcpy(soc_pmem.data(), image.data(), image.size());
  set_stdin_nonblock();
}

void tick(VysyxSoCFull &top) {
  top.externalPins_uart_rx = 1;
  top.clock = 0;
  top.eval();
  top.clock = 1;
  top.eval();
  top.clock = 0;
  top.eval();
}

PerfStats read_perf_stats(const VysyxSoCFull &) {
  return soc_stats;
}

#else

class AxiMemory {
 public:
  explicit AxiMemory(std::vector<uint8_t> image) : pmem_(PMEM_SIZE, 0) {
    if (image.size() > pmem_.size()) {
      throw std::runtime_error("image is larger than simulated pmem");
    }
    std::memcpy(pmem_.data(), image.data(), image.size());
    set_stdin_nonblock();
  }

  void drive(Vysyx_22040000 &top) {
    top.io_master_awready = 1;
    top.io_master_wready = 1;
    top.io_master_arready = 1;

    top.io_master_rvalid = read_.active ? 1 : 0;
    top.io_master_rresp = read_.resp;
    top.io_master_rdata = read_.data;
    top.io_master_rlast = read_.active && read_.beats_left == 1;
    top.io_master_rid = read_.id;

    top.io_master_bvalid = write_.bvalid ? 1 : 0;
    top.io_master_bresp = write_.bresp;
    top.io_master_bid = write_.bid;

    top.io_interrupt = 0;
    top.io_slave_awvalid = 0;
    top.io_slave_awaddr = 0;
    top.io_slave_awid = 0;
    top.io_slave_awlen = 0;
    top.io_slave_awsize = 0;
    top.io_slave_awburst = 0;
    top.io_slave_wvalid = 0;
    top.io_slave_wdata = 0;
    top.io_slave_wstrb = 0;
    top.io_slave_wlast = 0;
    top.io_slave_bready = 0;
    top.io_slave_arvalid = 0;
    top.io_slave_araddr = 0;
    top.io_slave_arid = 0;
    top.io_slave_arlen = 0;
    top.io_slave_arsize = 0;
    top.io_slave_arburst = 0;
    top.io_slave_rready = 0;
  }

  struct Sample {
    bool ar_fire = false;
    uint32_t araddr = 0;
    uint8_t arid = 0;
    uint8_t arlen = 0;
    uint8_t arsize = 0;
    uint8_t arburst = 0;

    bool r_fire = false;

    bool aw_fire = false;
    uint32_t awaddr = 0;
    uint8_t awid = 0;

    bool w_fire = false;
    uint32_t wdata = 0;
    uint8_t wstrb = 0;

    bool b_fire = false;
  };

  Sample capture(const Vysyx_22040000 &top) const {
    Sample s;
    s.ar_fire = top.io_master_arvalid && top.io_master_arready;
    s.araddr = top.io_master_araddr;
    s.arid = top.io_master_arid;
    s.arlen = top.io_master_arlen;
    s.arsize = top.io_master_arsize;
    s.arburst = top.io_master_arburst;

    s.r_fire = top.io_master_rvalid && top.io_master_rready;

    s.aw_fire = top.io_master_awvalid && top.io_master_awready;
    s.awaddr = top.io_master_awaddr;
    s.awid = top.io_master_awid;

    s.w_fire = top.io_master_wvalid && top.io_master_wready;
    s.wdata = top.io_master_wdata;
    s.wstrb = top.io_master_wstrb;

    s.b_fire = top.io_master_bvalid && top.io_master_bready;
    return s;
  }

  void commit(const Sample &s) {
    cycles_++;

    if (s.r_fire) {
      advance_read();
    }

    if (s.ar_fire) {
      if (read_.active) {
        std::fprintf(stderr, "\nNPC AXI warning: overlapping read at %s\n", hex32(s.araddr).c_str());
      } else {
        start_read(s.araddr, s.arlen, s.arsize, s.arburst, s.arid);
      }
    }

    if (s.b_fire) {
      write_.bvalid = false;
    }

    if (s.aw_fire) {
      write_.have_aw = true;
      write_.awaddr = s.awaddr;
      write_.bid = s.awid;
    }

    if (s.w_fire) {
      write_.have_w = true;
      write_.wdata = s.wdata;
      write_.wstrb = s.wstrb;
    }

    if (write_.have_aw && write_.have_w && !write_.bvalid) {
      store_word(write_.awaddr, write_.wdata, write_.wstrb);
      write_.bresp = 0;
      write_.bvalid = true;
      write_.have_aw = false;
      write_.have_w = false;
    }
  }

  bool output_good_trap() const { return output_good_trap_; }
  bool output_bad_trap() const { return output_bad_trap_; }
  bool microbench_started() const { return microbench_started_; }
  uint64_t cycles() const { return cycles_; }

 private:
  struct ReadState {
    bool active = false;
    uint32_t addr = 0;
    uint8_t beats_left = 0;
    uint8_t size = 2;
    uint8_t burst = 1;
    uint8_t id = 0;
    uint32_t data = 0;
    uint8_t resp = 0;
  };

  struct WriteState {
    bool have_aw = false;
    bool have_w = false;
    bool bvalid = false;
    uint32_t awaddr = 0;
    uint32_t wdata = 0;
    uint8_t wstrb = 0;
    uint8_t bresp = 0;
    uint8_t bid = 0;
  };

  std::vector<uint8_t> pmem_;
  std::deque<uint8_t> input_;
  ReadState read_;
  WriteState write_;
  uint64_t cycles_ = 0;
  std::string output_window_;
  bool output_good_trap_ = false;
  bool output_bad_trap_ = false;
  bool microbench_started_ = false;

  bool in_pmem(uint32_t addr, size_t len = 1) const {
    uint64_t off = uint64_t(addr) - PMEM_BASE;
    return addr >= PMEM_BASE && off + len <= pmem_.size();
  }

  void poll_stdin() {
    uint8_t buf[256];
    for (;;) {
      ssize_t n = read(STDIN_FILENO, buf, sizeof(buf));
      if (n > 0) {
        for (ssize_t i = 0; i < n; i++) input_.push_back(buf[i]);
        continue;
      }
      if (n == 0 || errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR) {
        break;
      }
      break;
    }
  }

  uint32_t load_word(uint32_t addr, uint8_t &resp) {
    resp = 0;
    if (in_pmem(addr, 4)) {
      uint32_t value = 0;
      uint32_t off = addr - PMEM_BASE;
      value |= uint32_t(pmem_[off + 0]) << 0;
      value |= uint32_t(pmem_[off + 1]) << 8;
      value |= uint32_t(pmem_[off + 2]) << 16;
      value |= uint32_t(pmem_[off + 3]) << 24;
      return value;
    }

    poll_stdin();
    if (addr == SERIAL_ADDR || addr == UART16550_ADDR) {
      if (input_.empty()) return 0xffffffffu;
      uint8_t ch = input_.front();
      input_.pop_front();
      return ch;
    }

    if (addr >= CLINT_MTIME && addr < CLINT_MTIME + 8) {
      uint64_t value = cycles_;
      return (addr & 4) ? uint32_t(value >> 32) : uint32_t(value);
    }

    if (addr >= RTC_ADDR && addr < RTC_ADDR + 8) {
      uint64_t value = cycles_;
      return (addr & 4) ? uint32_t(value >> 32) : uint32_t(value);
    }

    return 0;
  }

  void store_word(uint32_t addr, uint32_t data, uint8_t wstrb) {
    if (in_pmem(addr, 4)) {
      uint32_t off = addr - PMEM_BASE;
      for (int i = 0; i < 4; i++) {
        if (wstrb & (1u << i)) {
          pmem_[off + i] = uint8_t(data >> (8 * i));
        }
      }
      return;
    }

    for (int i = 0; i < 4; i++) {
      if ((wstrb & (1u << i)) == 0) continue;
      uint32_t byte_addr = addr + uint32_t(i);
      uint8_t byte = uint8_t(data >> (8 * i));
      if (byte_addr == SERIAL_ADDR || byte_addr == UART16550_ADDR) {
        std::fputc(static_cast<char>(byte), stdout);
        std::fflush(stdout);
        output_window_.push_back(static_cast<char>(byte));
        check_output_trap();
      }
    }
  }

  void check_output_trap() {
    constexpr size_t keep = 128;
    if (output_window_.size() > keep) {
      output_window_.erase(0, output_window_.size() - keep);
    }
    if (output_window_.find("HIT GOOD TRAP") != std::string::npos) {
      output_good_trap_ = true;
    }
    if (output_window_.find("HIT BAD TRAP") != std::string::npos) {
      output_bad_trap_ = true;
    }
    if (output_window_.find("======= Running MicroBench") != std::string::npos) {
      microbench_started_ = true;
    }
  }

  void prepare_read_data() {
    read_.data = load_word(read_.addr, read_.resp);
  }

  void start_read(uint32_t addr, uint8_t len, uint8_t size, uint8_t burst, uint8_t id) {
    read_.active = true;
    read_.addr = addr;
    read_.beats_left = uint8_t(len + 1);
    read_.size = size;
    read_.burst = burst;
    read_.id = id;
    prepare_read_data();
  }

  void advance_read() {
    if (!read_.active) return;
    if (read_.beats_left <= 1) {
      read_.active = false;
      read_.beats_left = 0;
      read_.data = 0;
      read_.resp = 0;
      return;
    }

    read_.beats_left--;
    if (read_.burst == 1) {
      read_.addr += uint32_t(1) << read_.size;
    }
    prepare_read_data();
  }
};

void tick(Vysyx_22040000 &top, AxiMemory &mem) {
  mem.drive(top);
  top.clock = 0;
  top.eval();
  AxiMemory::Sample sample = mem.capture(top);
  top.clock = 1;
  top.eval();
  mem.commit(sample);
  top.clock = 0;
  top.eval();
}

PerfStats read_perf_stats(const Vysyx_22040000 &top) {
  PerfStats stats;
  stats.cycles = top.rootp->ysyx_22040000__DOT__cycle_count;
  stats.instret = top.rootp->ysyx_22040000__DOT__instret_count;
  stats.ic_accesses = top.rootp->ysyx_22040000__DOT__icache_accesses;
  stats.ic_misses = top.rootp->ysyx_22040000__DOT__icache_misses;
  stats.ic_miss_cycles = top.rootp->ysyx_22040000__DOT__icache_miss_cycles;
  return stats;
}

#endif

void print_perf_delta(const char *label, const PerfStats &now, const PerfStats &base) {
  uint64_t cycles = now.cycles - base.cycles;
  uint64_t instret = now.instret - base.instret;
  uint64_t ic_accesses = now.ic_accesses - base.ic_accesses;
  uint64_t ic_misses = now.ic_misses - base.ic_misses;
  uint64_t ic_miss_cycles = now.ic_miss_cycles - base.ic_miss_cycles;
  double ipc = cycles == 0 ? 0.0 : static_cast<double>(instret) / static_cast<double>(cycles);
  double miss_rate = ic_accesses == 0 ? 0.0 : static_cast<double>(ic_misses) / static_cast<double>(ic_accesses);
  double amat = ic_accesses == 0 ? 0.0 :
      1.0 + static_cast<double>(ic_miss_cycles) / static_cast<double>(ic_accesses);

  std::printf("NPC PERF %s: cycles=%" PRIu64 " instret=%" PRIu64 " IPC=%.6f\n",
              label, cycles, instret, ipc);
  std::printf("NPC ICACHE %s: accesses=%" PRIu64 " misses=%" PRIu64
              " miss_rate=%.6f AMAT=%.6f cycles/access\n",
              label, ic_accesses, ic_misses, miss_rate, amat);
}

void print_perf_stats(const SimTop &top, bool have_bench_base,
                      const PerfStats &bench_base) {
  PerfStats now = read_perf_stats(top);
  PerfStats zero;
  print_perf_delta("total", now, zero);
  if (have_bench_base) {
    print_perf_delta("microbench", now, bench_base);
  }
}

}  // namespace

#if NPC_SOC
extern "C" int pmem_read(int addr) {
  return static_cast<int>(soc_load_word(static_cast<uint32_t>(addr)));
}

extern "C" void pmem_write(int addr, int data, unsigned char mask) {
  soc_store_word(static_cast<uint32_t>(addr), static_cast<uint32_t>(data), mask);
}

extern "C" void uart_putc(int ch) {
  soc_putc(static_cast<uint8_t>(ch));
}

extern "C" void flash_read(int addr, int *data) {
  *data = static_cast<int>(soc_load_word(PMEM_BASE + (static_cast<uint32_t>(addr) & (PMEM_SIZE - 1))));
}

extern "C" void mrom_read(int, int *data) {
  *data = 0;
}

extern "C" void npc_perf_sample(uint64_t cycles, uint64_t instret,
                                uint64_t ic_accesses, uint64_t ic_misses,
                                uint64_t ic_miss_cycles) {
  soc_stats.cycles = cycles;
  soc_stats.instret = instret;
  soc_stats.ic_accesses = ic_accesses;
  soc_stats.ic_misses = ic_misses;
  soc_stats.ic_miss_cycles = ic_miss_cycles;
}

extern "C" void npc_ebreak(int code) {
  soc_halt_seen = true;
  soc_halt_code = static_cast<uint32_t>(code);
}
#endif

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);

  try {
#if NPC_SOC
    load_soc_image(read_file(choose_image(argc, argv)));
    VysyxSoCFull top;
#else
    AxiMemory mem(read_file(choose_image(argc, argv)));
    Vysyx_22040000 top;
#endif
    top.clock = 0;
    top.reset = 1;

    for (int i = 0; i < 10; i++) {
#if NPC_SOC
      tick(top);
#else
      tick(top, mem);
#endif
    }
    top.reset = 0;

    uint64_t max_cycles = max_cycles_from_env();
    bool have_bench_base = false;
    PerfStats bench_base;
    for (uint64_t cycle = 0; cycle < max_cycles && !Verilated::gotFinish(); cycle++) {
#if NPC_SOC
      tick(top);

      if (!have_bench_base && soc_microbench_started_flag) {
        bench_base = read_perf_stats(top);
        have_bench_base = true;
      }

      if (soc_halt_seen) {
        print_perf_stats(top, have_bench_base, bench_base);
        if (soc_halt_code == 0) {
          std::printf("HIT GOOD TRAP\n");
          return 0;
        }
        std::printf("HIT BAD TRAP\n");
        return 1;
      }

      if (soc_output_good_trap) {
        print_perf_stats(top, have_bench_base, bench_base);
        return 0;
      }
      if (soc_output_bad_trap) {
        print_perf_stats(top, have_bench_base, bench_base);
        return 1;
      }
#else
      tick(top, mem);

      if (!have_bench_base && mem.microbench_started()) {
        bench_base = read_perf_stats(top);
        have_bench_base = true;
      }

      if (top.rootp->ysyx_22040000__DOT__debug_halt) {
        uint32_t code = top.rootp->ysyx_22040000__DOT__debug_halt_code;
        print_perf_stats(top, have_bench_base, bench_base);
        if (code == 0) {
          std::printf("HIT GOOD TRAP\n");
          return 0;
        }
        std::printf("HIT BAD TRAP\n");
        return 1;
      }

      if (mem.output_good_trap()) {
        print_perf_stats(top, have_bench_base, bench_base);
        return 0;
      }
      if (mem.output_bad_trap()) {
        print_perf_stats(top, have_bench_base, bench_base);
        return 1;
      }
#endif
    }

    print_perf_stats(top, have_bench_base, bench_base);
    std::fprintf(stderr, "\nNPC timeout after %" PRIu64 " cycles\n", max_cycles);
    return 1;
  } catch (const std::exception &e) {
    std::fprintf(stderr, "NPC startup failed: %s\n", e.what());
    return 1;
  }
}
