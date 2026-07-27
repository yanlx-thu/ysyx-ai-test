// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22040000.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_22040000___024root.h"

void Vysyx_22040000___024root___eval_act(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vysyx_22040000___024root___nba_sequent__TOP__0(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__2__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__2__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__2__value;
    __Vtask_ysyx_22040000__DOT__write_reg__2__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__load_extract__3__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__load_extract__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__load_extract__3__word;
    __Vfunc_ysyx_22040000__DOT__load_extract__3__word = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__load_extract__3__addr;
    __Vfunc_ysyx_22040000__DOT__load_extract__3__addr = 0;
    CData/*1:0*/ __Vfunc_ysyx_22040000__DOT__load_extract__3__size;
    __Vfunc_ysyx_22040000__DOT__load_extract__3__size = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__load_extract__3__is_unsigned;
    __Vfunc_ysyx_22040000__DOT__load_extract__3__is_unsigned = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__4__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__sext__4__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__4__value;
    __Vfunc_ysyx_22040000__DOT__sext__4__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__5__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__sext__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__5__value;
    __Vfunc_ysyx_22040000__DOT__sext__5__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__6__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__reg_read__6__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__6__idx;
    __Vfunc_ysyx_22040000__DOT__reg_read__6__idx = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__7__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__reg_read__7__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__7__idx;
    __Vfunc_ysyx_22040000__DOT__reg_read__7__idx = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__11__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__reg_read__11__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__csr_implemented__14__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__csr_implemented__14__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr;
    __Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__csr_read__16__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__csr_read__16__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_ysyx_22040000__DOT__csr_read__16__csr;
    __Vfunc_ysyx_22040000__DOT__csr_read__16__csr = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__17__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__reg_read__17__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__17__idx;
    __Vfunc_ysyx_22040000__DOT__reg_read__17__idx = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__18__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__reg_read__18__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__18__idx;
    __Vfunc_ysyx_22040000__DOT__reg_read__18__idx = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__19__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__reg_read__19__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_ysyx_22040000__DOT__reg_read__19__idx;
    __Vfunc_ysyx_22040000__DOT__reg_read__19__idx = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__Vfuncout = 0;
    SData/*11:0*/ __Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__csr;
    __Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__csr = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__22__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__22__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__22__value;
    __Vtask_ysyx_22040000__DOT__write_reg__22__value = 0;
    SData/*11:0*/ __Vtask_ysyx_22040000__DOT__write_csr__23__csr;
    __Vtask_ysyx_22040000__DOT__write_csr__23__csr = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_csr__23__value;
    __Vtask_ysyx_22040000__DOT__write_csr__23__value = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__27__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__27__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__27__value;
    __Vtask_ysyx_22040000__DOT__write_reg__27__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__jal_imm__28__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__jal_imm__28__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__jal_imm__28__raw;
    __Vfunc_ysyx_22040000__DOT__jal_imm__28__raw = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__29__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__sext__29__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__29__value;
    __Vfunc_ysyx_22040000__DOT__sext__29__value = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__34__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__34__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__34__value;
    __Vtask_ysyx_22040000__DOT__write_reg__34__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__35__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__sext__35__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__35__value;
    __Vfunc_ysyx_22040000__DOT__sext__35__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__branch_imm__40__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__branch_imm__40__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__branch_imm__40__raw;
    __Vfunc_ysyx_22040000__DOT__branch_imm__40__raw = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__41__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__sext__41__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__41__value;
    __Vfunc_ysyx_22040000__DOT__sext__41__value = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__47__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__47__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__47__value;
    __Vtask_ysyx_22040000__DOT__write_reg__47__value = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__51__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__51__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__51__value;
    __Vtask_ysyx_22040000__DOT__write_reg__51__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__store_imm__57__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__store_imm__57__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__store_imm__57__raw;
    __Vfunc_ysyx_22040000__DOT__store_imm__57__raw = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__58__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__sext__58__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__58__value;
    __Vfunc_ysyx_22040000__DOT__sext__58__value = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__59__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_addr__59__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__59__addr;
    __Vfunc_ysyx_22040000__DOT__clint_addr__59__addr = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__61__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_addr__61__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__61__addr;
    __Vfunc_ysyx_22040000__DOT__clint_addr__61__addr = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__63__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_addr__63__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__63__addr;
    __Vfunc_ysyx_22040000__DOT__clint_addr__63__addr = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__69__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__69__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__69__value;
    __Vtask_ysyx_22040000__DOT__write_reg__69__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__73__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__sext__73__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__73__value;
    __Vfunc_ysyx_22040000__DOT__sext__73__value = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__75__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__75__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__75__value;
    __Vtask_ysyx_22040000__DOT__write_reg__75__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__84__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__sext__84__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__sext__84__value;
    __Vfunc_ysyx_22040000__DOT__sext__84__value = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__87__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_addr__87__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__87__addr;
    __Vfunc_ysyx_22040000__DOT__clint_addr__87__addr = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__88__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__88__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__88__value;
    __Vtask_ysyx_22040000__DOT__write_reg__88__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__89__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_read__89__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__89__addr;
    __Vfunc_ysyx_22040000__DOT__clint_read__89__addr = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__90__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_addr__90__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__90__addr;
    __Vfunc_ysyx_22040000__DOT__clint_addr__90__addr = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__91__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__91__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__91__value;
    __Vtask_ysyx_22040000__DOT__write_reg__91__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__92__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_read__92__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__92__addr;
    __Vfunc_ysyx_22040000__DOT__clint_read__92__addr = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__95__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_addr__95__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__95__addr;
    __Vfunc_ysyx_22040000__DOT__clint_addr__95__addr = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__96__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__96__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__96__value;
    __Vtask_ysyx_22040000__DOT__write_reg__96__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__97__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_read__97__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__97__addr;
    __Vfunc_ysyx_22040000__DOT__clint_read__97__addr = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__99__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_addr__99__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__99__addr;
    __Vfunc_ysyx_22040000__DOT__clint_addr__99__addr = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__100__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__100__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__100__value;
    __Vtask_ysyx_22040000__DOT__write_reg__100__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__101__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_read__101__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__101__addr;
    __Vfunc_ysyx_22040000__DOT__clint_read__101__addr = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__102__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_addr__102__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_addr__102__addr;
    __Vfunc_ysyx_22040000__DOT__clint_addr__102__addr = 0;
    CData/*4:0*/ __Vtask_ysyx_22040000__DOT__write_reg__103__idx;
    __Vtask_ysyx_22040000__DOT__write_reg__103__idx = 0;
    IData/*31:0*/ __Vtask_ysyx_22040000__DOT__write_reg__103__value;
    __Vtask_ysyx_22040000__DOT__write_reg__103__value = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__104__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__clint_read__104__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__clint_read__104__addr;
    __Vfunc_ysyx_22040000__DOT__clint_read__104__addr = 0;
    IData/*31:0*/ __Vfunc_ysyx_22040000__DOT__ic_word__109__Vfuncout;
    __Vfunc_ysyx_22040000__DOT__ic_word__109__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_ysyx_22040000__DOT__ic_word__109__index;
    __Vfunc_ysyx_22040000__DOT__ic_word__109__index = 0;
    CData/*1:0*/ __Vfunc_ysyx_22040000__DOT__ic_word__109__word;
    __Vfunc_ysyx_22040000__DOT__ic_word__109__word = 0;
    CData/*3:0*/ __Vdly__ysyx_22040000__DOT__state;
    __Vdly__ysyx_22040000__DOT__state = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__pc;
    __Vdly__ysyx_22040000__DOT__pc = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__inst;
    __Vdly__ysyx_22040000__DOT__inst = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__inst_pc;
    __Vdly__ysyx_22040000__DOT__inst_pc = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__csr_mtvec;
    __Vdly__ysyx_22040000__DOT__csr_mtvec = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__csr_mepc;
    __Vdly__ysyx_22040000__DOT__csr_mepc = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__csr_mcause;
    __Vdly__ysyx_22040000__DOT__csr_mcause = 0;
    QData/*63:0*/ __Vdly__ysyx_22040000__DOT__mtime;
    __Vdly__ysyx_22040000__DOT__mtime = 0;
    QData/*63:0*/ __Vdly__ysyx_22040000__DOT__instret_count;
    __Vdly__ysyx_22040000__DOT__instret_count = 0;
    QData/*63:0*/ __Vdly__ysyx_22040000__DOT__icache_accesses;
    __Vdly__ysyx_22040000__DOT__icache_accesses = 0;
    QData/*63:0*/ __Vdly__ysyx_22040000__DOT__icache_misses;
    __Vdly__ysyx_22040000__DOT__icache_misses = 0;
    QData/*63:0*/ __Vdly__ysyx_22040000__DOT__icache_miss_cycles;
    __Vdly__ysyx_22040000__DOT__icache_miss_cycles = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__ic0_word0;
    __Vdly__ysyx_22040000__DOT__ic0_word0 = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__ic0_word1;
    __Vdly__ysyx_22040000__DOT__ic0_word1 = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__ic0_word2;
    __Vdly__ysyx_22040000__DOT__ic0_word2 = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__ic0_word3;
    __Vdly__ysyx_22040000__DOT__ic0_word3 = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__ic1_word0;
    __Vdly__ysyx_22040000__DOT__ic1_word0 = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__ic1_word1;
    __Vdly__ysyx_22040000__DOT__ic1_word1 = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__ic1_word2;
    __Vdly__ysyx_22040000__DOT__ic1_word2 = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__ic1_word3;
    __Vdly__ysyx_22040000__DOT__ic1_word3 = 0;
    CData/*0:0*/ __Vdly__ysyx_22040000__DOT__miss_index;
    __Vdly__ysyx_22040000__DOT__miss_index = 0;
    IData/*26:0*/ __Vdly__ysyx_22040000__DOT__miss_tag;
    __Vdly__ysyx_22040000__DOT__miss_tag = 0;
    CData/*1:0*/ __Vdly__ysyx_22040000__DOT__miss_word;
    __Vdly__ysyx_22040000__DOT__miss_word = 0;
    CData/*1:0*/ __Vdly__ysyx_22040000__DOT__miss_target_word;
    __Vdly__ysyx_22040000__DOT__miss_target_word = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__miss_saved_inst;
    __Vdly__ysyx_22040000__DOT__miss_saved_inst = 0;
    IData/*31:0*/ __Vdly__ysyx_22040000__DOT__mem_addr;
    __Vdly__ysyx_22040000__DOT__mem_addr = 0;
    CData/*4:0*/ __Vdly__ysyx_22040000__DOT__mem_rd;
    __Vdly__ysyx_22040000__DOT__mem_rd = 0;
    CData/*1:0*/ __Vdly__ysyx_22040000__DOT__mem_size;
    __Vdly__ysyx_22040000__DOT__mem_size = 0;
    CData/*0:0*/ __Vdly__ysyx_22040000__DOT__mem_unsigned;
    __Vdly__ysyx_22040000__DOT__mem_unsigned = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v0;
    __Vdlyvset__ysyx_22040000__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v16;
    __Vdlyvset__ysyx_22040000__DOT__regs__v16 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v17;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v17 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v17;
    __Vdlyvval__ysyx_22040000__DOT__regs__v17 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v17;
    __Vdlyvset__ysyx_22040000__DOT__regs__v17 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v18;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v18 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v18;
    __Vdlyvval__ysyx_22040000__DOT__regs__v18 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v18;
    __Vdlyvset__ysyx_22040000__DOT__regs__v18 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v19;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v19 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v19;
    __Vdlyvval__ysyx_22040000__DOT__regs__v19 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v19;
    __Vdlyvset__ysyx_22040000__DOT__regs__v19 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v20;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v20 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v20;
    __Vdlyvval__ysyx_22040000__DOT__regs__v20 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v20;
    __Vdlyvset__ysyx_22040000__DOT__regs__v20 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v21;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v21 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v21;
    __Vdlyvval__ysyx_22040000__DOT__regs__v21 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v21;
    __Vdlyvset__ysyx_22040000__DOT__regs__v21 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v22;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v22 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v22;
    __Vdlyvval__ysyx_22040000__DOT__regs__v22 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v22;
    __Vdlyvset__ysyx_22040000__DOT__regs__v22 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v23;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v23 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v23;
    __Vdlyvval__ysyx_22040000__DOT__regs__v23 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v23;
    __Vdlyvset__ysyx_22040000__DOT__regs__v23 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v24;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v24 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v24;
    __Vdlyvval__ysyx_22040000__DOT__regs__v24 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v24;
    __Vdlyvset__ysyx_22040000__DOT__regs__v24 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v25;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v25 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v25;
    __Vdlyvval__ysyx_22040000__DOT__regs__v25 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v25;
    __Vdlyvset__ysyx_22040000__DOT__regs__v25 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v26;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v26 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v26;
    __Vdlyvval__ysyx_22040000__DOT__regs__v26 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v26;
    __Vdlyvset__ysyx_22040000__DOT__regs__v26 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v27;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v27 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v27;
    __Vdlyvval__ysyx_22040000__DOT__regs__v27 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v27;
    __Vdlyvset__ysyx_22040000__DOT__regs__v27 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v28;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v28 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v28;
    __Vdlyvval__ysyx_22040000__DOT__regs__v28 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v28;
    __Vdlyvset__ysyx_22040000__DOT__regs__v28 = 0;
    CData/*3:0*/ __Vdlyvdim0__ysyx_22040000__DOT__regs__v29;
    __Vdlyvdim0__ysyx_22040000__DOT__regs__v29 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_22040000__DOT__regs__v29;
    __Vdlyvval__ysyx_22040000__DOT__regs__v29 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_22040000__DOT__regs__v29;
    __Vdlyvset__ysyx_22040000__DOT__regs__v29 = 0;
    // Body
    __Vdly__ysyx_22040000__DOT__mem_unsigned = vlSelf->ysyx_22040000__DOT__mem_unsigned;
    __Vdly__ysyx_22040000__DOT__mem_size = vlSelf->ysyx_22040000__DOT__mem_size;
    __Vdly__ysyx_22040000__DOT__mem_rd = vlSelf->ysyx_22040000__DOT__mem_rd;
    __Vdly__ysyx_22040000__DOT__miss_saved_inst = vlSelf->ysyx_22040000__DOT__miss_saved_inst;
    __Vdly__ysyx_22040000__DOT__miss_target_word = vlSelf->ysyx_22040000__DOT__miss_target_word;
    __Vdly__ysyx_22040000__DOT__miss_word = vlSelf->ysyx_22040000__DOT__miss_word;
    __Vdly__ysyx_22040000__DOT__miss_tag = vlSelf->ysyx_22040000__DOT__miss_tag;
    __Vdly__ysyx_22040000__DOT__miss_index = vlSelf->ysyx_22040000__DOT__miss_index;
    __Vdly__ysyx_22040000__DOT__ic1_word3 = vlSelf->ysyx_22040000__DOT__ic1_word3;
    __Vdly__ysyx_22040000__DOT__ic1_word2 = vlSelf->ysyx_22040000__DOT__ic1_word2;
    __Vdly__ysyx_22040000__DOT__ic1_word1 = vlSelf->ysyx_22040000__DOT__ic1_word1;
    __Vdly__ysyx_22040000__DOT__ic1_word0 = vlSelf->ysyx_22040000__DOT__ic1_word0;
    __Vdly__ysyx_22040000__DOT__ic0_word3 = vlSelf->ysyx_22040000__DOT__ic0_word3;
    __Vdly__ysyx_22040000__DOT__ic0_word2 = vlSelf->ysyx_22040000__DOT__ic0_word2;
    __Vdly__ysyx_22040000__DOT__ic0_word1 = vlSelf->ysyx_22040000__DOT__ic0_word1;
    __Vdly__ysyx_22040000__DOT__ic0_word0 = vlSelf->ysyx_22040000__DOT__ic0_word0;
    __Vdly__ysyx_22040000__DOT__icache_miss_cycles 
        = vlSelf->ysyx_22040000__DOT__icache_miss_cycles;
    __Vdly__ysyx_22040000__DOT__icache_misses = vlSelf->ysyx_22040000__DOT__icache_misses;
    __Vdly__ysyx_22040000__DOT__icache_accesses = vlSelf->ysyx_22040000__DOT__icache_accesses;
    __Vdly__ysyx_22040000__DOT__instret_count = vlSelf->ysyx_22040000__DOT__instret_count;
    __Vdly__ysyx_22040000__DOT__mtime = vlSelf->ysyx_22040000__DOT__mtime;
    __Vdly__ysyx_22040000__DOT__csr_mcause = vlSelf->ysyx_22040000__DOT__csr_mcause;
    __Vdly__ysyx_22040000__DOT__csr_mepc = vlSelf->ysyx_22040000__DOT__csr_mepc;
    __Vdly__ysyx_22040000__DOT__csr_mtvec = vlSelf->ysyx_22040000__DOT__csr_mtvec;
    __Vdly__ysyx_22040000__DOT__inst_pc = vlSelf->ysyx_22040000__DOT__inst_pc;
    __Vdly__ysyx_22040000__DOT__pc = vlSelf->ysyx_22040000__DOT__pc;
    __Vdly__ysyx_22040000__DOT__mem_addr = vlSelf->ysyx_22040000__DOT__mem_addr;
    __Vdly__ysyx_22040000__DOT__inst = vlSelf->ysyx_22040000__DOT__inst;
    __Vdly__ysyx_22040000__DOT__state = vlSelf->ysyx_22040000__DOT__state;
    __Vdlyvset__ysyx_22040000__DOT__regs__v0 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v16 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v17 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v18 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v19 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v20 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v21 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v22 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v23 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v24 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v25 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v26 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v27 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v28 = 0U;
    __Vdlyvset__ysyx_22040000__DOT__regs__v29 = 0U;
    if (vlSelf->reset) {
        vlSelf->ysyx_22040000__DOT__cycle_count = 0ULL;
        __Vdly__ysyx_22040000__DOT__state = 0U;
        __Vdly__ysyx_22040000__DOT__pc = 0x80000000U;
        __Vdly__ysyx_22040000__DOT__inst = 0U;
        __Vdly__ysyx_22040000__DOT__inst_pc = 0x80000000U;
        __Vdly__ysyx_22040000__DOT__csr_mtvec = 0U;
        __Vdly__ysyx_22040000__DOT__csr_mepc = 0U;
        __Vdly__ysyx_22040000__DOT__csr_mcause = 0U;
        __Vdly__ysyx_22040000__DOT__mtime = 0ULL;
        vlSelf->ysyx_22040000__DOT__debug_halt = 0U;
        vlSelf->ysyx_22040000__DOT__debug_halt_code = 0U;
        __Vdly__ysyx_22040000__DOT__instret_count = 0ULL;
        __Vdly__ysyx_22040000__DOT__icache_accesses = 0ULL;
        __Vdly__ysyx_22040000__DOT__icache_misses = 0ULL;
        __Vdly__ysyx_22040000__DOT__icache_miss_cycles = 0ULL;
        vlSelf->ysyx_22040000__DOT__ic_valid = 0U;
        vlSelf->ysyx_22040000__DOT__ic_tag0 = 0U;
        vlSelf->ysyx_22040000__DOT__ic_tag1 = 0U;
        __Vdly__ysyx_22040000__DOT__ic0_word0 = 0U;
        __Vdly__ysyx_22040000__DOT__ic0_word1 = 0U;
        __Vdly__ysyx_22040000__DOT__ic0_word2 = 0U;
        __Vdly__ysyx_22040000__DOT__ic0_word3 = 0U;
        __Vdly__ysyx_22040000__DOT__ic1_word0 = 0U;
        __Vdly__ysyx_22040000__DOT__ic1_word1 = 0U;
        __Vdly__ysyx_22040000__DOT__ic1_word2 = 0U;
        __Vdly__ysyx_22040000__DOT__ic1_word3 = 0U;
        vlSelf->ysyx_22040000__DOT__miss_addr = 0U;
        __Vdly__ysyx_22040000__DOT__miss_index = 0U;
        __Vdly__ysyx_22040000__DOT__miss_tag = 0U;
        __Vdly__ysyx_22040000__DOT__miss_word = 0U;
        __Vdly__ysyx_22040000__DOT__miss_target_word = 0U;
        __Vdly__ysyx_22040000__DOT__miss_saved_inst = 0U;
        __Vdly__ysyx_22040000__DOT__mem_addr = 0U;
        vlSelf->ysyx_22040000__DOT__mem_wdata = 0U;
        vlSelf->ysyx_22040000__DOT__mem_wstrb = 0U;
        __Vdly__ysyx_22040000__DOT__mem_rd = 0U;
        __Vdly__ysyx_22040000__DOT__mem_size = 0U;
        __Vdly__ysyx_22040000__DOT__mem_unsigned = 0U;
        __Vdlyvset__ysyx_22040000__DOT__regs__v0 = 1U;
    } else {
        vlSelf->ysyx_22040000__DOT__cycle_count = (1ULL 
                                                   + vlSelf->ysyx_22040000__DOT__cycle_count);
        __Vdly__ysyx_22040000__DOT__mtime = (1ULL + vlSelf->ysyx_22040000__DOT__mtime);
        __Vdlyvset__ysyx_22040000__DOT__regs__v16 = 1U;
        if ((8U & (IData)(vlSelf->ysyx_22040000__DOT__state))) {
            __Vdly__ysyx_22040000__DOT__state = ((4U 
                                                  & (IData)(vlSelf->ysyx_22040000__DOT__state))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->ysyx_22040000__DOT__state))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->ysyx_22040000__DOT__state))
                                                    ? 0U
                                                    : 8U)));
        } else if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__state))) {
            if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__state))) {
                if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__state))) {
                    if (vlSelf->io_master_bvalid) {
                        if ((0U != (IData)(vlSelf->io_master_bresp))) {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 7U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        } else {
                            __Vdly__ysyx_22040000__DOT__pc 
                                = ((IData)(4U) + vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        }
                    }
                } else if (((IData)(vlSelf->io_master_awready) 
                            & (IData)(vlSelf->io_master_wready))) {
                    __Vdly__ysyx_22040000__DOT__state = 7U;
                }
            } else if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__state))) {
                if (vlSelf->io_master_rvalid) {
                    if ((0U != (IData)(vlSelf->io_master_rresp))) {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 5U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    } else {
                        __Vfunc_ysyx_22040000__DOT__load_extract__3__is_unsigned 
                            = vlSelf->ysyx_22040000__DOT__mem_unsigned;
                        __Vfunc_ysyx_22040000__DOT__load_extract__3__size 
                            = vlSelf->ysyx_22040000__DOT__mem_size;
                        __Vfunc_ysyx_22040000__DOT__load_extract__3__addr 
                            = vlSelf->ysyx_22040000__DOT__mem_addr;
                        __Vdly__ysyx_22040000__DOT__pc 
                            = ((IData)(4U) + vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                        __Vfunc_ysyx_22040000__DOT__load_extract__3__word 
                            = vlSelf->io_master_rdata;
                        vlSelf->ysyx_22040000__DOT__load_extract__Vstatic__shifted 
                            = (__Vfunc_ysyx_22040000__DOT__load_extract__3__word 
                               >> (0x18U & (__Vfunc_ysyx_22040000__DOT__load_extract__3__addr 
                                            << 3U)));
                        if ((0U == (IData)(__Vfunc_ysyx_22040000__DOT__load_extract__3__size))) {
                            __Vfunc_ysyx_22040000__DOT__sext__4__value 
                                = (0xffU & vlSelf->ysyx_22040000__DOT__load_extract__Vstatic__shifted);
                            __Vfunc_ysyx_22040000__DOT__sext__4__Vfuncout 
                                = ((0x80U ^ __Vfunc_ysyx_22040000__DOT__sext__4__value) 
                                   - (IData)(0x80U));
                            __Vfunc_ysyx_22040000__DOT__load_extract__3__Vfuncout 
                                = ((IData)(__Vfunc_ysyx_22040000__DOT__load_extract__3__is_unsigned)
                                    ? (0xffU & vlSelf->ysyx_22040000__DOT__load_extract__Vstatic__shifted)
                                    : __Vfunc_ysyx_22040000__DOT__sext__4__Vfuncout);
                        } else if ((1U == (IData)(__Vfunc_ysyx_22040000__DOT__load_extract__3__size))) {
                            __Vfunc_ysyx_22040000__DOT__sext__5__value 
                                = (0xffffU & vlSelf->ysyx_22040000__DOT__load_extract__Vstatic__shifted);
                            __Vfunc_ysyx_22040000__DOT__sext__5__Vfuncout 
                                = ((0x8000U ^ __Vfunc_ysyx_22040000__DOT__sext__5__value) 
                                   - (IData)(0x8000U));
                            __Vfunc_ysyx_22040000__DOT__load_extract__3__Vfuncout 
                                = ((IData)(__Vfunc_ysyx_22040000__DOT__load_extract__3__is_unsigned)
                                    ? (0xffffU & vlSelf->ysyx_22040000__DOT__load_extract__Vstatic__shifted)
                                    : __Vfunc_ysyx_22040000__DOT__sext__5__Vfuncout);
                        } else {
                            __Vfunc_ysyx_22040000__DOT__load_extract__3__Vfuncout 
                                = __Vfunc_ysyx_22040000__DOT__load_extract__3__word;
                        }
                        __Vtask_ysyx_22040000__DOT__write_reg__2__value 
                            = __Vfunc_ysyx_22040000__DOT__load_extract__3__Vfuncout;
                        __Vtask_ysyx_22040000__DOT__write_reg__2__idx 
                            = vlSelf->ysyx_22040000__DOT__mem_rd;
                        if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__2__idx)) 
                             & (0x10U > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__2__idx)))) {
                            __Vdlyvval__ysyx_22040000__DOT__regs__v17 
                                = __Vtask_ysyx_22040000__DOT__write_reg__2__value;
                            __Vdlyvset__ysyx_22040000__DOT__regs__v17 = 1U;
                            __Vdlyvdim0__ysyx_22040000__DOT__regs__v17 
                                = (0xfU & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__2__idx));
                        }
                    }
                }
            } else if (vlSelf->io_master_arready) {
                __Vdly__ysyx_22040000__DOT__state = 5U;
            }
        } else if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__state))) {
            if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__state))) {
                __Vdly__ysyx_22040000__DOT__instret_count 
                    = (1ULL + vlSelf->ysyx_22040000__DOT__instret_count);
                vlSelf->ysyx_22040000__DOT__tmp_take_branch = 0U;
                vlSelf->ysyx_22040000__DOT__tmp_imm = 0U;
                vlSelf->ysyx_22040000__DOT__tmp_addr = 0U;
                vlSelf->ysyx_22040000__DOT__tmp_old_csr = 0U;
                vlSelf->ysyx_22040000__DOT__tmp_new_csr = 0U;
                vlSelf->ysyx_22040000__DOT__tmp_do_write = 0U;
                __Vfunc_ysyx_22040000__DOT__reg_read__6__idx 
                    = vlSelf->ysyx_22040000__DOT__rs1;
                __Vfunc_ysyx_22040000__DOT__reg_read__6__Vfuncout 
                    = ((0U == (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__6__idx))
                        ? 0U : ((0x10U > (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__6__idx))
                                 ? vlSelf->ysyx_22040000__DOT__regs
                                [(0xfU & (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__6__idx))]
                                 : 0U));
                vlSelf->ysyx_22040000__DOT__alu_a = __Vfunc_ysyx_22040000__DOT__reg_read__6__Vfuncout;
                __Vfunc_ysyx_22040000__DOT__reg_read__7__idx 
                    = vlSelf->ysyx_22040000__DOT__rs2;
                __Vfunc_ysyx_22040000__DOT__reg_read__7__Vfuncout 
                    = ((0U == (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__7__idx))
                        ? 0U : ((0x10U > (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__7__idx))
                                 ? vlSelf->ysyx_22040000__DOT__regs
                                [(0xfU & (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__7__idx))]
                                 : 0U));
                vlSelf->ysyx_22040000__DOT__alu_b = __Vfunc_ysyx_22040000__DOT__reg_read__7__Vfuncout;
                vlSelf->ysyx_22040000__DOT__alu_y = 0U;
                if ((0x40U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                    if ((0x20U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        if ((0x10U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if ((8U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            } else if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            } else if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                    if ((0U == (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                        if ((0U == 
                                             (vlSelf->ysyx_22040000__DOT__inst 
                                              >> 0x14U))) {
                                            __Vdly__ysyx_22040000__DOT__csr_mcause = 0xbU;
                                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                                = (0xfffffffcU 
                                                   & vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                        } else if (
                                                   (1U 
                                                    == 
                                                    (vlSelf->ysyx_22040000__DOT__inst 
                                                     >> 0x14U))) {
                                            __Vfunc_ysyx_22040000__DOT__reg_read__11__Vfuncout 
                                                = vlSelf->ysyx_22040000__DOT__regs
                                                [0xaU];
                                            vlSelf->ysyx_22040000__DOT__debug_halt = 1U;
                                            vlSelf->ysyx_22040000__DOT__debug_halt_code 
                                                = __Vfunc_ysyx_22040000__DOT__reg_read__11__Vfuncout;
                                            __Vdly__ysyx_22040000__DOT__csr_mcause = 3U;
                                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                                = (0xfffffffcU 
                                                   & vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                        } else if (
                                                   (0x302U 
                                                    == 
                                                    (vlSelf->ysyx_22040000__DOT__inst 
                                                     >> 0x14U))) {
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = vlSelf->ysyx_22040000__DOT__csr_mepc;
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                        } else {
                                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                                = (0xfffffffcU 
                                                   & vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                        }
                                    } else {
                                        __Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr 
                                            = vlSelf->ysyx_22040000__DOT__csr_id;
                                        __Vfunc_ysyx_22040000__DOT__csr_implemented__14__Vfuncout 
                                            = (((((
                                                   (0xf11U 
                                                    == (IData)(__Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr)) 
                                                   | (0xf12U 
                                                      == (IData)(__Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr))) 
                                                  | (0x300U 
                                                     == (IData)(__Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr))) 
                                                 | (0x305U 
                                                    == (IData)(__Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr))) 
                                                | (0x341U 
                                                   == (IData)(__Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr))) 
                                               | (0x342U 
                                                  == (IData)(__Vfunc_ysyx_22040000__DOT__csr_implemented__14__csr)));
                                        if ((1U & (
                                                   ((0x10U 
                                                     <= (IData)(vlSelf->ysyx_22040000__DOT__rd)) 
                                                    | ((((1U 
                                                          == (IData)(vlSelf->ysyx_22040000__DOT__funct3)) 
                                                         | (2U 
                                                            == (IData)(vlSelf->ysyx_22040000__DOT__funct3))) 
                                                        | (3U 
                                                           == (IData)(vlSelf->ysyx_22040000__DOT__funct3))) 
                                                       & (0x10U 
                                                          <= (IData)(vlSelf->ysyx_22040000__DOT__rs1)))) 
                                                   | (~ (IData)(__Vfunc_ysyx_22040000__DOT__csr_implemented__14__Vfuncout))))) {
                                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                                = (0xfffffffcU 
                                                   & vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                        } else {
                                            __Vfunc_ysyx_22040000__DOT__csr_read__16__csr 
                                                = vlSelf->ysyx_22040000__DOT__csr_id;
                                            __Vfunc_ysyx_22040000__DOT__csr_read__16__Vfuncout 
                                                = (
                                                   (0xf11U 
                                                    == (IData)(__Vfunc_ysyx_22040000__DOT__csr_read__16__csr))
                                                    ? 0U
                                                    : 
                                                   ((0xf12U 
                                                     == (IData)(__Vfunc_ysyx_22040000__DOT__csr_read__16__csr))
                                                     ? 0U
                                                     : 
                                                    ((0x300U 
                                                      == (IData)(__Vfunc_ysyx_22040000__DOT__csr_read__16__csr))
                                                      ? 0x1800U
                                                      : 
                                                     ((0x305U 
                                                       == (IData)(__Vfunc_ysyx_22040000__DOT__csr_read__16__csr))
                                                       ? vlSelf->ysyx_22040000__DOT__csr_mtvec
                                                       : 
                                                      ((0x341U 
                                                        == (IData)(__Vfunc_ysyx_22040000__DOT__csr_read__16__csr))
                                                        ? vlSelf->ysyx_22040000__DOT__csr_mepc
                                                        : 
                                                       ((0x342U 
                                                         == (IData)(__Vfunc_ysyx_22040000__DOT__csr_read__16__csr))
                                                         ? vlSelf->ysyx_22040000__DOT__csr_mcause
                                                         : 0U))))));
                                            vlSelf->ysyx_22040000__DOT__tmp_old_csr 
                                                = __Vfunc_ysyx_22040000__DOT__csr_read__16__Vfuncout;
                                            vlSelf->ysyx_22040000__DOT__tmp_do_write = 1U;
                                            if ((4U 
                                                 & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                                    if (
                                                        (1U 
                                                         & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                                        vlSelf->ysyx_22040000__DOT__tmp_new_csr 
                                                            = 
                                                            (vlSelf->ysyx_22040000__DOT__tmp_old_csr 
                                                             & (~ (IData)(vlSelf->ysyx_22040000__DOT__rs1)));
                                                        vlSelf->ysyx_22040000__DOT__tmp_do_write 
                                                            = 
                                                            (0U 
                                                             != (IData)(vlSelf->ysyx_22040000__DOT__rs1));
                                                    } else {
                                                        vlSelf->ysyx_22040000__DOT__tmp_new_csr 
                                                            = 
                                                            (vlSelf->ysyx_22040000__DOT__tmp_old_csr 
                                                             | (IData)(vlSelf->ysyx_22040000__DOT__rs1));
                                                        vlSelf->ysyx_22040000__DOT__tmp_do_write 
                                                            = 
                                                            (0U 
                                                             != (IData)(vlSelf->ysyx_22040000__DOT__rs1));
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                                    vlSelf->ysyx_22040000__DOT__tmp_new_csr 
                                                        = vlSelf->ysyx_22040000__DOT__rs1;
                                                } else {
                                                    vlSelf->ysyx_22040000__DOT__tmp_new_csr = 0U;
                                                    vlSelf->ysyx_22040000__DOT__tmp_do_write = 0U;
                                                }
                                            } else if (
                                                       (2U 
                                                        & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                                if (
                                                    (1U 
                                                     & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                                    __Vfunc_ysyx_22040000__DOT__reg_read__17__idx 
                                                        = vlSelf->ysyx_22040000__DOT__rs1;
                                                    __Vfunc_ysyx_22040000__DOT__reg_read__17__Vfuncout 
                                                        = 
                                                        ((0U 
                                                          == (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__17__idx))
                                                          ? 0U
                                                          : 
                                                         ((0x10U 
                                                           > (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__17__idx))
                                                           ? 
                                                          vlSelf->ysyx_22040000__DOT__regs
                                                          [
                                                          (0xfU 
                                                           & (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__17__idx))]
                                                           : 0U));
                                                    vlSelf->ysyx_22040000__DOT__tmp_do_write 
                                                        = 
                                                        (0U 
                                                         != (IData)(vlSelf->ysyx_22040000__DOT__rs1));
                                                    vlSelf->ysyx_22040000__DOT__tmp_new_csr 
                                                        = 
                                                        (vlSelf->ysyx_22040000__DOT__tmp_old_csr 
                                                         & (~ __Vfunc_ysyx_22040000__DOT__reg_read__17__Vfuncout));
                                                } else {
                                                    __Vfunc_ysyx_22040000__DOT__reg_read__18__idx 
                                                        = vlSelf->ysyx_22040000__DOT__rs1;
                                                    __Vfunc_ysyx_22040000__DOT__reg_read__18__Vfuncout 
                                                        = 
                                                        ((0U 
                                                          == (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__18__idx))
                                                          ? 0U
                                                          : 
                                                         ((0x10U 
                                                           > (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__18__idx))
                                                           ? 
                                                          vlSelf->ysyx_22040000__DOT__regs
                                                          [
                                                          (0xfU 
                                                           & (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__18__idx))]
                                                           : 0U));
                                                    vlSelf->ysyx_22040000__DOT__tmp_do_write 
                                                        = 
                                                        (0U 
                                                         != (IData)(vlSelf->ysyx_22040000__DOT__rs1));
                                                    vlSelf->ysyx_22040000__DOT__tmp_new_csr 
                                                        = 
                                                        (vlSelf->ysyx_22040000__DOT__tmp_old_csr 
                                                         | __Vfunc_ysyx_22040000__DOT__reg_read__18__Vfuncout);
                                                }
                                            } else if (
                                                       (1U 
                                                        & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                                __Vfunc_ysyx_22040000__DOT__reg_read__19__idx 
                                                    = vlSelf->ysyx_22040000__DOT__rs1;
                                                __Vfunc_ysyx_22040000__DOT__reg_read__19__Vfuncout 
                                                    = 
                                                    ((0U 
                                                      == (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__19__idx))
                                                      ? 0U
                                                      : 
                                                     ((0x10U 
                                                       > (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__19__idx))
                                                       ? 
                                                      vlSelf->ysyx_22040000__DOT__regs
                                                      [
                                                      (0xfU 
                                                       & (IData)(__Vfunc_ysyx_22040000__DOT__reg_read__19__idx))]
                                                       : 0U));
                                                vlSelf->ysyx_22040000__DOT__tmp_new_csr 
                                                    = __Vfunc_ysyx_22040000__DOT__reg_read__19__Vfuncout;
                                            } else {
                                                vlSelf->ysyx_22040000__DOT__tmp_new_csr = 0U;
                                                vlSelf->ysyx_22040000__DOT__tmp_do_write = 0U;
                                            }
                                            __Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__csr 
                                                = vlSelf->ysyx_22040000__DOT__csr_id;
                                            __Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__Vfuncout 
                                                = (
                                                   (((0x300U 
                                                      == (IData)(__Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__csr)) 
                                                     | (0x305U 
                                                        == (IData)(__Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__csr))) 
                                                    | (0x341U 
                                                       == (IData)(__Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__csr))) 
                                                   | (0x342U 
                                                      == (IData)(__Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__csr)));
                                            if (((0U 
                                                  == (IData)(vlSelf->ysyx_22040000__DOT__funct3)) 
                                                 | ((IData)(vlSelf->ysyx_22040000__DOT__tmp_do_write) 
                                                    & (~ (IData)(__Vfunc_ysyx_22040000__DOT__csr_write_allowed__20__Vfuncout))))) {
                                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                                    = 
                                                    (0xfffffffcU 
                                                     & vlSelf->ysyx_22040000__DOT__inst_pc);
                                                __Vdly__ysyx_22040000__DOT__pc 
                                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                                __Vdly__ysyx_22040000__DOT__state = 0U;
                                            } else {
                                                __Vtask_ysyx_22040000__DOT__write_reg__22__value 
                                                    = vlSelf->ysyx_22040000__DOT__tmp_old_csr;
                                                __Vtask_ysyx_22040000__DOT__write_reg__22__idx 
                                                    = vlSelf->ysyx_22040000__DOT__rd;
                                                if (
                                                    ((0U 
                                                      != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__22__idx)) 
                                                     & (0x10U 
                                                        > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__22__idx)))) {
                                                    __Vdlyvval__ysyx_22040000__DOT__regs__v18 
                                                        = __Vtask_ysyx_22040000__DOT__write_reg__22__value;
                                                    __Vdlyvset__ysyx_22040000__DOT__regs__v18 = 1U;
                                                    __Vdlyvdim0__ysyx_22040000__DOT__regs__v18 
                                                        = 
                                                        (0xfU 
                                                         & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__22__idx));
                                                }
                                                if (vlSelf->ysyx_22040000__DOT__tmp_do_write) {
                                                    __Vtask_ysyx_22040000__DOT__write_csr__23__value 
                                                        = vlSelf->ysyx_22040000__DOT__tmp_new_csr;
                                                    __Vtask_ysyx_22040000__DOT__write_csr__23__csr 
                                                        = vlSelf->ysyx_22040000__DOT__csr_id;
                                                    if (
                                                        (0x300U 
                                                         != (IData)(__Vtask_ysyx_22040000__DOT__write_csr__23__csr))) {
                                                        if (
                                                            (0x305U 
                                                             == (IData)(__Vtask_ysyx_22040000__DOT__write_csr__23__csr))) {
                                                            __Vdly__ysyx_22040000__DOT__csr_mtvec 
                                                                = 
                                                                (0xfffffffcU 
                                                                 & __Vtask_ysyx_22040000__DOT__write_csr__23__value);
                                                        } else if (
                                                                   (0x341U 
                                                                    == (IData)(__Vtask_ysyx_22040000__DOT__write_csr__23__csr))) {
                                                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                                                = 
                                                                (0xfffffffcU 
                                                                 & __Vtask_ysyx_22040000__DOT__write_csr__23__value);
                                                        } else if (
                                                                   (0x342U 
                                                                    == (IData)(__Vtask_ysyx_22040000__DOT__write_csr__23__csr))) {
                                                            __Vdly__ysyx_22040000__DOT__csr_mcause 
                                                                = __Vtask_ysyx_22040000__DOT__write_csr__23__value;
                                                        }
                                                    }
                                                }
                                                __Vdly__ysyx_22040000__DOT__pc 
                                                    = 
                                                    ((IData)(4U) 
                                                     + vlSelf->ysyx_22040000__DOT__inst_pc);
                                                __Vdly__ysyx_22040000__DOT__state = 0U;
                                            }
                                        }
                                    }
                                } else {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                }
                            } else {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            }
                        } else if ((8U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                    if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                        if ((0x10U 
                                             <= (IData)(vlSelf->ysyx_22040000__DOT__rd))) {
                                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                                = (0xfffffffcU 
                                                   & vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                        } else {
                                            __Vtask_ysyx_22040000__DOT__write_reg__27__value 
                                                = ((IData)(4U) 
                                                   + vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vtask_ysyx_22040000__DOT__write_reg__27__idx 
                                                = vlSelf->ysyx_22040000__DOT__rd;
                                            if (((0U 
                                                  != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__27__idx)) 
                                                 & (0x10U 
                                                    > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__27__idx)))) {
                                                __Vdlyvval__ysyx_22040000__DOT__regs__v19 
                                                    = __Vtask_ysyx_22040000__DOT__write_reg__27__value;
                                                __Vdlyvset__ysyx_22040000__DOT__regs__v19 = 1U;
                                                __Vdlyvdim0__ysyx_22040000__DOT__regs__v19 
                                                    = 
                                                    (0xfU 
                                                     & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__27__idx));
                                            }
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                            __Vfunc_ysyx_22040000__DOT__jal_imm__28__raw 
                                                = vlSelf->ysyx_22040000__DOT__inst;
                                            __Vfunc_ysyx_22040000__DOT__sext__29__value 
                                                = (
                                                   (0x100000U 
                                                    & (__Vfunc_ysyx_22040000__DOT__jal_imm__28__raw 
                                                       >> 0xbU)) 
                                                   | ((0xff000U 
                                                       & __Vfunc_ysyx_22040000__DOT__jal_imm__28__raw) 
                                                      | ((0x800U 
                                                          & (__Vfunc_ysyx_22040000__DOT__jal_imm__28__raw 
                                                             >> 9U)) 
                                                         | (0x7feU 
                                                            & (__Vfunc_ysyx_22040000__DOT__jal_imm__28__raw 
                                                               >> 0x14U)))));
                                            __Vfunc_ysyx_22040000__DOT__sext__29__Vfuncout 
                                                = (
                                                   (0x100000U 
                                                    ^ __Vfunc_ysyx_22040000__DOT__sext__29__value) 
                                                   - (IData)(0x100000U));
                                            __Vfunc_ysyx_22040000__DOT__jal_imm__28__Vfuncout 
                                                = __Vfunc_ysyx_22040000__DOT__sext__29__Vfuncout;
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = (vlSelf->ysyx_22040000__DOT__inst_pc 
                                                   + __Vfunc_ysyx_22040000__DOT__jal_imm__28__Vfuncout);
                                        }
                                    } else {
                                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                                            = (0xfffffffcU 
                                               & vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    }
                                } else {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                }
                            } else {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            }
                        } else if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                    if ((((0U != (IData)(vlSelf->ysyx_22040000__DOT__funct3)) 
                                          | (0x10U 
                                             <= (IData)(vlSelf->ysyx_22040000__DOT__rd))) 
                                         | (0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs1)))) {
                                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                                            = (0xfffffffcU 
                                               & vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    } else {
                                        __Vtask_ysyx_22040000__DOT__write_reg__34__value 
                                            = ((IData)(4U) 
                                               + vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vfunc_ysyx_22040000__DOT__sext__35__value 
                                            = (vlSelf->ysyx_22040000__DOT__inst 
                                               >> 0x14U);
                                        __Vtask_ysyx_22040000__DOT__write_reg__34__idx 
                                            = vlSelf->ysyx_22040000__DOT__rd;
                                        __Vfunc_ysyx_22040000__DOT__sext__35__Vfuncout 
                                            = ((0x800U 
                                                ^ __Vfunc_ysyx_22040000__DOT__sext__35__value) 
                                               - (IData)(0x800U));
                                        if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__34__idx)) 
                                             & (0x10U 
                                                > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__34__idx)))) {
                                            __Vdlyvval__ysyx_22040000__DOT__regs__v20 
                                                = __Vtask_ysyx_22040000__DOT__write_reg__34__value;
                                            __Vdlyvset__ysyx_22040000__DOT__regs__v20 = 1U;
                                            __Vdlyvdim0__ysyx_22040000__DOT__regs__v20 
                                                = (0xfU 
                                                   & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__34__idx));
                                        }
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = (0xfffffffeU 
                                               & (vlSelf->ysyx_22040000__DOT__alu_a 
                                                  + __Vfunc_ysyx_22040000__DOT__sext__35__Vfuncout));
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    }
                                } else {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                }
                            } else {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            }
                        } else if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                if (((0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs1)) 
                                     | (0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs2)))) {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                } else {
                                    vlSelf->ysyx_22040000__DOT__tmp_take_branch 
                                        = ((4U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                            ? ((2U 
                                                & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                                    ? 
                                                   (vlSelf->ysyx_22040000__DOT__alu_a 
                                                    >= vlSelf->ysyx_22040000__DOT__alu_b)
                                                    : 
                                                   (vlSelf->ysyx_22040000__DOT__alu_a 
                                                    < vlSelf->ysyx_22040000__DOT__alu_b))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                                    ? 
                                                   VL_GTES_III(32, vlSelf->ysyx_22040000__DOT__alu_a, vlSelf->ysyx_22040000__DOT__alu_b)
                                                    : 
                                                   VL_LTS_III(32, vlSelf->ysyx_22040000__DOT__alu_a, vlSelf->ysyx_22040000__DOT__alu_b)))
                                            : ((~ ((IData)(vlSelf->ysyx_22040000__DOT__funct3) 
                                                   >> 1U)) 
                                               & ((1U 
                                                   & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                                   ? 
                                                  (vlSelf->ysyx_22040000__DOT__alu_a 
                                                   != vlSelf->ysyx_22040000__DOT__alu_b)
                                                   : 
                                                  (vlSelf->ysyx_22040000__DOT__alu_a 
                                                   == vlSelf->ysyx_22040000__DOT__alu_b))));
                                    if (((2U == (IData)(vlSelf->ysyx_22040000__DOT__funct3)) 
                                         | (3U == (IData)(vlSelf->ysyx_22040000__DOT__funct3)))) {
                                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                                            = (0xfffffffcU 
                                               & vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    } else {
                                        __Vfunc_ysyx_22040000__DOT__branch_imm__40__raw 
                                            = vlSelf->ysyx_22040000__DOT__inst;
                                        __Vfunc_ysyx_22040000__DOT__sext__41__value 
                                            = ((0x1000U 
                                                & (__Vfunc_ysyx_22040000__DOT__branch_imm__40__raw 
                                                   >> 0x13U)) 
                                               | ((0x800U 
                                                   & (__Vfunc_ysyx_22040000__DOT__branch_imm__40__raw 
                                                      << 4U)) 
                                                  | ((0x7e0U 
                                                      & (__Vfunc_ysyx_22040000__DOT__branch_imm__40__raw 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (__Vfunc_ysyx_22040000__DOT__branch_imm__40__raw 
                                                           >> 7U)))));
                                        __Vfunc_ysyx_22040000__DOT__sext__41__Vfuncout 
                                            = ((0x1000U 
                                                ^ __Vfunc_ysyx_22040000__DOT__sext__41__value) 
                                               - (IData)(0x1000U));
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                        __Vfunc_ysyx_22040000__DOT__branch_imm__40__Vfuncout 
                                            = __Vfunc_ysyx_22040000__DOT__sext__41__Vfuncout;
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = ((IData)(vlSelf->ysyx_22040000__DOT__tmp_take_branch)
                                                ? (vlSelf->ysyx_22040000__DOT__inst_pc 
                                                   + __Vfunc_ysyx_22040000__DOT__branch_imm__40__Vfuncout)
                                                : ((IData)(4U) 
                                                   + vlSelf->ysyx_22040000__DOT__inst_pc));
                                    }
                                }
                            } else {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            }
                        } else {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        }
                    } else {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    }
                } else if ((0x20U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                    if ((0x10U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        if ((8U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        } else if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                    if ((0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rd))) {
                                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                                            = (0xfffffffcU 
                                               & vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    } else {
                                        __Vtask_ysyx_22040000__DOT__write_reg__47__value 
                                            = (0xfffff000U 
                                               & vlSelf->ysyx_22040000__DOT__inst);
                                        __Vtask_ysyx_22040000__DOT__write_reg__47__idx 
                                            = vlSelf->ysyx_22040000__DOT__rd;
                                        if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__47__idx)) 
                                             & (0x10U 
                                                > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__47__idx)))) {
                                            __Vdlyvval__ysyx_22040000__DOT__regs__v21 
                                                = __Vtask_ysyx_22040000__DOT__write_reg__47__value;
                                            __Vdlyvset__ysyx_22040000__DOT__regs__v21 = 1U;
                                            __Vdlyvdim0__ysyx_22040000__DOT__regs__v21 
                                                = (0xfU 
                                                   & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__47__idx));
                                        }
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = ((IData)(4U) 
                                               + vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    }
                                } else {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                }
                            } else {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            }
                        } else if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                if ((((0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rd)) 
                                      | (0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs1))) 
                                     | (0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs2)))) {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                } else {
                                    vlSelf->ysyx_22040000__DOT__alu_y 
                                        = (((((((((0U 
                                                   == 
                                                   (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                     << 3U) 
                                                    | (IData)(vlSelf->ysyx_22040000__DOT__funct3))) 
                                                  | (0x100U 
                                                     == 
                                                     (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                       << 3U) 
                                                      | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))) 
                                                 | (1U 
                                                    == 
                                                    (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                      << 3U) 
                                                     | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))) 
                                                | (2U 
                                                   == 
                                                   (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                     << 3U) 
                                                    | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))) 
                                               | (3U 
                                                  == 
                                                  (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                    << 3U) 
                                                   | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))) 
                                              | (4U 
                                                 == 
                                                 (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                   << 3U) 
                                                  | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))) 
                                             | (5U 
                                                == 
                                                (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))) 
                                            | (0x105U 
                                               == (
                                                   ((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                    << 3U) 
                                                   | (IData)(vlSelf->ysyx_22040000__DOT__funct3))))
                                            ? ((0U 
                                                == 
                                                (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                ? (vlSelf->ysyx_22040000__DOT__alu_a 
                                                   + vlSelf->ysyx_22040000__DOT__alu_b)
                                                : (
                                                   (0x100U 
                                                    == 
                                                    (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                      << 3U) 
                                                     | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                    ? 
                                                   (vlSelf->ysyx_22040000__DOT__alu_a 
                                                    - vlSelf->ysyx_22040000__DOT__alu_b)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                       << 3U) 
                                                      | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                     ? 
                                                    (vlSelf->ysyx_22040000__DOT__alu_a 
                                                     << 
                                                     (0x1fU 
                                                      & vlSelf->ysyx_22040000__DOT__alu_b))
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                        << 3U) 
                                                       | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                      ? 
                                                     (VL_LTS_III(32, vlSelf->ysyx_22040000__DOT__alu_a, vlSelf->ysyx_22040000__DOT__alu_b)
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                         << 3U) 
                                                        | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                       ? 
                                                      ((vlSelf->ysyx_22040000__DOT__alu_a 
                                                        < vlSelf->ysyx_22040000__DOT__alu_b)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                          << 3U) 
                                                         | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                        ? 
                                                       (vlSelf->ysyx_22040000__DOT__alu_a 
                                                        ^ vlSelf->ysyx_22040000__DOT__alu_b)
                                                        : 
                                                       ((5U 
                                                         == 
                                                         (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                           << 3U) 
                                                          | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                         ? 
                                                        (vlSelf->ysyx_22040000__DOT__alu_a 
                                                         >> 
                                                         (0x1fU 
                                                          & vlSelf->ysyx_22040000__DOT__alu_b))
                                                         : 
                                                        VL_SHIFTRS_III(32,32,5, vlSelf->ysyx_22040000__DOT__alu_a, 
                                                                       (0x1fU 
                                                                        & vlSelf->ysyx_22040000__DOT__alu_b)))))))))
                                            : ((6U 
                                                == 
                                                (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                  << 3U) 
                                                 | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                ? (vlSelf->ysyx_22040000__DOT__alu_a 
                                                   | vlSelf->ysyx_22040000__DOT__alu_b)
                                                : (
                                                   (7U 
                                                    == 
                                                    (((IData)(vlSelf->ysyx_22040000__DOT__funct7) 
                                                      << 3U) 
                                                     | (IData)(vlSelf->ysyx_22040000__DOT__funct3)))
                                                    ? 
                                                   (vlSelf->ysyx_22040000__DOT__alu_a 
                                                    & vlSelf->ysyx_22040000__DOT__alu_b)
                                                    : 0U)));
                                    __Vtask_ysyx_22040000__DOT__write_reg__51__value 
                                        = vlSelf->ysyx_22040000__DOT__alu_y;
                                    __Vtask_ysyx_22040000__DOT__write_reg__51__idx 
                                        = vlSelf->ysyx_22040000__DOT__rd;
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = ((IData)(4U) 
                                           + vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                    if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__51__idx)) 
                                         & (0x10U > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__51__idx)))) {
                                        __Vdlyvval__ysyx_22040000__DOT__regs__v22 
                                            = __Vtask_ysyx_22040000__DOT__write_reg__51__value;
                                        __Vdlyvset__ysyx_22040000__DOT__regs__v22 = 1U;
                                        __Vdlyvdim0__ysyx_22040000__DOT__regs__v22 
                                            = (0xfU 
                                               & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__51__idx));
                                    }
                                }
                            } else {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            }
                        } else {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        }
                    } else if ((8U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    } else if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    } else if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if (((0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs1)) 
                                 | (0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs2)))) {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            } else {
                                __Vfunc_ysyx_22040000__DOT__store_imm__57__raw 
                                    = vlSelf->ysyx_22040000__DOT__inst;
                                __Vfunc_ysyx_22040000__DOT__sext__58__value 
                                    = ((0xfe0U & (__Vfunc_ysyx_22040000__DOT__store_imm__57__raw 
                                                  >> 0x14U)) 
                                       | (0x1fU & (__Vfunc_ysyx_22040000__DOT__store_imm__57__raw 
                                                   >> 7U)));
                                __Vfunc_ysyx_22040000__DOT__sext__58__Vfuncout 
                                    = ((0x800U ^ __Vfunc_ysyx_22040000__DOT__sext__58__value) 
                                       - (IData)(0x800U));
                                __Vfunc_ysyx_22040000__DOT__store_imm__57__Vfuncout 
                                    = __Vfunc_ysyx_22040000__DOT__sext__58__Vfuncout;
                                vlSelf->ysyx_22040000__DOT__tmp_addr 
                                    = (vlSelf->ysyx_22040000__DOT__alu_a 
                                       + __Vfunc_ysyx_22040000__DOT__store_imm__57__Vfuncout);
                                __Vdly__ysyx_22040000__DOT__mem_addr 
                                    = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                if ((0U == (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                    __Vdly__ysyx_22040000__DOT__mem_size = 0U;
                                    vlSelf->ysyx_22040000__DOT__mem_wdata 
                                        = (vlSelf->ysyx_22040000__DOT__alu_b 
                                           << (0x18U 
                                               & (vlSelf->ysyx_22040000__DOT__tmp_addr 
                                                  << 3U)));
                                    vlSelf->ysyx_22040000__DOT__mem_wstrb 
                                        = (0xfU & ((IData)(1U) 
                                                   << 
                                                   (3U 
                                                    & vlSelf->ysyx_22040000__DOT__tmp_addr)));
                                    __Vfunc_ysyx_22040000__DOT__clint_addr__59__addr 
                                        = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                    __Vfunc_ysyx_22040000__DOT__clint_addr__59__Vfuncout 
                                        = ((0x2000000U 
                                            <= __Vfunc_ysyx_22040000__DOT__clint_addr__59__addr) 
                                           & (0x200ffffU 
                                              >= __Vfunc_ysyx_22040000__DOT__clint_addr__59__addr));
                                    if (__Vfunc_ysyx_22040000__DOT__clint_addr__59__Vfuncout) {
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = ((IData)(4U) 
                                               + vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    } else {
                                        __Vdly__ysyx_22040000__DOT__state = 6U;
                                    }
                                } else if ((1U == (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                    __Vdly__ysyx_22040000__DOT__mem_size = 1U;
                                    vlSelf->ysyx_22040000__DOT__mem_wdata 
                                        = (vlSelf->ysyx_22040000__DOT__alu_b 
                                           << (0x10U 
                                               & (vlSelf->ysyx_22040000__DOT__tmp_addr 
                                                  << 3U)));
                                    vlSelf->ysyx_22040000__DOT__mem_wstrb 
                                        = ((2U & vlSelf->ysyx_22040000__DOT__tmp_addr)
                                            ? 0xcU : 3U);
                                    if ((1U & vlSelf->ysyx_22040000__DOT__tmp_addr)) {
                                        __Vdly__ysyx_22040000__DOT__csr_mcause = 6U;
                                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                                            = (0xfffffffcU 
                                               & vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    } else {
                                        __Vfunc_ysyx_22040000__DOT__clint_addr__61__addr 
                                            = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                        __Vfunc_ysyx_22040000__DOT__clint_addr__61__Vfuncout 
                                            = ((0x2000000U 
                                                <= __Vfunc_ysyx_22040000__DOT__clint_addr__61__addr) 
                                               & (0x200ffffU 
                                                  >= __Vfunc_ysyx_22040000__DOT__clint_addr__61__addr));
                                        if (__Vfunc_ysyx_22040000__DOT__clint_addr__61__Vfuncout) {
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = ((IData)(4U) 
                                                   + vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                        } else {
                                            __Vdly__ysyx_22040000__DOT__state = 6U;
                                        }
                                    }
                                } else if ((2U == (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                    __Vdly__ysyx_22040000__DOT__mem_size = 2U;
                                    vlSelf->ysyx_22040000__DOT__mem_wdata 
                                        = vlSelf->ysyx_22040000__DOT__alu_b;
                                    vlSelf->ysyx_22040000__DOT__mem_wstrb = 0xfU;
                                    if ((0U != (3U 
                                                & vlSelf->ysyx_22040000__DOT__tmp_addr))) {
                                        __Vdly__ysyx_22040000__DOT__csr_mcause = 6U;
                                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                                            = (0xfffffffcU 
                                               & vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    } else {
                                        __Vfunc_ysyx_22040000__DOT__clint_addr__63__addr 
                                            = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                        __Vfunc_ysyx_22040000__DOT__clint_addr__63__Vfuncout 
                                            = ((0x2000000U 
                                                <= __Vfunc_ysyx_22040000__DOT__clint_addr__63__addr) 
                                               & (0x200ffffU 
                                                  >= __Vfunc_ysyx_22040000__DOT__clint_addr__63__addr));
                                        if (__Vfunc_ysyx_22040000__DOT__clint_addr__63__Vfuncout) {
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = ((IData)(4U) 
                                                   + vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                        } else {
                                            __Vdly__ysyx_22040000__DOT__state = 6U;
                                        }
                                    }
                                } else {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                }
                            }
                        } else {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        }
                    } else {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    }
                } else if ((0x10U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                    if ((8U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    } else if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                if ((0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rd))) {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                } else {
                                    __Vtask_ysyx_22040000__DOT__write_reg__69__value 
                                        = (vlSelf->ysyx_22040000__DOT__inst_pc 
                                           + (0xfffff000U 
                                              & vlSelf->ysyx_22040000__DOT__inst));
                                    __Vtask_ysyx_22040000__DOT__write_reg__69__idx 
                                        = vlSelf->ysyx_22040000__DOT__rd;
                                    if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__69__idx)) 
                                         & (0x10U > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__69__idx)))) {
                                        __Vdlyvval__ysyx_22040000__DOT__regs__v23 
                                            = __Vtask_ysyx_22040000__DOT__write_reg__69__value;
                                        __Vdlyvset__ysyx_22040000__DOT__regs__v23 = 1U;
                                        __Vdlyvdim0__ysyx_22040000__DOT__regs__v23 
                                            = (0xfU 
                                               & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__69__idx));
                                    }
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = ((IData)(4U) 
                                           + vlSelf->ysyx_22040000__DOT__inst_pc);
                                }
                            } else {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            }
                        } else {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        }
                    } else if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if (((0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rd)) 
                                 | (0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs1)))) {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            } else {
                                __Vfunc_ysyx_22040000__DOT__sext__73__value 
                                    = (vlSelf->ysyx_22040000__DOT__inst 
                                       >> 0x14U);
                                __Vfunc_ysyx_22040000__DOT__sext__73__Vfuncout 
                                    = ((0x800U ^ __Vfunc_ysyx_22040000__DOT__sext__73__value) 
                                       - (IData)(0x800U));
                                vlSelf->ysyx_22040000__DOT__tmp_imm 
                                    = __Vfunc_ysyx_22040000__DOT__sext__73__Vfuncout;
                                vlSelf->ysyx_22040000__DOT__alu_y 
                                    = ((4U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                        ? ((2U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                            ? ((1U 
                                                & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                                ? (vlSelf->ysyx_22040000__DOT__alu_a 
                                                   & vlSelf->ysyx_22040000__DOT__tmp_imm)
                                                : (vlSelf->ysyx_22040000__DOT__alu_a 
                                                   | vlSelf->ysyx_22040000__DOT__tmp_imm))
                                            : ((1U 
                                                & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                                ? (
                                                   (0U 
                                                    == (IData)(vlSelf->ysyx_22040000__DOT__funct7))
                                                    ? 
                                                   (vlSelf->ysyx_22040000__DOT__alu_a 
                                                    >> 
                                                    (0x1fU 
                                                     & (vlSelf->ysyx_22040000__DOT__inst 
                                                        >> 0x14U)))
                                                    : 
                                                   ((0x20U 
                                                     == (IData)(vlSelf->ysyx_22040000__DOT__funct7))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelf->ysyx_22040000__DOT__alu_a, 
                                                                   (0x1fU 
                                                                    & (vlSelf->ysyx_22040000__DOT__inst 
                                                                       >> 0x14U)))
                                                     : 0U))
                                                : (vlSelf->ysyx_22040000__DOT__alu_a 
                                                   ^ vlSelf->ysyx_22040000__DOT__tmp_imm)))
                                        : ((2U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                            ? ((1U 
                                                & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                                ? (
                                                   (vlSelf->ysyx_22040000__DOT__alu_a 
                                                    < vlSelf->ysyx_22040000__DOT__tmp_imm)
                                                    ? 1U
                                                    : 0U)
                                                : (
                                                   VL_LTS_III(32, vlSelf->ysyx_22040000__DOT__alu_a, vlSelf->ysyx_22040000__DOT__tmp_imm)
                                                    ? 1U
                                                    : 0U))
                                            : ((1U 
                                                & (IData)(vlSelf->ysyx_22040000__DOT__funct3))
                                                ? (
                                                   (0U 
                                                    == (IData)(vlSelf->ysyx_22040000__DOT__funct7))
                                                    ? 
                                                   (vlSelf->ysyx_22040000__DOT__alu_a 
                                                    << 
                                                    (0x1fU 
                                                     & (vlSelf->ysyx_22040000__DOT__inst 
                                                        >> 0x14U)))
                                                    : 0U)
                                                : (vlSelf->ysyx_22040000__DOT__alu_a 
                                                   + vlSelf->ysyx_22040000__DOT__tmp_imm))));
                                if ((((1U == (IData)(vlSelf->ysyx_22040000__DOT__funct3)) 
                                      & (0U != (IData)(vlSelf->ysyx_22040000__DOT__funct7))) 
                                     | (((5U == (IData)(vlSelf->ysyx_22040000__DOT__funct3)) 
                                         & (0U != (IData)(vlSelf->ysyx_22040000__DOT__funct7))) 
                                        & (0x20U != (IData)(vlSelf->ysyx_22040000__DOT__funct7))))) {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                } else {
                                    __Vtask_ysyx_22040000__DOT__write_reg__75__value 
                                        = vlSelf->ysyx_22040000__DOT__alu_y;
                                    __Vtask_ysyx_22040000__DOT__write_reg__75__idx 
                                        = vlSelf->ysyx_22040000__DOT__rd;
                                    if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__75__idx)) 
                                         & (0x10U > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__75__idx)))) {
                                        __Vdlyvval__ysyx_22040000__DOT__regs__v24 
                                            = __Vtask_ysyx_22040000__DOT__write_reg__75__value;
                                        __Vdlyvset__ysyx_22040000__DOT__regs__v24 = 1U;
                                        __Vdlyvdim0__ysyx_22040000__DOT__regs__v24 
                                            = (0xfU 
                                               & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__75__idx));
                                    }
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = ((IData)(4U) 
                                           + vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                }
                            }
                        } else {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        }
                    } else {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    }
                } else if ((8U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                    if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                            if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                                if ((1U == (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                    vlSelf->ysyx_22040000__DOT__ic_valid = 0U;
                                }
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = ((IData)(4U) 
                                       + vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            } else {
                                __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                __Vdly__ysyx_22040000__DOT__csr_mepc 
                                    = (0xfffffffcU 
                                       & vlSelf->ysyx_22040000__DOT__inst_pc);
                                __Vdly__ysyx_22040000__DOT__pc 
                                    = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                __Vdly__ysyx_22040000__DOT__state = 0U;
                            }
                        } else {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        }
                    } else {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    }
                } else if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                        = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                    __Vdly__ysyx_22040000__DOT__pc 
                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                    __Vdly__ysyx_22040000__DOT__state = 0U;
                } else if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                    if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__opcode))) {
                        if (((0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rd)) 
                             | (0x10U <= (IData)(vlSelf->ysyx_22040000__DOT__rs1)))) {
                            __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                            __Vdly__ysyx_22040000__DOT__csr_mepc 
                                = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                            __Vdly__ysyx_22040000__DOT__pc 
                                = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                            __Vdly__ysyx_22040000__DOT__state = 0U;
                        } else {
                            __Vfunc_ysyx_22040000__DOT__sext__84__value 
                                = (vlSelf->ysyx_22040000__DOT__inst 
                                   >> 0x14U);
                            __Vfunc_ysyx_22040000__DOT__sext__84__Vfuncout 
                                = ((0x800U ^ __Vfunc_ysyx_22040000__DOT__sext__84__value) 
                                   - (IData)(0x800U));
                            vlSelf->ysyx_22040000__DOT__tmp_addr 
                                = (vlSelf->ysyx_22040000__DOT__alu_a 
                                   + __Vfunc_ysyx_22040000__DOT__sext__84__Vfuncout);
                            __Vdly__ysyx_22040000__DOT__mem_rd 
                                = vlSelf->ysyx_22040000__DOT__rd;
                            __Vdly__ysyx_22040000__DOT__mem_unsigned 
                                = ((4U == (IData)(vlSelf->ysyx_22040000__DOT__funct3)) 
                                   | (5U == (IData)(vlSelf->ysyx_22040000__DOT__funct3)));
                            __Vdly__ysyx_22040000__DOT__mem_addr 
                                = vlSelf->ysyx_22040000__DOT__tmp_addr;
                            if ((4U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                } else if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                    __Vdly__ysyx_22040000__DOT__mem_size = 1U;
                                    if ((1U & vlSelf->ysyx_22040000__DOT__tmp_addr)) {
                                        __Vdly__ysyx_22040000__DOT__csr_mcause = 4U;
                                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                                            = (0xfffffffcU 
                                               & vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    } else {
                                        __Vfunc_ysyx_22040000__DOT__clint_addr__87__addr 
                                            = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                        __Vfunc_ysyx_22040000__DOT__clint_addr__87__Vfuncout 
                                            = ((0x2000000U 
                                                <= __Vfunc_ysyx_22040000__DOT__clint_addr__87__addr) 
                                               & (0x200ffffU 
                                                  >= __Vfunc_ysyx_22040000__DOT__clint_addr__87__addr));
                                        if (__Vfunc_ysyx_22040000__DOT__clint_addr__87__Vfuncout) {
                                            __Vfunc_ysyx_22040000__DOT__clint_read__89__addr 
                                                = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                            __Vfunc_ysyx_22040000__DOT__clint_read__89__Vfuncout 
                                                = (
                                                   (0x200bff8U 
                                                    == __Vfunc_ysyx_22040000__DOT__clint_read__89__addr)
                                                    ? (IData)(vlSelf->ysyx_22040000__DOT__mtime)
                                                    : 
                                                   ((0x200bffcU 
                                                     == __Vfunc_ysyx_22040000__DOT__clint_read__89__addr)
                                                     ? (IData)(
                                                               (vlSelf->ysyx_22040000__DOT__mtime 
                                                                >> 0x20U))
                                                     : 0U));
                                            __Vtask_ysyx_22040000__DOT__write_reg__88__value 
                                                = __Vfunc_ysyx_22040000__DOT__clint_read__89__Vfuncout;
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = ((IData)(4U) 
                                                   + vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                            __Vtask_ysyx_22040000__DOT__write_reg__88__idx 
                                                = vlSelf->ysyx_22040000__DOT__rd;
                                            if (((0U 
                                                  != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__88__idx)) 
                                                 & (0x10U 
                                                    > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__88__idx)))) {
                                                __Vdlyvval__ysyx_22040000__DOT__regs__v25 
                                                    = __Vtask_ysyx_22040000__DOT__write_reg__88__value;
                                                __Vdlyvset__ysyx_22040000__DOT__regs__v25 = 1U;
                                                __Vdlyvdim0__ysyx_22040000__DOT__regs__v25 
                                                    = 
                                                    (0xfU 
                                                     & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__88__idx));
                                            }
                                        } else {
                                            __Vdly__ysyx_22040000__DOT__state = 4U;
                                        }
                                    }
                                } else {
                                    __Vfunc_ysyx_22040000__DOT__clint_addr__90__addr 
                                        = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                    __Vfunc_ysyx_22040000__DOT__clint_addr__90__Vfuncout 
                                        = ((0x2000000U 
                                            <= __Vfunc_ysyx_22040000__DOT__clint_addr__90__addr) 
                                           & (0x200ffffU 
                                              >= __Vfunc_ysyx_22040000__DOT__clint_addr__90__addr));
                                    __Vdly__ysyx_22040000__DOT__mem_size = 0U;
                                    if (__Vfunc_ysyx_22040000__DOT__clint_addr__90__Vfuncout) {
                                        __Vfunc_ysyx_22040000__DOT__clint_read__92__addr 
                                            = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                        __Vfunc_ysyx_22040000__DOT__clint_read__92__Vfuncout 
                                            = ((0x200bff8U 
                                                == __Vfunc_ysyx_22040000__DOT__clint_read__92__addr)
                                                ? (IData)(vlSelf->ysyx_22040000__DOT__mtime)
                                                : (
                                                   (0x200bffcU 
                                                    == __Vfunc_ysyx_22040000__DOT__clint_read__92__addr)
                                                    ? (IData)(
                                                              (vlSelf->ysyx_22040000__DOT__mtime 
                                                               >> 0x20U))
                                                    : 0U));
                                        __Vtask_ysyx_22040000__DOT__write_reg__91__value 
                                            = __Vfunc_ysyx_22040000__DOT__clint_read__92__Vfuncout;
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = ((IData)(4U) 
                                               + vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                        __Vtask_ysyx_22040000__DOT__write_reg__91__idx 
                                            = vlSelf->ysyx_22040000__DOT__rd;
                                        if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__91__idx)) 
                                             & (0x10U 
                                                > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__91__idx)))) {
                                            __Vdlyvval__ysyx_22040000__DOT__regs__v26 
                                                = __Vtask_ysyx_22040000__DOT__write_reg__91__value;
                                            __Vdlyvset__ysyx_22040000__DOT__regs__v26 = 1U;
                                            __Vdlyvdim0__ysyx_22040000__DOT__regs__v26 
                                                = (0xfU 
                                                   & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__91__idx));
                                        }
                                    } else {
                                        __Vdly__ysyx_22040000__DOT__state = 4U;
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                } else {
                                    __Vdly__ysyx_22040000__DOT__mem_size = 2U;
                                    if ((0U != (3U 
                                                & vlSelf->ysyx_22040000__DOT__tmp_addr))) {
                                        __Vdly__ysyx_22040000__DOT__csr_mcause = 4U;
                                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                                            = (0xfffffffcU 
                                               & vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                    } else {
                                        __Vfunc_ysyx_22040000__DOT__clint_addr__95__addr 
                                            = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                        __Vfunc_ysyx_22040000__DOT__clint_addr__95__Vfuncout 
                                            = ((0x2000000U 
                                                <= __Vfunc_ysyx_22040000__DOT__clint_addr__95__addr) 
                                               & (0x200ffffU 
                                                  >= __Vfunc_ysyx_22040000__DOT__clint_addr__95__addr));
                                        if (__Vfunc_ysyx_22040000__DOT__clint_addr__95__Vfuncout) {
                                            __Vfunc_ysyx_22040000__DOT__clint_read__97__addr 
                                                = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                            __Vfunc_ysyx_22040000__DOT__clint_read__97__Vfuncout 
                                                = (
                                                   (0x200bff8U 
                                                    == __Vfunc_ysyx_22040000__DOT__clint_read__97__addr)
                                                    ? (IData)(vlSelf->ysyx_22040000__DOT__mtime)
                                                    : 
                                                   ((0x200bffcU 
                                                     == __Vfunc_ysyx_22040000__DOT__clint_read__97__addr)
                                                     ? (IData)(
                                                               (vlSelf->ysyx_22040000__DOT__mtime 
                                                                >> 0x20U))
                                                     : 0U));
                                            __Vtask_ysyx_22040000__DOT__write_reg__96__value 
                                                = __Vfunc_ysyx_22040000__DOT__clint_read__97__Vfuncout;
                                            __Vdly__ysyx_22040000__DOT__pc 
                                                = ((IData)(4U) 
                                                   + vlSelf->ysyx_22040000__DOT__inst_pc);
                                            __Vdly__ysyx_22040000__DOT__state = 0U;
                                            __Vtask_ysyx_22040000__DOT__write_reg__96__idx 
                                                = vlSelf->ysyx_22040000__DOT__rd;
                                            if (((0U 
                                                  != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__96__idx)) 
                                                 & (0x10U 
                                                    > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__96__idx)))) {
                                                __Vdlyvval__ysyx_22040000__DOT__regs__v27 
                                                    = __Vtask_ysyx_22040000__DOT__write_reg__96__value;
                                                __Vdlyvset__ysyx_22040000__DOT__regs__v27 = 1U;
                                                __Vdlyvdim0__ysyx_22040000__DOT__regs__v27 
                                                    = 
                                                    (0xfU 
                                                     & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__96__idx));
                                            }
                                        } else {
                                            __Vdly__ysyx_22040000__DOT__state = 4U;
                                        }
                                    }
                                }
                            } else if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__funct3))) {
                                __Vdly__ysyx_22040000__DOT__mem_size = 1U;
                                if ((1U & vlSelf->ysyx_22040000__DOT__tmp_addr)) {
                                    __Vdly__ysyx_22040000__DOT__csr_mcause = 4U;
                                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                                        = (0xfffffffcU 
                                           & vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                } else {
                                    __Vfunc_ysyx_22040000__DOT__clint_addr__99__addr 
                                        = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                    __Vfunc_ysyx_22040000__DOT__clint_addr__99__Vfuncout 
                                        = ((0x2000000U 
                                            <= __Vfunc_ysyx_22040000__DOT__clint_addr__99__addr) 
                                           & (0x200ffffU 
                                              >= __Vfunc_ysyx_22040000__DOT__clint_addr__99__addr));
                                    if (__Vfunc_ysyx_22040000__DOT__clint_addr__99__Vfuncout) {
                                        __Vfunc_ysyx_22040000__DOT__clint_read__101__addr 
                                            = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                        __Vfunc_ysyx_22040000__DOT__clint_read__101__Vfuncout 
                                            = ((0x200bff8U 
                                                == __Vfunc_ysyx_22040000__DOT__clint_read__101__addr)
                                                ? (IData)(vlSelf->ysyx_22040000__DOT__mtime)
                                                : (
                                                   (0x200bffcU 
                                                    == __Vfunc_ysyx_22040000__DOT__clint_read__101__addr)
                                                    ? (IData)(
                                                              (vlSelf->ysyx_22040000__DOT__mtime 
                                                               >> 0x20U))
                                                    : 0U));
                                        __Vtask_ysyx_22040000__DOT__write_reg__100__value 
                                            = __Vfunc_ysyx_22040000__DOT__clint_read__101__Vfuncout;
                                        __Vdly__ysyx_22040000__DOT__pc 
                                            = ((IData)(4U) 
                                               + vlSelf->ysyx_22040000__DOT__inst_pc);
                                        __Vdly__ysyx_22040000__DOT__state = 0U;
                                        __Vtask_ysyx_22040000__DOT__write_reg__100__idx 
                                            = vlSelf->ysyx_22040000__DOT__rd;
                                        if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__100__idx)) 
                                             & (0x10U 
                                                > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__100__idx)))) {
                                            __Vdlyvval__ysyx_22040000__DOT__regs__v28 
                                                = __Vtask_ysyx_22040000__DOT__write_reg__100__value;
                                            __Vdlyvset__ysyx_22040000__DOT__regs__v28 = 1U;
                                            __Vdlyvdim0__ysyx_22040000__DOT__regs__v28 
                                                = (0xfU 
                                                   & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__100__idx));
                                        }
                                    } else {
                                        __Vdly__ysyx_22040000__DOT__state = 4U;
                                    }
                                }
                            } else {
                                __Vfunc_ysyx_22040000__DOT__clint_addr__102__addr 
                                    = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                __Vfunc_ysyx_22040000__DOT__clint_addr__102__Vfuncout 
                                    = ((0x2000000U 
                                        <= __Vfunc_ysyx_22040000__DOT__clint_addr__102__addr) 
                                       & (0x200ffffU 
                                          >= __Vfunc_ysyx_22040000__DOT__clint_addr__102__addr));
                                __Vdly__ysyx_22040000__DOT__mem_size = 0U;
                                if (__Vfunc_ysyx_22040000__DOT__clint_addr__102__Vfuncout) {
                                    __Vfunc_ysyx_22040000__DOT__clint_read__104__addr 
                                        = vlSelf->ysyx_22040000__DOT__tmp_addr;
                                    __Vfunc_ysyx_22040000__DOT__clint_read__104__Vfuncout 
                                        = ((0x200bff8U 
                                            == __Vfunc_ysyx_22040000__DOT__clint_read__104__addr)
                                            ? (IData)(vlSelf->ysyx_22040000__DOT__mtime)
                                            : ((0x200bffcU 
                                                == __Vfunc_ysyx_22040000__DOT__clint_read__104__addr)
                                                ? (IData)(
                                                          (vlSelf->ysyx_22040000__DOT__mtime 
                                                           >> 0x20U))
                                                : 0U));
                                    __Vtask_ysyx_22040000__DOT__write_reg__103__value 
                                        = __Vfunc_ysyx_22040000__DOT__clint_read__104__Vfuncout;
                                    __Vdly__ysyx_22040000__DOT__pc 
                                        = ((IData)(4U) 
                                           + vlSelf->ysyx_22040000__DOT__inst_pc);
                                    __Vdly__ysyx_22040000__DOT__state = 0U;
                                    __Vtask_ysyx_22040000__DOT__write_reg__103__idx 
                                        = vlSelf->ysyx_22040000__DOT__rd;
                                    if (((0U != (IData)(__Vtask_ysyx_22040000__DOT__write_reg__103__idx)) 
                                         & (0x10U > (IData)(__Vtask_ysyx_22040000__DOT__write_reg__103__idx)))) {
                                        __Vdlyvval__ysyx_22040000__DOT__regs__v29 
                                            = __Vtask_ysyx_22040000__DOT__write_reg__103__value;
                                        __Vdlyvset__ysyx_22040000__DOT__regs__v29 = 1U;
                                        __Vdlyvdim0__ysyx_22040000__DOT__regs__v29 
                                            = (0xfU 
                                               & (IData)(__Vtask_ysyx_22040000__DOT__write_reg__103__idx));
                                    }
                                } else {
                                    __Vdly__ysyx_22040000__DOT__state = 4U;
                                }
                            }
                        }
                    } else {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    }
                } else {
                    __Vdly__ysyx_22040000__DOT__csr_mcause = 2U;
                    __Vdly__ysyx_22040000__DOT__csr_mepc 
                        = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                    __Vdly__ysyx_22040000__DOT__pc 
                        = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                    __Vdly__ysyx_22040000__DOT__state = 0U;
                }
            } else {
                __Vdly__ysyx_22040000__DOT__icache_miss_cycles 
                    = (1ULL + vlSelf->ysyx_22040000__DOT__icache_miss_cycles);
                if (vlSelf->io_master_rvalid) {
                    if ((0U != (IData)(vlSelf->io_master_rresp))) {
                        __Vdly__ysyx_22040000__DOT__csr_mcause = 1U;
                        __Vdly__ysyx_22040000__DOT__csr_mepc 
                            = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                        __Vdly__ysyx_22040000__DOT__pc 
                            = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                        __Vdly__ysyx_22040000__DOT__state = 0U;
                    } else {
                        if (vlSelf->ysyx_22040000__DOT__miss_index) {
                            if ((0U == (IData)(vlSelf->ysyx_22040000__DOT__miss_word))) {
                                __Vdly__ysyx_22040000__DOT__ic1_word0 
                                    = vlSelf->io_master_rdata;
                            } else if ((1U == (IData)(vlSelf->ysyx_22040000__DOT__miss_word))) {
                                __Vdly__ysyx_22040000__DOT__ic1_word1 
                                    = vlSelf->io_master_rdata;
                            } else if ((2U == (IData)(vlSelf->ysyx_22040000__DOT__miss_word))) {
                                __Vdly__ysyx_22040000__DOT__ic1_word2 
                                    = vlSelf->io_master_rdata;
                            } else {
                                __Vdly__ysyx_22040000__DOT__ic1_word3 
                                    = vlSelf->io_master_rdata;
                            }
                        } else if ((0U == (IData)(vlSelf->ysyx_22040000__DOT__miss_word))) {
                            __Vdly__ysyx_22040000__DOT__ic0_word0 
                                = vlSelf->io_master_rdata;
                        } else if ((1U == (IData)(vlSelf->ysyx_22040000__DOT__miss_word))) {
                            __Vdly__ysyx_22040000__DOT__ic0_word1 
                                = vlSelf->io_master_rdata;
                        } else if ((2U == (IData)(vlSelf->ysyx_22040000__DOT__miss_word))) {
                            __Vdly__ysyx_22040000__DOT__ic0_word2 
                                = vlSelf->io_master_rdata;
                        } else {
                            __Vdly__ysyx_22040000__DOT__ic0_word3 
                                = vlSelf->io_master_rdata;
                        }
                        if (((IData)(vlSelf->ysyx_22040000__DOT__miss_word) 
                             == (IData)(vlSelf->ysyx_22040000__DOT__miss_target_word))) {
                            __Vdly__ysyx_22040000__DOT__miss_saved_inst 
                                = vlSelf->io_master_rdata;
                        }
                        if (vlSelf->io_master_rlast) {
                            if (vlSelf->ysyx_22040000__DOT__miss_index) {
                                vlSelf->ysyx_22040000__DOT__ic_valid 
                                    = (2U | (IData)(vlSelf->ysyx_22040000__DOT__ic_valid));
                                vlSelf->ysyx_22040000__DOT__ic_tag1 
                                    = vlSelf->ysyx_22040000__DOT__miss_tag;
                            } else {
                                vlSelf->ysyx_22040000__DOT__ic_valid 
                                    = (1U | (IData)(vlSelf->ysyx_22040000__DOT__ic_valid));
                                vlSelf->ysyx_22040000__DOT__ic_tag0 
                                    = vlSelf->ysyx_22040000__DOT__miss_tag;
                            }
                            __Vdly__ysyx_22040000__DOT__inst 
                                = (((IData)(vlSelf->ysyx_22040000__DOT__miss_word) 
                                    == (IData)(vlSelf->ysyx_22040000__DOT__miss_target_word))
                                    ? vlSelf->io_master_rdata
                                    : vlSelf->ysyx_22040000__DOT__miss_saved_inst);
                            __Vdly__ysyx_22040000__DOT__state = 3U;
                        } else {
                            __Vdly__ysyx_22040000__DOT__miss_word 
                                = (3U & ((IData)(1U) 
                                         + (IData)(vlSelf->ysyx_22040000__DOT__miss_word)));
                        }
                    }
                }
            }
        } else if ((1U & (IData)(vlSelf->ysyx_22040000__DOT__state))) {
            __Vdly__ysyx_22040000__DOT__icache_miss_cycles 
                = (1ULL + vlSelf->ysyx_22040000__DOT__icache_miss_cycles);
            if (vlSelf->io_master_arready) {
                __Vdly__ysyx_22040000__DOT__state = 2U;
            }
        } else {
            __Vdly__ysyx_22040000__DOT__inst_pc = vlSelf->ysyx_22040000__DOT__pc;
            if ((0U != (3U & vlSelf->ysyx_22040000__DOT__pc))) {
                __Vdly__ysyx_22040000__DOT__csr_mcause = 0U;
                __Vdly__ysyx_22040000__DOT__csr_mepc 
                    = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__inst_pc);
                __Vdly__ysyx_22040000__DOT__pc = vlSelf->ysyx_22040000__DOT__csr_mtvec;
                __Vdly__ysyx_22040000__DOT__state = 0U;
            } else {
                __Vdly__ysyx_22040000__DOT__icache_accesses 
                    = (1ULL + vlSelf->ysyx_22040000__DOT__icache_accesses);
                if (vlSelf->ysyx_22040000__DOT__if_hit) {
                    __Vfunc_ysyx_22040000__DOT__ic_word__109__word 
                        = (3U & (vlSelf->ysyx_22040000__DOT__pc 
                                 >> 2U));
                    __Vfunc_ysyx_22040000__DOT__ic_word__109__index 
                        = (1U & (vlSelf->ysyx_22040000__DOT__pc 
                                 >> 4U));
                    __Vfunc_ysyx_22040000__DOT__ic_word__109__Vfuncout 
                        = ((IData)(__Vfunc_ysyx_22040000__DOT__ic_word__109__index)
                            ? ((0U == (IData)(__Vfunc_ysyx_22040000__DOT__ic_word__109__word))
                                ? vlSelf->ysyx_22040000__DOT__ic1_word0
                                : ((1U == (IData)(__Vfunc_ysyx_22040000__DOT__ic_word__109__word))
                                    ? vlSelf->ysyx_22040000__DOT__ic1_word1
                                    : ((2U == (IData)(__Vfunc_ysyx_22040000__DOT__ic_word__109__word))
                                        ? vlSelf->ysyx_22040000__DOT__ic1_word2
                                        : vlSelf->ysyx_22040000__DOT__ic1_word3)))
                            : ((0U == (IData)(__Vfunc_ysyx_22040000__DOT__ic_word__109__word))
                                ? vlSelf->ysyx_22040000__DOT__ic0_word0
                                : ((1U == (IData)(__Vfunc_ysyx_22040000__DOT__ic_word__109__word))
                                    ? vlSelf->ysyx_22040000__DOT__ic0_word1
                                    : ((2U == (IData)(__Vfunc_ysyx_22040000__DOT__ic_word__109__word))
                                        ? vlSelf->ysyx_22040000__DOT__ic0_word2
                                        : vlSelf->ysyx_22040000__DOT__ic0_word3))));
                    __Vdly__ysyx_22040000__DOT__state = 3U;
                    __Vdly__ysyx_22040000__DOT__inst 
                        = __Vfunc_ysyx_22040000__DOT__ic_word__109__Vfuncout;
                } else {
                    __Vdly__ysyx_22040000__DOT__icache_misses 
                        = (1ULL + vlSelf->ysyx_22040000__DOT__icache_misses);
                    vlSelf->ysyx_22040000__DOT__miss_addr 
                        = (0xfffffff0U & vlSelf->ysyx_22040000__DOT__pc);
                    __Vdly__ysyx_22040000__DOT__miss_word = 0U;
                    __Vdly__ysyx_22040000__DOT__miss_saved_inst = 0U;
                    __Vdly__ysyx_22040000__DOT__state = 1U;
                    __Vdly__ysyx_22040000__DOT__miss_index 
                        = (1U & (vlSelf->ysyx_22040000__DOT__pc 
                                 >> 4U));
                    __Vdly__ysyx_22040000__DOT__miss_tag 
                        = (vlSelf->ysyx_22040000__DOT__pc 
                           >> 5U);
                    __Vdly__ysyx_22040000__DOT__miss_target_word 
                        = (3U & (vlSelf->ysyx_22040000__DOT__pc 
                                 >> 2U));
                }
            }
        }
    }
    vlSelf->ysyx_22040000__DOT__inst_pc = __Vdly__ysyx_22040000__DOT__inst_pc;
    vlSelf->ysyx_22040000__DOT__csr_mtvec = __Vdly__ysyx_22040000__DOT__csr_mtvec;
    vlSelf->ysyx_22040000__DOT__csr_mepc = __Vdly__ysyx_22040000__DOT__csr_mepc;
    vlSelf->ysyx_22040000__DOT__csr_mcause = __Vdly__ysyx_22040000__DOT__csr_mcause;
    vlSelf->ysyx_22040000__DOT__mtime = __Vdly__ysyx_22040000__DOT__mtime;
    vlSelf->ysyx_22040000__DOT__instret_count = __Vdly__ysyx_22040000__DOT__instret_count;
    vlSelf->ysyx_22040000__DOT__icache_accesses = __Vdly__ysyx_22040000__DOT__icache_accesses;
    vlSelf->ysyx_22040000__DOT__icache_misses = __Vdly__ysyx_22040000__DOT__icache_misses;
    vlSelf->ysyx_22040000__DOT__icache_miss_cycles 
        = __Vdly__ysyx_22040000__DOT__icache_miss_cycles;
    vlSelf->ysyx_22040000__DOT__ic0_word0 = __Vdly__ysyx_22040000__DOT__ic0_word0;
    vlSelf->ysyx_22040000__DOT__ic0_word1 = __Vdly__ysyx_22040000__DOT__ic0_word1;
    vlSelf->ysyx_22040000__DOT__ic0_word2 = __Vdly__ysyx_22040000__DOT__ic0_word2;
    vlSelf->ysyx_22040000__DOT__ic0_word3 = __Vdly__ysyx_22040000__DOT__ic0_word3;
    vlSelf->ysyx_22040000__DOT__ic1_word0 = __Vdly__ysyx_22040000__DOT__ic1_word0;
    vlSelf->ysyx_22040000__DOT__ic1_word1 = __Vdly__ysyx_22040000__DOT__ic1_word1;
    vlSelf->ysyx_22040000__DOT__ic1_word2 = __Vdly__ysyx_22040000__DOT__ic1_word2;
    vlSelf->ysyx_22040000__DOT__ic1_word3 = __Vdly__ysyx_22040000__DOT__ic1_word3;
    vlSelf->ysyx_22040000__DOT__miss_index = __Vdly__ysyx_22040000__DOT__miss_index;
    vlSelf->ysyx_22040000__DOT__miss_tag = __Vdly__ysyx_22040000__DOT__miss_tag;
    vlSelf->ysyx_22040000__DOT__miss_word = __Vdly__ysyx_22040000__DOT__miss_word;
    vlSelf->ysyx_22040000__DOT__miss_target_word = __Vdly__ysyx_22040000__DOT__miss_target_word;
    vlSelf->ysyx_22040000__DOT__miss_saved_inst = __Vdly__ysyx_22040000__DOT__miss_saved_inst;
    vlSelf->ysyx_22040000__DOT__mem_rd = __Vdly__ysyx_22040000__DOT__mem_rd;
    vlSelf->ysyx_22040000__DOT__mem_size = __Vdly__ysyx_22040000__DOT__mem_size;
    vlSelf->ysyx_22040000__DOT__mem_unsigned = __Vdly__ysyx_22040000__DOT__mem_unsigned;
    vlSelf->ysyx_22040000__DOT__pc = __Vdly__ysyx_22040000__DOT__pc;
    vlSelf->ysyx_22040000__DOT__mem_addr = __Vdly__ysyx_22040000__DOT__mem_addr;
    vlSelf->ysyx_22040000__DOT__inst = __Vdly__ysyx_22040000__DOT__inst;
    vlSelf->ysyx_22040000__DOT__state = __Vdly__ysyx_22040000__DOT__state;
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v0) {
        vlSelf->ysyx_22040000__DOT__regs[0U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[1U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[2U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[3U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[4U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[5U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[6U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[7U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[8U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[9U] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[0xaU] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[0xbU] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[0xcU] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[0xdU] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[0xeU] = 0U;
        vlSelf->ysyx_22040000__DOT__regs[0xfU] = 0U;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v16) {
        vlSelf->ysyx_22040000__DOT__regs[0U] = 0U;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v17) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v17] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v17;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v18) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v18] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v18;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v19) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v19] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v19;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v20) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v20] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v20;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v21) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v21] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v21;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v22) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v22] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v22;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v23) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v23] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v23;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v24) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v24] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v24;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v25) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v25] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v25;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v26) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v26] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v26;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v27) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v27] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v27;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v28) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v28] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v28;
    }
    if (__Vdlyvset__ysyx_22040000__DOT__regs__v29) {
        vlSelf->ysyx_22040000__DOT__regs[__Vdlyvdim0__ysyx_22040000__DOT__regs__v29] 
            = __Vdlyvval__ysyx_22040000__DOT__regs__v29;
    }
    vlSelf->io_master_wdata = vlSelf->ysyx_22040000__DOT__mem_wdata;
    vlSelf->io_master_wstrb = vlSelf->ysyx_22040000__DOT__mem_wstrb;
    vlSelf->ysyx_22040000__DOT__if_hit = ((0x10U & vlSelf->ysyx_22040000__DOT__pc)
                                           ? (((IData)(vlSelf->ysyx_22040000__DOT__ic_valid) 
                                               >> 1U) 
                                              & (vlSelf->ysyx_22040000__DOT__ic_tag1 
                                                 == 
                                                 (vlSelf->ysyx_22040000__DOT__pc 
                                                  >> 5U)))
                                           : ((IData)(vlSelf->ysyx_22040000__DOT__ic_valid) 
                                              & (vlSelf->ysyx_22040000__DOT__ic_tag0 
                                                 == 
                                                 (vlSelf->ysyx_22040000__DOT__pc 
                                                  >> 5U))));
    vlSelf->io_master_awaddr = (0xfffffffcU & vlSelf->ysyx_22040000__DOT__mem_addr);
    vlSelf->ysyx_22040000__DOT__rs1 = (0x1fU & (vlSelf->ysyx_22040000__DOT__inst 
                                                >> 0xfU));
    vlSelf->ysyx_22040000__DOT__rs2 = (0x1fU & (vlSelf->ysyx_22040000__DOT__inst 
                                                >> 0x14U));
    vlSelf->ysyx_22040000__DOT__opcode = (0x7fU & vlSelf->ysyx_22040000__DOT__inst);
    vlSelf->ysyx_22040000__DOT__rd = (0x1fU & (vlSelf->ysyx_22040000__DOT__inst 
                                               >> 7U));
    vlSelf->ysyx_22040000__DOT__funct3 = (7U & (vlSelf->ysyx_22040000__DOT__inst 
                                                >> 0xcU));
    vlSelf->ysyx_22040000__DOT__funct7 = (vlSelf->ysyx_22040000__DOT__inst 
                                          >> 0x19U);
    vlSelf->ysyx_22040000__DOT__csr_id = (vlSelf->ysyx_22040000__DOT__inst 
                                          >> 0x14U);
    vlSelf->io_master_bready = (7U == (IData)(vlSelf->ysyx_22040000__DOT__state));
    vlSelf->io_master_arvalid = ((1U == (IData)(vlSelf->ysyx_22040000__DOT__state)) 
                                 | (4U == (IData)(vlSelf->ysyx_22040000__DOT__state)));
    vlSelf->io_master_arlen = ((1U == (IData)(vlSelf->ysyx_22040000__DOT__state))
                                ? 3U : 0U);
    vlSelf->io_master_rready = ((2U == (IData)(vlSelf->ysyx_22040000__DOT__state)) 
                                | (5U == (IData)(vlSelf->ysyx_22040000__DOT__state)));
    vlSelf->io_master_awvalid = (6U == (IData)(vlSelf->ysyx_22040000__DOT__state));
    vlSelf->io_master_araddr = ((4U == (IData)(vlSelf->ysyx_22040000__DOT__state))
                                 ? vlSelf->io_master_awaddr
                                 : vlSelf->ysyx_22040000__DOT__miss_addr);
    vlSelf->io_master_wvalid = vlSelf->io_master_awvalid;
}

