// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_22040000.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_22040000__Syms.h"
#include "Vysyx_22040000___024root.h"

void Vysyx_22040000___024root___ctor_var_reset(Vysyx_22040000___024root* vlSelf);

Vysyx_22040000___024root::Vysyx_22040000___024root(Vysyx_22040000__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vysyx_22040000___024root___ctor_var_reset(this);
}

void Vysyx_22040000___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vysyx_22040000___024root::~Vysyx_22040000___024root() {
}
