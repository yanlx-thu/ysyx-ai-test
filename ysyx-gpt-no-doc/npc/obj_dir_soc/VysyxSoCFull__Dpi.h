// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYXSOCFULL__DPI_H_
#define VERILATED_VYSYXSOCFULL__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/yanlx/ysyx-workbench/ysyxSoC/perip/flash/flash.v:84:30
    extern void flash_read(int addr, int* data);
    // DPI import at /home/yanlx/ysyx-workbench/ysyxSoC/build/ysyxSoCFull.v:5706:30
    extern void mrom_read(int raddr, int* rdata);
    // DPI import at /home/yanlx/ysyx-workbench/npc/vsrc/ysyx_00000000.v:99:32
    extern void npc_ebreak(int code);
    // DPI import at /home/yanlx/ysyx-workbench/npc/vsrc/ysyx_00000000.v:92:32
    extern void npc_perf_sample(unsigned long long cycles, unsigned long long instret, unsigned long long ic_accesses, unsigned long long ic_misses, unsigned long long ic_miss_cycles);
    // DPI import at /home/yanlx/ysyx-workbench/ysyxSoC/perip/psram/psram_top_apb.v:3:29
    extern int pmem_read(int addr);
    // DPI import at /home/yanlx/ysyx-workbench/ysyxSoC/perip/psram/psram_top_apb.v:4:30
    extern void pmem_write(int addr, int data, char mask);
    // DPI import at /home/yanlx/ysyx-workbench/ysyxSoC/perip/uart16550/rtl/uart_top_apb.v:3:30
    extern void uart_putc(int ch);

#ifdef __cplusplus
}
#endif

#endif  // guard
