// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vysyx_22040000__Syms.h"
#include "Vysyx_22040000.h"
#include "Vysyx_22040000___024root.h"

// FUNCTIONS
Vysyx_22040000__Syms::~Vysyx_22040000__Syms()
{
}

Vysyx_22040000__Syms::Vysyx_22040000__Syms(VerilatedContext* contextp, const char* namep, Vysyx_22040000* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_ysyx_22040000.configure(this, name(), "ysyx_22040000", "ysyx_22040000", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_ysyx_22040000.varInsert(__Vfinal,"cycle_count", &(TOP.ysyx_22040000__DOT__cycle_count), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ysyx_22040000.varInsert(__Vfinal,"debug_halt", &(TOP.ysyx_22040000__DOT__debug_halt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ysyx_22040000.varInsert(__Vfinal,"debug_halt_code", &(TOP.ysyx_22040000__DOT__debug_halt_code), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ysyx_22040000.varInsert(__Vfinal,"icache_accesses", &(TOP.ysyx_22040000__DOT__icache_accesses), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ysyx_22040000.varInsert(__Vfinal,"icache_miss_cycles", &(TOP.ysyx_22040000__DOT__icache_miss_cycles), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ysyx_22040000.varInsert(__Vfinal,"icache_misses", &(TOP.ysyx_22040000__DOT__icache_misses), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ysyx_22040000.varInsert(__Vfinal,"instret_count", &(TOP.ysyx_22040000__DOT__instret_count), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
    }
}
