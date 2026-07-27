TOPNAME = ysyx_22040000
BUILD_DIR = ./obj_dir
BIN = $(BUILD_DIR)/V$(TOPNAME)
VSRCS = $(abspath ./vsrc/ysyx_22040000.v)
CSRCS = $(shell find $(abspath ./csrc) -name "*.cpp")

SOC_TOPNAME = ysyxSoCFull
SOC_BUILD_DIR = ./obj_dir_soc
SOC_BIN = $(SOC_BUILD_DIR)/V$(SOC_TOPNAME)
SOC_V_FILE = ../ysyxSoC/build/ysyxSoCFull.v
SOC_VSRCS = $(abspath $(SOC_V_FILE)) \
            $(abspath ./vsrc/ysyx_22040000.v) \
            $(abspath ./vsrc/ysyx_00000000.v) \
            $(shell find $(abspath ../ysyxSoC/perip) -name "*.v")

IMG ?= ../ysyx-rt-thread/rt-thread-am/bsp/abstract-machine/build/rtthread-riscv32e-npc.bin
VERILATOR_FLAGS += --cc --exe --build --top-module $(TOPNAME)
VERILATOR_FLAGS += --Mdir $(BUILD_DIR) --Wno-fatal --Wno-UNUSEDSIGNAL --Wno-UNUSEDPARAM
VERILATOR_FLAGS += -GRESET_VECTOR=2147483648
VERILATOR_FLAGS += -CFLAGS "-std=c++17 -O2"

SOC_VERILATOR_FLAGS += --cc --exe --build --top-module $(SOC_TOPNAME)
SOC_VERILATOR_FLAGS += --Mdir $(SOC_BUILD_DIR) --Wno-fatal --Wno-UNUSEDSIGNAL --Wno-UNUSEDPARAM
SOC_VERILATOR_FLAGS += --no-timing
SOC_VERILATOR_FLAGS += -DNPC_SOC_SIM
SOC_VERILATOR_FLAGS += -I$(abspath ../ysyxSoC/perip/uart16550/rtl)
SOC_VERILATOR_FLAGS += -I$(abspath ../ysyxSoC/perip/spi/rtl)
SOC_VERILATOR_FLAGS += -CFLAGS "-std=c++17 -O2 -DNPC_SOC=1"

all: $(BIN)

$(BIN): $(VSRCS) $(CSRCS)
	verilator $(VERILATOR_FLAGS) $(VSRCS) $(CSRCS)

$(SOC_V_FILE):
	$(MAKE) -C ../ysyxSoC verilog

$(SOC_BIN): $(SOC_V_FILE) $(SOC_VSRCS) $(CSRCS)
	verilator $(SOC_VERILATOR_FLAGS) $(SOC_VSRCS) $(CSRCS)

sim: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(BIN) $(ARGS) $(IMG)

soc: $(SOC_BIN)
	$(call git_commit, "sim SoC") # DO NOT REMOVE THIS LINE!!!
	$(SOC_BIN) $(ARGS) $(IMG)

clean:
	rm -rf $(BUILD_DIR) $(SOC_BUILD_DIR)

include ../Makefile

.PHONY: all sim soc clean
