// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VYSYX_22040000__SYMS_H_
#define VERILATED_VYSYX_22040000__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vysyx_22040000.h"

// INCLUDE MODULE CLASSES
#include "Vysyx_22040000___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class Vysyx_22040000__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vysyx_22040000* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vysyx_22040000___024root       TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_ysyx_22040000;

    // CONSTRUCTORS
    Vysyx_22040000__Syms(VerilatedContext* contextp, const char* namep, Vysyx_22040000* modelp);
    ~Vysyx_22040000__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
