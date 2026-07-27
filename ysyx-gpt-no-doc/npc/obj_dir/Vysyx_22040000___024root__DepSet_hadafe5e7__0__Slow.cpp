// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22040000.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_22040000___024root.h"

VL_ATTR_COLD void Vysyx_22040000___024root___eval_static(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_22040000___024root___eval_initial__TOP(Vysyx_22040000___024root* vlSelf);

VL_ATTR_COLD void Vysyx_22040000___024root___eval_initial(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_initial\n"); );
    // Body
    Vysyx_22040000___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void Vysyx_22040000___024root___eval_initial__TOP(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->io_master_arid = 0U;
    vlSelf->io_master_arsize = 2U;
    vlSelf->io_master_arburst = 1U;
    vlSelf->io_master_awid = 0U;
    vlSelf->io_master_awlen = 0U;
    vlSelf->io_master_awsize = 2U;
    vlSelf->io_master_awburst = 1U;
    vlSelf->io_master_wlast = 1U;
    vlSelf->io_slave_awready = 0U;
    vlSelf->io_slave_wready = 0U;
    vlSelf->io_slave_bvalid = 0U;
    vlSelf->io_slave_bresp = 0U;
    vlSelf->io_slave_bid = 0U;
    vlSelf->io_slave_arready = 0U;
    vlSelf->io_slave_rvalid = 0U;
    vlSelf->io_slave_rresp = 0U;
    vlSelf->io_slave_rdata = 0U;
    vlSelf->io_slave_rlast = 0U;
    vlSelf->io_slave_rid = 0U;
}

VL_ATTR_COLD void Vysyx_22040000___024root___eval_final(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_22040000___024root___eval_triggers__stl(Vysyx_22040000___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22040000___024root___dump_triggers__stl(Vysyx_22040000___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_22040000___024root___eval_stl(Vysyx_22040000___024root* vlSelf);

VL_ATTR_COLD void Vysyx_22040000___024root___eval_settle(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_22040000___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_22040000___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yanlx/ysyx-workbench/npc/vsrc/ysyx_22040000.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_22040000___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22040000___024root___dump_triggers__stl(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_22040000___024root___stl_sequent__TOP__0(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->io_master_bready = (7U == (IData)(vlSelf->ysyx_22040000__DOT__state));
    vlSelf->io_master_arvalid = ((1U == (IData)(vlSelf->ysyx_22040000__DOT__state)) 
                                 | (4U == (IData)(vlSelf->ysyx_22040000__DOT__state)));
    vlSelf->io_master_arlen = ((1U == (IData)(vlSelf->ysyx_22040000__DOT__state))
                                ? 3U : 0U);
    vlSelf->io_master_rready = ((2U == (IData)(vlSelf->ysyx_22040000__DOT__state)) 
                                | (5U == (IData)(vlSelf->ysyx_22040000__DOT__state)));
    vlSelf->io_master_wdata = vlSelf->ysyx_22040000__DOT__mem_wdata;
    vlSelf->io_master_wstrb = vlSelf->ysyx_22040000__DOT__mem_wstrb;
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
    vlSelf->io_master_awvalid = (6U == (IData)(vlSelf->ysyx_22040000__DOT__state));
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
    vlSelf->io_master_wvalid = vlSelf->io_master_awvalid;
    vlSelf->io_master_araddr = ((4U == (IData)(vlSelf->ysyx_22040000__DOT__state))
                                 ? vlSelf->io_master_awaddr
                                 : vlSelf->ysyx_22040000__DOT__miss_addr);
}

VL_ATTR_COLD void Vysyx_22040000___024root___eval_stl(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_22040000___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22040000___024root___dump_triggers__act(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_22040000___024root___dump_triggers__nba(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_22040000___024root___ctor_var_reset(Vysyx_22040000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_22040000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_22040000___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_interrupt = VL_RAND_RESET_I(1);
    vlSelf->io_master_awready = VL_RAND_RESET_I(1);
    vlSelf->io_master_awvalid = VL_RAND_RESET_I(1);
    vlSelf->io_master_awaddr = VL_RAND_RESET_I(32);
    vlSelf->io_master_awid = VL_RAND_RESET_I(4);
    vlSelf->io_master_awlen = VL_RAND_RESET_I(8);
    vlSelf->io_master_awsize = VL_RAND_RESET_I(3);
    vlSelf->io_master_awburst = VL_RAND_RESET_I(2);
    vlSelf->io_master_wready = VL_RAND_RESET_I(1);
    vlSelf->io_master_wvalid = VL_RAND_RESET_I(1);
    vlSelf->io_master_wdata = VL_RAND_RESET_I(32);
    vlSelf->io_master_wstrb = VL_RAND_RESET_I(4);
    vlSelf->io_master_wlast = VL_RAND_RESET_I(1);
    vlSelf->io_master_bready = VL_RAND_RESET_I(1);
    vlSelf->io_master_bvalid = VL_RAND_RESET_I(1);
    vlSelf->io_master_bresp = VL_RAND_RESET_I(2);
    vlSelf->io_master_bid = VL_RAND_RESET_I(4);
    vlSelf->io_master_arready = VL_RAND_RESET_I(1);
    vlSelf->io_master_arvalid = VL_RAND_RESET_I(1);
    vlSelf->io_master_araddr = VL_RAND_RESET_I(32);
    vlSelf->io_master_arid = VL_RAND_RESET_I(4);
    vlSelf->io_master_arlen = VL_RAND_RESET_I(8);
    vlSelf->io_master_arsize = VL_RAND_RESET_I(3);
    vlSelf->io_master_arburst = VL_RAND_RESET_I(2);
    vlSelf->io_master_rready = VL_RAND_RESET_I(1);
    vlSelf->io_master_rvalid = VL_RAND_RESET_I(1);
    vlSelf->io_master_rresp = VL_RAND_RESET_I(2);
    vlSelf->io_master_rdata = VL_RAND_RESET_I(32);
    vlSelf->io_master_rlast = VL_RAND_RESET_I(1);
    vlSelf->io_master_rid = VL_RAND_RESET_I(4);
    vlSelf->io_slave_awready = VL_RAND_RESET_I(1);
    vlSelf->io_slave_awvalid = VL_RAND_RESET_I(1);
    vlSelf->io_slave_awaddr = VL_RAND_RESET_I(32);
    vlSelf->io_slave_awid = VL_RAND_RESET_I(4);
    vlSelf->io_slave_awlen = VL_RAND_RESET_I(8);
    vlSelf->io_slave_awsize = VL_RAND_RESET_I(3);
    vlSelf->io_slave_awburst = VL_RAND_RESET_I(2);
    vlSelf->io_slave_wready = VL_RAND_RESET_I(1);
    vlSelf->io_slave_wvalid = VL_RAND_RESET_I(1);
    vlSelf->io_slave_wdata = VL_RAND_RESET_I(32);
    vlSelf->io_slave_wstrb = VL_RAND_RESET_I(4);
    vlSelf->io_slave_wlast = VL_RAND_RESET_I(1);
    vlSelf->io_slave_bready = VL_RAND_RESET_I(1);
    vlSelf->io_slave_bvalid = VL_RAND_RESET_I(1);
    vlSelf->io_slave_bresp = VL_RAND_RESET_I(2);
    vlSelf->io_slave_bid = VL_RAND_RESET_I(4);
    vlSelf->io_slave_arready = VL_RAND_RESET_I(1);
    vlSelf->io_slave_arvalid = VL_RAND_RESET_I(1);
    vlSelf->io_slave_araddr = VL_RAND_RESET_I(32);
    vlSelf->io_slave_arid = VL_RAND_RESET_I(4);
    vlSelf->io_slave_arlen = VL_RAND_RESET_I(8);
    vlSelf->io_slave_arsize = VL_RAND_RESET_I(3);
    vlSelf->io_slave_arburst = VL_RAND_RESET_I(2);
    vlSelf->io_slave_rready = VL_RAND_RESET_I(1);
    vlSelf->io_slave_rvalid = VL_RAND_RESET_I(1);
    vlSelf->io_slave_rresp = VL_RAND_RESET_I(2);
    vlSelf->io_slave_rdata = VL_RAND_RESET_I(32);
    vlSelf->io_slave_rlast = VL_RAND_RESET_I(1);
    vlSelf->io_slave_rid = VL_RAND_RESET_I(4);
    vlSelf->ysyx_22040000__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->ysyx_22040000__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__inst_pc = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ysyx_22040000__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_22040000__DOT__csr_mtvec = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__csr_mepc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__csr_mcause = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__mtime = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_22040000__DOT__debug_halt = VL_RAND_RESET_I(1);
    vlSelf->ysyx_22040000__DOT__debug_halt_code = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__cycle_count = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_22040000__DOT__instret_count = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_22040000__DOT__icache_accesses = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_22040000__DOT__icache_misses = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_22040000__DOT__icache_miss_cycles = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_22040000__DOT__ic_valid = VL_RAND_RESET_I(2);
    vlSelf->ysyx_22040000__DOT__ic_tag0 = VL_RAND_RESET_I(27);
    vlSelf->ysyx_22040000__DOT__ic_tag1 = VL_RAND_RESET_I(27);
    vlSelf->ysyx_22040000__DOT__ic0_word0 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__ic0_word1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__ic0_word2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__ic0_word3 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__ic1_word0 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__ic1_word1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__ic1_word2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__ic1_word3 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__miss_addr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__miss_index = VL_RAND_RESET_I(1);
    vlSelf->ysyx_22040000__DOT__miss_tag = VL_RAND_RESET_I(27);
    vlSelf->ysyx_22040000__DOT__miss_word = VL_RAND_RESET_I(2);
    vlSelf->ysyx_22040000__DOT__miss_target_word = VL_RAND_RESET_I(2);
    vlSelf->ysyx_22040000__DOT__miss_saved_inst = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__mem_addr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__mem_wdata = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__mem_wstrb = VL_RAND_RESET_I(4);
    vlSelf->ysyx_22040000__DOT__mem_rd = VL_RAND_RESET_I(5);
    vlSelf->ysyx_22040000__DOT__mem_size = VL_RAND_RESET_I(2);
    vlSelf->ysyx_22040000__DOT__mem_unsigned = VL_RAND_RESET_I(1);
    vlSelf->ysyx_22040000__DOT__alu_a = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__alu_b = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__alu_y = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__tmp_imm = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__tmp_addr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__tmp_old_csr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__tmp_new_csr = VL_RAND_RESET_I(32);
    vlSelf->ysyx_22040000__DOT__tmp_do_write = VL_RAND_RESET_I(1);
    vlSelf->ysyx_22040000__DOT__tmp_take_branch = VL_RAND_RESET_I(1);
    vlSelf->ysyx_22040000__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->ysyx_22040000__DOT__rd = VL_RAND_RESET_I(5);
    vlSelf->ysyx_22040000__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->ysyx_22040000__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_22040000__DOT__rs2 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_22040000__DOT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->ysyx_22040000__DOT__csr_id = VL_RAND_RESET_I(12);
    vlSelf->ysyx_22040000__DOT__if_hit = VL_RAND_RESET_I(1);
    vlSelf->ysyx_22040000__DOT__load_extract__Vstatic__shifted = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
}
