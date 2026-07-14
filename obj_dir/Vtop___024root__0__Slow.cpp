// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vinline__eval_static__TOP_top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1;
    __Vinline__eval_static__TOP_top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 = 0;
    IData/*31:0*/ __Vinline__eval_static__TOP_top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2;
    __Vinline__eval_static__TOP_top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 0;
    // Body
    __Vinline__eval_static__TOP_top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 = 0;
    __Vinline__eval_static__TOP_top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 0;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->top__DOT__u_cpu__DOT__u_decoder__DOT__unnamedblk1__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 700192354801459446ull);
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in1_sel__0 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in2_sel__0 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_op__0 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_op;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__imm_type__0 
        = vlSelfRef.top__DOT__u_cpu__DOT__imm_type;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in1_sel__1 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in2_sel__1 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_op__1 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_op;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__imm_type__1 
        = vlSelfRef.top__DOT__u_cpu__DOT__imm_type;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1;
    top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 = 0;
    IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2;
    top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 0;
    // Body
    top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 = 0;
    top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 0;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->top__DOT__u_cpu__DOT__u_decoder__DOT__unnamedblk1__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 700192354801459446ull);
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("src/design\\top.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop___024root___eval_triggers_vec__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[1U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlTriggered[0U] = (QData)((IData)(
                                                    (((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__imm_type) 
                                                        != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__imm_type__0)) 
                                                       << 3U) 
                                                      | (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_op) 
                                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_op__0)) 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel) 
                                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in2_sel__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel) 
                                                           != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in1_sel__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in1_sel__0 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in2_sel__0 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_op__0 
        = vlSelfRef.top__DOT__u_cpu__DOT__alu_op;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__imm_type__0 
        = vlSelfRef.top__DOT__u_cpu__DOT__imm_type;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered[0U] = (1ULL | vlSelfRef.__VstlTriggered[0U]);
        vlSelfRef.__VstlTriggered[0U] = (2ULL | vlSelfRef.__VstlTriggered[0U]);
        vlSelfRef.__VstlTriggered[0U] = (4ULL | vlSelfRef.__VstlTriggered[0U]);
        vlSelfRef.__VstlTriggered[0U] = (8ULL | vlSelfRef.__VstlTriggered[0U]);
    }
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([hybrid] top.u_cpu.alu_in1_sel)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([hybrid] top.u_cpu.alu_in2_sel)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([hybrid] top.u_cpu.alu_op)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([hybrid] top.u_cpu.imm_type)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__if_addr = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc;
    vlSelfRef.top__DOT__instr = 0U;
    if ((0x0001fffcU > vlSelfRef.top__DOT__if_addr)) {
        vlSelfRef.top__DOT__instr = (((((IData)(vlSelfRef.top__DOT__u_mem__DOT__container
                                                [(0x0001ffffU 
                                                  & ((IData)(3U) 
                                                     + vlSelfRef.top__DOT__if_addr))]) 
                                        << 8U) | vlSelfRef.top__DOT__u_mem__DOT__container
                                       [(0x0001ffffU 
                                         & ((IData)(2U) 
                                            + vlSelfRef.top__DOT__if_addr))]) 
                                      << 0x00000010U) 
                                     | (((IData)(vlSelfRef.top__DOT__u_mem__DOT__container
                                                 [(0x0001ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__if_addr))]) 
                                         << 8U) | vlSelfRef.top__DOT__u_mem__DOT__container
                                        [(0x0001ffffU 
                                          & vlSelfRef.top__DOT__if_addr)]));
    }
    vlSelfRef.top__DOT__u_cpu__DOT__rs2_data = (vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
                                                [(0x0000001fU 
                                                  & (vlSelfRef.top__DOT__instr 
                                                     >> 0x00000014U))] 
                                                & (- (IData)(
                                                             (0U 
                                                              != 
                                                              (0x0000001fU 
                                                               & (vlSelfRef.top__DOT__instr 
                                                                  >> 0x00000014U))))));
    vlSelfRef.top__DOT__u_cpu__DOT__rs1_data = (vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
                                                [(0x0000001fU 
                                                  & (vlSelfRef.top__DOT__instr 
                                                     >> 0x0000000fU))] 
                                                & (- (IData)(
                                                             (0U 
                                                              != 
                                                              (0x0000001fU 
                                                               & (vlSelfRef.top__DOT__instr 
                                                                  >> 0x0000000fU))))));
}

