// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_22040000.h for the primary calling header

#ifndef VERILATED_VYSYX_22040000___024ROOT_H_
#define VERILATED_VYSYX_22040000___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_22040000__Syms;

class Vysyx_22040000___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_interrupt,0,0);
        VL_IN8(io_master_awready,0,0);
        VL_OUT8(io_master_awvalid,0,0);
        VL_OUT8(io_master_awid,3,0);
        VL_OUT8(io_master_awlen,7,0);
        VL_OUT8(io_master_awsize,2,0);
        VL_OUT8(io_master_awburst,1,0);
        VL_IN8(io_master_wready,0,0);
        VL_OUT8(io_master_wvalid,0,0);
        VL_OUT8(io_master_wstrb,3,0);
        VL_OUT8(io_master_wlast,0,0);
        VL_OUT8(io_master_bready,0,0);
        VL_IN8(io_master_bvalid,0,0);
        VL_IN8(io_master_bresp,1,0);
        VL_IN8(io_master_bid,3,0);
        VL_IN8(io_master_arready,0,0);
        VL_OUT8(io_master_arvalid,0,0);
        VL_OUT8(io_master_arid,3,0);
        VL_OUT8(io_master_arlen,7,0);
        VL_OUT8(io_master_arsize,2,0);
        VL_OUT8(io_master_arburst,1,0);
        VL_OUT8(io_master_rready,0,0);
        VL_IN8(io_master_rvalid,0,0);
        VL_IN8(io_master_rresp,1,0);
        VL_IN8(io_master_rlast,0,0);
        VL_IN8(io_master_rid,3,0);
        VL_OUT8(io_slave_awready,0,0);
        VL_IN8(io_slave_awvalid,0,0);
        VL_IN8(io_slave_awid,3,0);
        VL_IN8(io_slave_awlen,7,0);
        VL_IN8(io_slave_awsize,2,0);
        VL_IN8(io_slave_awburst,1,0);
        VL_OUT8(io_slave_wready,0,0);
        VL_IN8(io_slave_wvalid,0,0);
        VL_IN8(io_slave_wstrb,3,0);
        VL_IN8(io_slave_wlast,0,0);
        VL_IN8(io_slave_bready,0,0);
        VL_OUT8(io_slave_bvalid,0,0);
        VL_OUT8(io_slave_bresp,1,0);
        VL_OUT8(io_slave_bid,3,0);
        VL_OUT8(io_slave_arready,0,0);
        VL_IN8(io_slave_arvalid,0,0);
        VL_IN8(io_slave_arid,3,0);
        VL_IN8(io_slave_arlen,7,0);
        VL_IN8(io_slave_arsize,2,0);
        VL_IN8(io_slave_arburst,1,0);
        VL_IN8(io_slave_rready,0,0);
        VL_OUT8(io_slave_rvalid,0,0);
        VL_OUT8(io_slave_rresp,1,0);
        VL_OUT8(io_slave_rlast,0,0);
        VL_OUT8(io_slave_rid,3,0);
        CData/*3:0*/ ysyx_22040000__DOT__state;
        CData/*0:0*/ ysyx_22040000__DOT__debug_halt;
        CData/*1:0*/ ysyx_22040000__DOT__ic_valid;
        CData/*0:0*/ ysyx_22040000__DOT__miss_index;
        CData/*1:0*/ ysyx_22040000__DOT__miss_word;
        CData/*1:0*/ ysyx_22040000__DOT__miss_target_word;
        CData/*3:0*/ ysyx_22040000__DOT__mem_wstrb;
        CData/*4:0*/ ysyx_22040000__DOT__mem_rd;
        CData/*1:0*/ ysyx_22040000__DOT__mem_size;
        CData/*0:0*/ ysyx_22040000__DOT__mem_unsigned;
        CData/*0:0*/ ysyx_22040000__DOT__tmp_do_write;
    };
    struct {
        CData/*0:0*/ ysyx_22040000__DOT__tmp_take_branch;
        CData/*6:0*/ ysyx_22040000__DOT__opcode;
        CData/*4:0*/ ysyx_22040000__DOT__rd;
        CData/*2:0*/ ysyx_22040000__DOT__funct3;
        CData/*4:0*/ ysyx_22040000__DOT__rs1;
        CData/*4:0*/ ysyx_22040000__DOT__rs2;
        CData/*6:0*/ ysyx_22040000__DOT__funct7;
        CData/*0:0*/ ysyx_22040000__DOT__if_hit;
        CData/*0:0*/ __Vtrigrprev__TOP__clock;
        CData/*0:0*/ __VactContinue;
        SData/*11:0*/ ysyx_22040000__DOT__csr_id;
        VL_OUT(io_master_awaddr,31,0);
        VL_OUT(io_master_wdata,31,0);
        VL_OUT(io_master_araddr,31,0);
        VL_IN(io_master_rdata,31,0);
        VL_IN(io_slave_awaddr,31,0);
        VL_IN(io_slave_wdata,31,0);
        VL_IN(io_slave_araddr,31,0);
        VL_OUT(io_slave_rdata,31,0);
        IData/*31:0*/ ysyx_22040000__DOT__pc;
        IData/*31:0*/ ysyx_22040000__DOT__inst;
        IData/*31:0*/ ysyx_22040000__DOT__inst_pc;
        IData/*31:0*/ ysyx_22040000__DOT__csr_mtvec;
        IData/*31:0*/ ysyx_22040000__DOT__csr_mepc;
        IData/*31:0*/ ysyx_22040000__DOT__csr_mcause;
        IData/*31:0*/ ysyx_22040000__DOT__debug_halt_code;
        IData/*26:0*/ ysyx_22040000__DOT__ic_tag0;
        IData/*26:0*/ ysyx_22040000__DOT__ic_tag1;
        IData/*31:0*/ ysyx_22040000__DOT__ic0_word0;
        IData/*31:0*/ ysyx_22040000__DOT__ic0_word1;
        IData/*31:0*/ ysyx_22040000__DOT__ic0_word2;
        IData/*31:0*/ ysyx_22040000__DOT__ic0_word3;
        IData/*31:0*/ ysyx_22040000__DOT__ic1_word0;
        IData/*31:0*/ ysyx_22040000__DOT__ic1_word1;
        IData/*31:0*/ ysyx_22040000__DOT__ic1_word2;
        IData/*31:0*/ ysyx_22040000__DOT__ic1_word3;
        IData/*31:0*/ ysyx_22040000__DOT__miss_addr;
        IData/*26:0*/ ysyx_22040000__DOT__miss_tag;
        IData/*31:0*/ ysyx_22040000__DOT__miss_saved_inst;
        IData/*31:0*/ ysyx_22040000__DOT__mem_addr;
        IData/*31:0*/ ysyx_22040000__DOT__mem_wdata;
        IData/*31:0*/ ysyx_22040000__DOT__alu_a;
        IData/*31:0*/ ysyx_22040000__DOT__alu_b;
        IData/*31:0*/ ysyx_22040000__DOT__alu_y;
        IData/*31:0*/ ysyx_22040000__DOT__tmp_imm;
        IData/*31:0*/ ysyx_22040000__DOT__tmp_addr;
        IData/*31:0*/ ysyx_22040000__DOT__tmp_old_csr;
        IData/*31:0*/ ysyx_22040000__DOT__tmp_new_csr;
        IData/*31:0*/ ysyx_22040000__DOT__load_extract__Vstatic__shifted;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ ysyx_22040000__DOT__mtime;
        QData/*63:0*/ ysyx_22040000__DOT__cycle_count;
        QData/*63:0*/ ysyx_22040000__DOT__instret_count;
        QData/*63:0*/ ysyx_22040000__DOT__icache_accesses;
        QData/*63:0*/ ysyx_22040000__DOT__icache_misses;
        QData/*63:0*/ ysyx_22040000__DOT__icache_miss_cycles;
        VlUnpacked<IData/*31:0*/, 16> ysyx_22040000__DOT__regs;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_22040000__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_22040000___024root(Vysyx_22040000__Syms* symsp, const char* v__name);
    ~Vysyx_22040000___024root();
    VL_UNCOPYABLE(Vysyx_22040000___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
