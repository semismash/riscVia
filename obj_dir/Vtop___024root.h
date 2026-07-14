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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_OUT8(halt,0,0);
        CData/*0:0*/ top__DOT__write_enable;
        CData/*2:0*/ top__DOT__req_bytes;
        CData/*0:0*/ top__DOT__data_fault;
        CData/*0:0*/ top__DOT__u_cpu__DOT__w_enable;
        CData/*0:0*/ top__DOT__u_cpu__DOT__pc_in1_sel;
        CData/*0:0*/ top__DOT__u_cpu__DOT__pc_in2_sel;
        CData/*0:0*/ top__DOT__u_cpu__DOT__alu_or_mem_to_reg;
        CData/*0:0*/ top__DOT__u_cpu__DOT__imm_to_reg;
        CData/*0:0*/ top__DOT__u_cpu__DOT__illegal_instr;
        CData/*2:0*/ top__DOT__u_cpu__DOT__imm_type;
        CData/*3:0*/ top__DOT__u_cpu__DOT__alu_op;
        CData/*0:0*/ top__DOT__u_cpu__DOT__alu_in1_sel;
        CData/*0:0*/ top__DOT__u_cpu__DOT__alu_in2_sel;
        CData/*0:0*/ top__DOT__u_cpu__DOT__mem_read;
        CData/*0:0*/ top__DOT__u_cpu__DOT__mem_write;
        CData/*6:0*/ top__DOT__u_cpu__DOT__u_decoder__DOT__opcode;
        CData/*2:0*/ top__DOT__u_cpu__DOT__u_decoder__DOT__unnamedblk1__DOT__funct3;
        CData/*3:0*/ __Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__Vfuncout;
        CData/*2:0*/ __Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__funct3;
        CData/*3:0*/ __Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__return_op;
        CData/*3:0*/ __Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__2__Vfuncout;
        CData/*2:0*/ __Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__2__funct3;
        CData/*3:0*/ __Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__2__return_op;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in1_sel__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in2_sel__0;
        CData/*3:0*/ __Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_op__0;
        CData/*2:0*/ __Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__imm_type__0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoDidInit;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in1_sel__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in2_sel__1;
        CData/*3:0*/ __Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_op__1;
        CData/*2:0*/ __Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__imm_type__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        IData/*31:0*/ top__DOT__if_addr;
        IData/*31:0*/ top__DOT__data_addr;
        IData/*31:0*/ top__DOT__write_data;
        IData/*31:0*/ top__DOT__instr;
        IData/*31:0*/ top__DOT__read_data;
        IData/*31:0*/ top__DOT__u_cpu__DOT__reg_write_data;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_reg_file__DOT__i;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__pc;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__pc_next;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_alu__DOT__r_data1;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_alu__DOT__r_data2;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_alu__DOT__imm;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_alu__DOT__alu_out;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_alu__DOT__data1;
        IData/*31:0*/ top__DOT__u_cpu__DOT__u_alu__DOT__data2;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__u_cpu__DOT__u_reg_file__DOT__registers;
    };
    struct {
        VlUnpacked<CData/*7:0*/, 131072> top__DOT__u_mem__DOT__container;
        VlUnpacked<QData/*63:0*/, 2> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;
    };

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