void Vtop___024root___ico_comb__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___ico_comb__TOP__3(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[1U])) {
        vlSelfRef.top__DOT__if_addr = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc;
        vlSelfRef.top__DOT__instr = 0U;
        if ((0x0001fffcU > vlSelfRef.top__DOT__if_addr)) {
            vlSelfRef.top__DOT__instr = (((((IData)(vlSelfRef.top__DOT__u_mem__DOT__container
                                                    [
                                                    (0x0001ffffU 
                                                     & ((IData)(3U) 
                                                        + vlSelfRef.top__DOT__if_addr))]) 
                                            << 8U) 
                                           | vlSelfRef.top__DOT__u_mem__DOT__container
                                           [(0x0001ffffU 
                                             & ((IData)(2U) 
                                                + vlSelfRef.top__DOT__if_addr))]) 
                                          << 0x00000010U) 
                                         | (((IData)(vlSelfRef.top__DOT__u_mem__DOT__container
                                                     [
                                                     (0x0001ffffU 
                                                      & ((IData)(1U) 
                                                         + vlSelfRef.top__DOT__if_addr))]) 
                                             << 8U) 
                                            | vlSelfRef.top__DOT__u_mem__DOT__container
                                            [(0x0001ffffU 
                                              & vlSelfRef.top__DOT__if_addr)]));
        }
        vlSelfRef.top__DOT__u_cpu__DOT__rs2_data = 
            (vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
             [(0x0000001fU & (vlSelfRef.top__DOT__instr 
                              >> 0x00000014U))] & (- (IData)(
                                                             (0U 
                                                              != 
                                                              (0x0000001fU 
                                                               & (vlSelfRef.top__DOT__instr 
                                                                  >> 0x00000014U))))));
        vlSelfRef.top__DOT__u_cpu__DOT__rs1_data = 
            (vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
             [(0x0000001fU & (vlSelfRef.top__DOT__instr 
                              >> 0x0000000fU))] & (- (IData)(
                                                             (0U 
                                                              != 
                                                              (0x0000001fU 
                                                               & (vlSelfRef.top__DOT__instr 
                                                                  >> 0x0000000fU))))));
    }
    if (((1ULL & vlSelfRef.__VstlTriggered[1U]) | (8ULL 
                                                   & vlSelfRef.__VstlTriggered[0U]))) {
        Vtop___024root___ico_comb__TOP__0(vlSelf);
    }
    if ((1ULL & (vlSelfRef.__VstlTriggered[1U] | vlSelfRef.__VstlTriggered[0U]))) {
        vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = 
            ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel)
              ? vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc
              : vlSelfRef.top__DOT__u_cpu__DOT__rs1_data);
    }
    if (((1ULL & vlSelfRef.__VstlTriggered[1U]) | (0x000000000000000aULL 
                                                   & vlSelfRef.__VstlTriggered[0U]))) {
        vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = 
            ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel)
              ? vlSelfRef.top__DOT__u_cpu__DOT__imm_val
              : vlSelfRef.top__DOT__u_cpu__DOT__rs2_data);
    }
    if (((1ULL & vlSelfRef.__VstlTriggered[1U]) | (0x000000000000000fULL 
                                                   & vlSelfRef.__VstlTriggered[0U]))) {
        Vtop___024root___ico_comb__TOP__3(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([hybrid] top.u_cpu.alu_in1_sel)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([hybrid] top.u_cpu.alu_in2_sel)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([hybrid] top.u_cpu.alu_op)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([hybrid] top.u_cpu.imm_type)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([hybrid] top.u_cpu.alu_in1_sel)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([hybrid] top.u_cpu.alu_in2_sel)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([hybrid] top.u_cpu.alu_op)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([hybrid] top.u_cpu.imm_type)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->halt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11049222807502041558ull);
    vlSelf->top__DOT__if_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9948625378764159429ull);
    vlSelf->top__DOT__data_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16073976394386819418ull);
    vlSelf->top__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 554206876145221615ull);
    vlSelf->top__DOT__write_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5791377118671855880ull);
    vlSelf->top__DOT__req_bytes = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16775011400878586817ull);
    vlSelf->top__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3126867797622976717ull);
    vlSelf->top__DOT__data_fault = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8167140621540713626ull);
    vlSelf->top__DOT__u_cpu__DOT__w_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1067586700560839279ull);
    vlSelf->top__DOT__u_cpu__DOT__rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14929891142440176797ull);
    vlSelf->top__DOT__u_cpu__DOT__rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1908695070480338884ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_or_mem_to_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12789933475273004143ull);
    vlSelf->top__DOT__u_cpu__DOT__imm_val = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3219742408583586275ull);
    vlSelf->top__DOT__u_cpu__DOT__imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17771432074263927410ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12758967225510099876ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_in1_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15870090315687284172ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_in2_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15916634701875632495ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3482279785517445549ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11728375109217349596ull);
    vlSelf->top__DOT__u_cpu__DOT__reg_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4252256717780325557ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1375488913775379883ull);
    }
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1399258308895884909ull);
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11855832878590989954ull);
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->top__DOT__u_mem__DOT__container[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16390826160958245493ull);
    }
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__2__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__2__funct3 = 0;
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__2__return_op = 0;
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__3__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__3__funct3 = 0;
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__3__return_op = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_1 = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in1_sel__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in2_sel__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_op__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__imm_type__0 = 0;
    vlSelf->__VstlDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in1_sel__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_in2_sel__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__alu_op__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__u_cpu__DOT__imm_type__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = 0;
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