void Vysyx_22040000___024root___eval_nba(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_22040000___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vysyx_22040000___024root___eval_triggers__act(Vysyx_22040000___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22040000___024root___dump_triggers__act(Vysyx_22040000___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22040000___024root___dump_triggers__nba(Vysyx_22040000___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_22040000___024root___eval(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vysyx_22040000___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vysyx_22040000___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yanlx/ysyx-workbench/npc/vsrc/ysyx_22040000.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vysyx_22040000___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vysyx_22040000___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yanlx/ysyx-workbench/npc/vsrc/ysyx_22040000.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vysyx_22040000___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_22040000___024root___eval_debug_assertions(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_interrupt & 0xfeU))) {
        Verilated::overWidthError("io_interrupt");}
    if (VL_UNLIKELY((vlSelf->io_master_awready & 0xfeU))) {
        Verilated::overWidthError("io_master_awready");}
    if (VL_UNLIKELY((vlSelf->io_master_wready & 0xfeU))) {
        Verilated::overWidthError("io_master_wready");}
    if (VL_UNLIKELY((vlSelf->io_master_bvalid & 0xfeU))) {
        Verilated::overWidthError("io_master_bvalid");}
    if (VL_UNLIKELY((vlSelf->io_master_bresp & 0xfcU))) {
        Verilated::overWidthError("io_master_bresp");}
    if (VL_UNLIKELY((vlSelf->io_master_bid & 0xf0U))) {
        Verilated::overWidthError("io_master_bid");}
    if (VL_UNLIKELY((vlSelf->io_master_arready & 0xfeU))) {
        Verilated::overWidthError("io_master_arready");}
    if (VL_UNLIKELY((vlSelf->io_master_rvalid & 0xfeU))) {
        Verilated::overWidthError("io_master_rvalid");}
    if (VL_UNLIKELY((vlSelf->io_master_rresp & 0xfcU))) {
        Verilated::overWidthError("io_master_rresp");}
    if (VL_UNLIKELY((vlSelf->io_master_rlast & 0xfeU))) {
        Verilated::overWidthError("io_master_rlast");}
    if (VL_UNLIKELY((vlSelf->io_master_rid & 0xf0U))) {
        Verilated::overWidthError("io_master_rid");}
    if (VL_UNLIKELY((vlSelf->io_slave_awvalid & 0xfeU))) {
        Verilated::overWidthError("io_slave_awvalid");}
    if (VL_UNLIKELY((vlSelf->io_slave_awid & 0xf0U))) {
        Verilated::overWidthError("io_slave_awid");}
    if (VL_UNLIKELY((vlSelf->io_slave_awsize & 0xf8U))) {
        Verilated::overWidthError("io_slave_awsize");}
    if (VL_UNLIKELY((vlSelf->io_slave_awburst & 0xfcU))) {
        Verilated::overWidthError("io_slave_awburst");}
    if (VL_UNLIKELY((vlSelf->io_slave_wvalid & 0xfeU))) {
        Verilated::overWidthError("io_slave_wvalid");}
    if (VL_UNLIKELY((vlSelf->io_slave_wstrb & 0xf0U))) {
        Verilated::overWidthError("io_slave_wstrb");}
    if (VL_UNLIKELY((vlSelf->io_slave_wlast & 0xfeU))) {
        Verilated::overWidthError("io_slave_wlast");}
    if (VL_UNLIKELY((vlSelf->io_slave_bready & 0xfeU))) {
        Verilated::overWidthError("io_slave_bready");}
    if (VL_UNLIKELY((vlSelf->io_slave_arvalid & 0xfeU))) {
        Verilated::overWidthError("io_slave_arvalid");}
    if (VL_UNLIKELY((vlSelf->io_slave_arid & 0xf0U))) {
        Verilated::overWidthError("io_slave_arid");}
    if (VL_UNLIKELY((vlSelf->io_slave_arsize & 0xf8U))) {
        Verilated::overWidthError("io_slave_arsize");}
    if (VL_UNLIKELY((vlSelf->io_slave_arburst & 0xfcU))) {
        Verilated::overWidthError("io_slave_arburst");}
    if (VL_UNLIKELY((vlSelf->io_slave_rready & 0xfeU))) {
        Verilated::overWidthError("io_slave_rready");}
}
#endif  // VL_DEBUG
