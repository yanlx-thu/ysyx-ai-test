TOP       = NPC
BUILD_DIR = build
OBJ_DIR   = $(BUILD_DIR)/obj_dir
BIN       = $(BUILD_DIR)/npc
SOC_TOP   = ysyxSoCFull
SOC_OBJ_DIR = $(BUILD_DIR)/obj_dir_soc
SOC_BIN   = $(BUILD_DIR)/ysyxsoc
export CCACHE_DIR := $(abspath $(BUILD_DIR)/ccache)
VSRCS     = $(abspath vsrc/NPC.sv)
CSRCS     = $(abspath csrc/main.cpp)
SOC_ROOT  = $(abspath ../ysyxSoC)
SOC_VSRCS = $(abspath vsrc/ysyx_00000000.sv) \
            $(SOC_ROOT)/ready-to-run/D-stage/ysyxSoCFull.v \
            $(SOC_ROOT)/perip/amba/apb_delayer.v \
            $(SOC_ROOT)/perip/bitrev/bitrev.v \
            $(SOC_ROOT)/perip/flash/flash.v \
            $(SOC_ROOT)/perip/spi/rtl/spi_clgen.v \
            $(SOC_ROOT)/perip/spi/rtl/spi_shift.v \
            $(SOC_ROOT)/perip/spi/rtl/spi_top.v \
            $(SOC_ROOT)/perip/spi/rtl/spi_top_apb.v \
            $(SOC_ROOT)/perip/uart16550/rtl/raminfr.v \
            $(SOC_ROOT)/perip/uart16550/rtl/uart_receiver.v \
            $(SOC_ROOT)/perip/uart16550/rtl/uart_rfifo.v \
            $(SOC_ROOT)/perip/uart16550/rtl/uart_regs.v \
            $(SOC_ROOT)/perip/uart16550/rtl/uart_sync_flops.v \
            $(SOC_ROOT)/perip/uart16550/rtl/uart_tfifo.v \
            $(SOC_ROOT)/perip/uart16550/rtl/uart_transmitter.v \
            $(SOC_ROOT)/perip/uart16550/rtl/uart_top_apb.v \
            $(SOC_ROOT)/perip/sdram/sdram_top_apb.v \
            $(SOC_ROOT)/perip/sdram/core_sdram_axi4/sdram_axi.v \
            $(SOC_ROOT)/perip/sdram/core_sdram_axi4/sdram_axi_core.v \
            $(SOC_ROOT)/perip/sdram/core_sdram_axi4/sdram_axi_pmem.v
SOC_CSRCS = $(abspath csrc/soc_main.cpp)

VERILATOR_FLAGS += --cc --exe --build -j 0 -Wall
VERILATOR_FLAGS += --top-module $(TOP)
VERILATOR_FLAGS += --Mdir $(OBJ_DIR)
VERILATOR_FLAGS += -Wno-DECLFILENAME -Wno-UNUSED -Wno-WIDTH -Wno-BLKSEQ
VERILATOR_FLAGS += -CFLAGS "-std=c++17 -O2"

SOC_VERILATOR_FLAGS += --cc --exe --build -j 0 -Wall -sv -DFAST_FLASH -DFAST_SDRAM --no-timing
SOC_VERILATOR_FLAGS += --top-module $(SOC_TOP)
SOC_VERILATOR_FLAGS += --Mdir $(SOC_OBJ_DIR)
SOC_VERILATOR_FLAGS += +incdir+$(SOC_ROOT)/perip/spi/rtl
SOC_VERILATOR_FLAGS += +incdir+$(SOC_ROOT)/perip/uart16550/rtl
SOC_VERILATOR_FLAGS += -Wno-DECLFILENAME -Wno-UNUSED -Wno-WIDTH -Wno-BLKSEQ -Wno-STMTDLY
SOC_VERILATOR_FLAGS += -Wno-PINCONNECTEMPTY -Wno-TIMESCALEMOD -Wno-DEFPARAM
SOC_VERILATOR_FLAGS += -Wno-ASSIGNDLY -Wno-SYNCASYNCNET
SOC_VERILATOR_FLAGS += -CFLAGS "-std=c++17 -O2"

all: $(BIN)

$(BIN): $(VSRCS) $(CSRCS)
	@mkdir -p $(BUILD_DIR)
	verilator $(VERILATOR_FLAGS) $(VSRCS) $(CSRCS)
	@cp $(OBJ_DIR)/V$(TOP) $(BIN)

run: $(BIN)
	$(BIN) $(IMG)

sim: run

soc: $(SOC_BIN)

$(SOC_BIN): $(SOC_VSRCS) $(SOC_CSRCS)
	@mkdir -p $(BUILD_DIR)
	verilator $(SOC_VERILATOR_FLAGS) $(SOC_VSRCS) $(SOC_CSRCS)
	@cp $(SOC_OBJ_DIR)/V$(SOC_TOP) $(SOC_BIN)

soc-run: $(SOC_BIN)
	$(SOC_BIN) $(IMG)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run sim soc soc-run clean
