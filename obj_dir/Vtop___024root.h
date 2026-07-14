// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(halt,0,0);
    CData/*0:0*/ top__DOT__write_enable;
    CData/*2:0*/ top__DOT__req_bytes;
    CData/*0:0*/ top__DOT__data_fault;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_18;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_20;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ top__DOT__if_addr;
    IData/*31:0*/ top__DOT__data_addr;
    IData/*31:0*/ top__DOT__write_data;
    IData/*31:0*/ top__DOT__instr;
    IData/*31:0*/ top__DOT__u_cpu__DOT__alu_out;
    IData/*31:0*/ top__DOT__u_cpu__DOT__reg_write_data;
    IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__pc;
    IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__pc_next;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__u_cpu__DOT__u_reg_file__DOT__registers;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__u_mem__DOT__container;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
