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
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
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
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
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
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ top__DOT__read_data;
    top__DOT__read_data = 0;
    IData/*31:0*/ top__DOT__u_cpu__DOT__rs1_data;
    top__DOT__u_cpu__DOT__rs1_data = 0;
    IData/*31:0*/ top__DOT__u_cpu__DOT__rs2_data;
    top__DOT__u_cpu__DOT__rs2_data = 0;
    IData/*31:0*/ top__DOT__u_cpu__DOT__imm_val;
    top__DOT__u_cpu__DOT__imm_val = 0;
    CData/*2:0*/ top__DOT__u_cpu__DOT__imm_type;
    top__DOT__u_cpu__DOT__imm_type = 0;
    CData/*3:0*/ top__DOT__u_cpu__DOT__alu_op;
    top__DOT__u_cpu__DOT__alu_op = 0;
    CData/*0:0*/ top__DOT__u_cpu__DOT__mem_write;
    top__DOT__u_cpu__DOT__mem_write = 0;
    IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1;
    top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 = 0;
    IData/*31:0*/ top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2;
    top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    CData/*2:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    CData/*2:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_18;
    __VdfgRegularize_h6e95ff9d_0_18 = 0;
    CData/*2:0*/ __VdfgRegularize_h6e95ff9d_0_19;
    __VdfgRegularize_h6e95ff9d_0_19 = 0;
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
    top__DOT__u_cpu__DOT__rs2_data = (vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
                                      [(0x0000001fU 
                                        & (vlSelfRef.top__DOT__instr 
                                           >> 0x00000014U))] 
                                      & (- (IData)(
                                                   (0U 
                                                    != 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.top__DOT__instr 
                                                        >> 0x00000014U))))));
    top__DOT__u_cpu__DOT__rs1_data = (vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
                                      [(0x0000001fU 
                                        & (vlSelfRef.top__DOT__instr 
                                           >> 0x0000000fU))] 
                                      & (- (IData)(
                                                   (0U 
                                                    != 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.top__DOT__instr 
                                                        >> 0x0000000fU))))));
    if ((2U & vlSelfRef.top__DOT__instr)) {
        __VdfgRegularize_h6e95ff9d_0_9 = ((1U & vlSelfRef.top__DOT__instr)
                                           ? 3U : 5U);
        __VdfgRegularize_h6e95ff9d_0_5 = (5U & (- (IData)(
                                                          (1U 
                                                           & (~ vlSelfRef.top__DOT__instr)))));
    } else {
        __VdfgRegularize_h6e95ff9d_0_9 = 5U;
        __VdfgRegularize_h6e95ff9d_0_5 = 5U;
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6 = (IData)(
                                                       (3U 
                                                        == 
                                                        (0x0000000bU 
                                                         & vlSelfRef.top__DOT__instr)));
    __VdfgRegularize_h6e95ff9d_0_7 = (IData)((7U == 
                                              (7U & vlSelfRef.top__DOT__instr)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4 = ((~ 
                                                 (vlSelfRef.top__DOT__instr 
                                                  >> 2U)) 
                                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14 = (IData)(
                                                        ((0x00000020U 
                                                          == 
                                                          (0x00000030U 
                                                           & vlSelfRef.top__DOT__instr)) 
                                                         & (IData)(__VdfgRegularize_h6e95ff9d_0_7)));
    __VdfgRegularize_h6e95ff9d_0_18 = ((~ (vlSelfRef.top__DOT__instr 
                                           >> 3U)) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_7));
    __VdfgRegularize_h6e95ff9d_0_19 = ((8U & vlSelfRef.top__DOT__instr)
                                        ? 5U : ((4U 
                                                 & vlSelfRef.top__DOT__instr)
                                                 ? 5U
                                                 : (IData)(__VdfgRegularize_h6e95ff9d_0_5)));
    if ((0x00000040U & vlSelfRef.top__DOT__instr)) {
        top__DOT__u_cpu__DOT__alu_op = ((- (IData)(
                                                   (1U 
                                                    & (~ 
                                                       (vlSelfRef.top__DOT__instr 
                                                        >> 4U))))) 
                                        & (((0x00004000U 
                                             & vlSelfRef.top__DOT__instr)
                                             ? ((0x00002000U 
                                                 & vlSelfRef.top__DOT__instr)
                                                 ? 0x0cU
                                                 : 0x0dU)
                                             : (4U 
                                                & (- (IData)(
                                                             (1U 
                                                              & (~ 
                                                                 (vlSelfRef.top__DOT__instr 
                                                                  >> 0x0000000dU))))))) 
                                           & ((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.top__DOT__instr 
                                                             >> 5U)))) 
                                              & (- (IData)((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4))))));
        top__DOT__u_cpu__DOT__imm_type = ((0x00000020U 
                                           & vlSelfRef.top__DOT__instr)
                                           ? ((0x00000010U 
                                               & vlSelfRef.top__DOT__instr)
                                               ? (IData)(__VdfgRegularize_h6e95ff9d_0_19)
                                               : ((8U 
                                                   & vlSelfRef.top__DOT__instr)
                                                   ? 
                                                  ((4U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? 
                                                   ((2U 
                                                     & vlSelfRef.top__DOT__instr)
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.top__DOT__instr)
                                                      ? 4U
                                                      : 5U)
                                                     : 5U)
                                                    : 5U)
                                                   : 
                                                  ((4U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? (IData)(__VdfgRegularize_h6e95ff9d_0_5)
                                                    : 
                                                   ((2U 
                                                     & vlSelfRef.top__DOT__instr)
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.top__DOT__instr)
                                                      ? 2U
                                                      : 5U)
                                                     : 5U))))
                                           : 5U);
    } else {
        top__DOT__u_cpu__DOT__alu_op = (((0x00004000U 
                                          & vlSelfRef.top__DOT__instr)
                                          ? ((0x00002000U 
                                              & vlSelfRef.top__DOT__instr)
                                              ? ((0x00001000U 
                                                  & vlSelfRef.top__DOT__instr)
                                                  ? 6U
                                                  : 5U)
                                              : ((0x00001000U 
                                                  & vlSelfRef.top__DOT__instr)
                                                  ? 
                                                 ((0x40000000U 
                                                   & vlSelfRef.top__DOT__instr)
                                                   ? 0x0bU
                                                   : 0x0aU)
                                                  : 4U))
                                          : ((0x00002000U 
                                              & vlSelfRef.top__DOT__instr)
                                              ? ((0x00001000U 
                                                  & vlSelfRef.top__DOT__instr)
                                                  ? 0x0cU
                                                  : 0x0dU)
                                              : ((0x00001000U 
                                                  & vlSelfRef.top__DOT__instr)
                                                  ? 8U
                                                  : 
                                                 (1U 
                                                  & (- (IData)(
                                                               (1U 
                                                                & (vlSelfRef.top__DOT__instr 
                                                                   >> 0x0000001eU)))))))) 
                                        & (- (IData)(
                                                     ((vlSelfRef.top__DOT__instr 
                                                       >> 4U) 
                                                      & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)))));
        top__DOT__u_cpu__DOT__imm_type = ((0x00000020U 
                                           & vlSelfRef.top__DOT__instr)
                                           ? ((0x00000010U 
                                               & vlSelfRef.top__DOT__instr)
                                               ? ((8U 
                                                   & vlSelfRef.top__DOT__instr)
                                                   ? 5U
                                                   : 
                                                  ((4U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? (IData)(__VdfgRegularize_h6e95ff9d_0_9)
                                                    : 5U))
                                               : ((8U 
                                                   & vlSelfRef.top__DOT__instr)
                                                   ? 5U
                                                   : 
                                                  ((4U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? 5U
                                                    : 
                                                   ((2U 
                                                     & vlSelfRef.top__DOT__instr)
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.top__DOT__instr)
                                                      ? 1U
                                                      : 5U)
                                                     : 5U))))
                                           : ((0x00000010U 
                                               & vlSelfRef.top__DOT__instr)
                                               ? ((8U 
                                                   & vlSelfRef.top__DOT__instr)
                                                   ? 5U
                                                   : 
                                                  ((4U 
                                                    & vlSelfRef.top__DOT__instr)
                                                    ? (IData)(__VdfgRegularize_h6e95ff9d_0_9)
                                                    : (IData)(__VdfgRegularize_h6e95ff9d_0_5)))
                                               : (IData)(__VdfgRegularize_h6e95ff9d_0_19)));
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17 = ((~ 
                                                  (vlSelfRef.top__DOT__instr 
                                                   >> 4U)) 
                                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4));
    __VdfgRegularize_h6e95ff9d_0_0 = (((0x00000040U 
                                        & vlSelfRef.top__DOT__instr)
                                        ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14)
                                        : (IData)((
                                                   (0x00000010U 
                                                    == 
                                                    (0x00000030U 
                                                     & vlSelfRef.top__DOT__instr)) 
                                                   & (IData)(__VdfgRegularize_h6e95ff9d_0_18))))
                                       ? vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc
                                       : top__DOT__u_cpu__DOT__rs1_data);
    top__DOT__u_cpu__DOT__mem_write = (IData)(((0x00000020U 
                                                == 
                                                (0x00000060U 
                                                 & vlSelfRef.top__DOT__instr)) 
                                               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17)));
    top__DOT__u_cpu__DOT__imm_val = ((4U & (IData)(top__DOT__u_cpu__DOT__imm_type))
                                      ? ((- (IData)(
                                                    (1U 
                                                     & (~ (IData)(top__DOT__u_cpu__DOT__imm_type))))) 
                                         & ((((- (IData)(
                                                         (vlSelfRef.top__DOT__instr 
                                                          >> 0x0000001fU))) 
                                              << 0x00000014U) 
                                             | ((((0x000001feU 
                                                   & (vlSelfRef.top__DOT__instr 
                                                      >> 0x0000000bU)) 
                                                  | (1U 
                                                     & (vlSelfRef.top__DOT__instr 
                                                        >> 0x00000014U))) 
                                                 << 0x0000000bU) 
                                                | (0x000007feU 
                                                   & (vlSelfRef.top__DOT__instr 
                                                      >> 0x00000014U)))) 
                                            & (- (IData)(
                                                         (1U 
                                                          & (~ 
                                                             ((IData)(top__DOT__u_cpu__DOT__imm_type) 
                                                              >> 1U)))))))
                                      : ((2U & (IData)(top__DOT__u_cpu__DOT__imm_type))
                                          ? ((1U & (IData)(top__DOT__u_cpu__DOT__imm_type))
                                              ? (0xfffff000U 
                                                 & vlSelfRef.top__DOT__instr)
                                              : (((- (IData)(
                                                             (vlSelfRef.top__DOT__instr 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | ((0x00000800U 
                                                     & (vlSelfRef.top__DOT__instr 
                                                        << 4U)) 
                                                    | ((0x000007e0U 
                                                        & (vlSelfRef.top__DOT__instr 
                                                           >> 0x00000014U)) 
                                                       | (0x0000001eU 
                                                          & (vlSelfRef.top__DOT__instr 
                                                             >> 7U))))))
                                          : (((- (IData)(
                                                         (vlSelfRef.top__DOT__instr 
                                                          >> 0x0000001fU))) 
                                              << 0x0000000bU) 
                                             | (0x000007ffU 
                                                & ((1U 
                                                    & (IData)(top__DOT__u_cpu__DOT__imm_type))
                                                    ? 
                                                   ((0x000007e0U 
                                                     & (vlSelfRef.top__DOT__instr 
                                                        >> 0x00000014U)) 
                                                    | (0x0000001fU 
                                                       & (vlSelfRef.top__DOT__instr 
                                                          >> 7U)))
                                                    : 
                                                   (vlSelfRef.top__DOT__instr 
                                                    >> 0x00000014U))))));
    vlSelfRef.top__DOT__write_enable = 0U;
    vlSelfRef.top__DOT__req_bytes = 0U;
    __VdfgRegularize_h6e95ff9d_0_1 = ((1U & ((0x00000040U 
                                              & vlSelfRef.top__DOT__instr)
                                              ? (1U 
                                                 & ((0x00000030U 
                                                     != 
                                                     (0x0000003cU 
                                                      & vlSelfRef.top__DOT__instr)) 
                                                    | (~ 
                                                       (3U 
                                                        == 
                                                        (3U 
                                                         & vlSelfRef.top__DOT__instr)))))
                                              : (1U 
                                                 & ((0x00000030U 
                                                     != 
                                                     (0x00000038U 
                                                      & vlSelfRef.top__DOT__instr)) 
                                                    | (~ 
                                                       (3U 
                                                        == 
                                                        (3U 
                                                         & vlSelfRef.top__DOT__instr)))))))
                                       ? top__DOT__u_cpu__DOT__imm_val
                                       : top__DOT__u_cpu__DOT__rs2_data);
    vlSelfRef.top__DOT__u_cpu__DOT__alu_out = ((8U 
                                                & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                ? (
                                                   (4U 
                                                    & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                    ? 
                                                   (((1U 
                                                      & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                      ? 
                                                     (1U 
                                                      & (- (IData)(
                                                                   VL_LTS_III(32, __VdfgRegularize_h6e95ff9d_0_0, __VdfgRegularize_h6e95ff9d_0_1))))
                                                      : 
                                                     (1U 
                                                      & (- (IData)(
                                                                   (__VdfgRegularize_h6e95ff9d_0_0 
                                                                    < __VdfgRegularize_h6e95ff9d_0_1))))) 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (~ 
                                                                     ((IData)(top__DOT__u_cpu__DOT__alu_op) 
                                                                      >> 1U))))))
                                                    : 
                                                   ((2U 
                                                     & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, __VdfgRegularize_h6e95ff9d_0_0, 
                                                                    (0x0000001fU 
                                                                     & __VdfgRegularize_h6e95ff9d_0_1))
                                                      : 
                                                     (__VdfgRegularize_h6e95ff9d_0_0 
                                                      >> 
                                                      (0x0000001fU 
                                                       & __VdfgRegularize_h6e95ff9d_0_1)))
                                                     : 
                                                    ((__VdfgRegularize_h6e95ff9d_0_0 
                                                      << 
                                                      (0x0000001fU 
                                                       & __VdfgRegularize_h6e95ff9d_0_1)) 
                                                     & (- (IData)(
                                                                  (1U 
                                                                   & (~ (IData)(top__DOT__u_cpu__DOT__alu_op))))))))
                                                : (
                                                   (4U 
                                                    & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                     ? 
                                                    (__VdfgRegularize_h6e95ff9d_0_0 
                                                     & (__VdfgRegularize_h6e95ff9d_0_1 
                                                        & (- (IData)(
                                                                     (1U 
                                                                      & (~ (IData)(top__DOT__u_cpu__DOT__alu_op)))))))
                                                     : 
                                                    ((1U 
                                                      & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                      ? 
                                                     (__VdfgRegularize_h6e95ff9d_0_0 
                                                      | __VdfgRegularize_h6e95ff9d_0_1)
                                                      : 
                                                     (__VdfgRegularize_h6e95ff9d_0_0 
                                                      ^ __VdfgRegularize_h6e95ff9d_0_1)))
                                                    : 
                                                   (((1U 
                                                      & (IData)(top__DOT__u_cpu__DOT__alu_op))
                                                      ? 
                                                     (__VdfgRegularize_h6e95ff9d_0_0 
                                                      - __VdfgRegularize_h6e95ff9d_0_1)
                                                      : 
                                                     (__VdfgRegularize_h6e95ff9d_0_0 
                                                      + __VdfgRegularize_h6e95ff9d_0_1)) 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (~ 
                                                                     ((IData)(top__DOT__u_cpu__DOT__alu_op) 
                                                                      >> 1U))))))));
    top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
        = ((IData)(((0x00000060U == (0x00000070U & vlSelfRef.top__DOT__instr)) 
                    & (IData)(__VdfgRegularize_h6e95ff9d_0_18)))
            ? top__DOT__u_cpu__DOT__rs1_data : vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc);
    top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 
        = ((IData)(((0x00000060U == (0x00000070U & vlSelfRef.top__DOT__instr)) 
                    & ((8U & vlSelfRef.top__DOT__instr)
                        ? (IData)(__VdfgRegularize_h6e95ff9d_0_7)
                        : ((4U & vlSelfRef.top__DOT__instr)
                            ? (3U == (3U & vlSelfRef.top__DOT__instr))
                            : (((0x00004000U & vlSelfRef.top__DOT__instr)
                                 ? ((0x00001000U & vlSelfRef.top__DOT__instr)
                                     ? (0U == vlSelfRef.top__DOT__u_cpu__DOT__alu_out)
                                     : (0U != vlSelfRef.top__DOT__u_cpu__DOT__alu_out))
                                 : ((~ (vlSelfRef.top__DOT__instr 
                                        >> 0x0000000dU)) 
                                    & ((0x00001000U 
                                        & vlSelfRef.top__DOT__instr)
                                        ? (0U != vlSelfRef.top__DOT__u_cpu__DOT__alu_out)
                                        : (0U == vlSelfRef.top__DOT__u_cpu__DOT__alu_out)))) 
                               & (3U == (3U & vlSelfRef.top__DOT__instr)))))))
            ? top__DOT__u_cpu__DOT__imm_val : 4U);
    vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc_next 
        = (top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
           + top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2);
    vlSelfRef.top__DOT__data_addr = vlSelfRef.top__DOT__u_cpu__DOT__alu_out;
    vlSelfRef.top__DOT__data_fault = 0U;
    if (top__DOT__u_cpu__DOT__mem_write) {
        vlSelfRef.top__DOT__write_enable = 1U;
        if ((0U == (7U & (vlSelfRef.top__DOT__instr 
                          >> 0x0cU)))) {
            vlSelfRef.top__DOT__req_bytes = 1U;
        } else if ((1U == (7U & (vlSelfRef.top__DOT__instr 
                                 >> 0x0cU)))) {
            vlSelfRef.top__DOT__req_bytes = 2U;
        } else if ((2U == (7U & (vlSelfRef.top__DOT__instr 
                                 >> 0x0cU)))) {
            vlSelfRef.top__DOT__req_bytes = 4U;
        }
    } else if ((0x00004000U & vlSelfRef.top__DOT__instr)) {
        if ((1U & (~ (vlSelfRef.top__DOT__instr >> 0x0000000dU)))) {
            vlSelfRef.top__DOT__req_bytes = ((0x00001000U 
                                              & vlSelfRef.top__DOT__instr)
                                              ? 2U : 1U);
        }
    } else if ((0x00002000U & vlSelfRef.top__DOT__instr)) {
        if ((1U & (~ (vlSelfRef.top__DOT__instr >> 0x0000000cU)))) {
            vlSelfRef.top__DOT__req_bytes = 4U;
        }
    } else {
        vlSelfRef.top__DOT__req_bytes = ((0x00001000U 
                                          & vlSelfRef.top__DOT__instr)
                                          ? 2U : 1U);
    }
    if ((0x00020000U < (vlSelfRef.top__DOT__data_addr 
                        + (IData)(vlSelfRef.top__DOT__req_bytes)))) {
        vlSelfRef.top__DOT__data_fault = 1U;
    } else if ((1U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
        if ((2U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
            if ((4U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
                vlSelfRef.top__DOT__data_fault = 1U;
            }
        }
    }
    top__DOT__read_data = 0U;
    if ((0x00020000U >= (vlSelfRef.top__DOT__data_addr 
                         + (IData)(vlSelfRef.top__DOT__req_bytes)))) {
        if ((1U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            top__DOT__read_data = vlSelfRef.top__DOT__u_mem__DOT__container
                [(0x0001ffffU & vlSelfRef.top__DOT__data_addr)];
        } else if ((2U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            top__DOT__read_data = ((vlSelfRef.top__DOT__u_mem__DOT__container
                                    [(0x0001ffffU & 
                                      ((IData)(1U) 
                                       + vlSelfRef.top__DOT__data_addr))] 
                                    << 8U) | vlSelfRef.top__DOT__u_mem__DOT__container
                                   [(0x0001ffffU & vlSelfRef.top__DOT__data_addr)]);
        } else if ((4U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            top__DOT__read_data = (((((IData)(vlSelfRef.top__DOT__u_mem__DOT__container
                                              [(0x0001ffffU 
                                                & ((IData)(3U) 
                                                   + vlSelfRef.top__DOT__data_addr))]) 
                                      << 8U) | vlSelfRef.top__DOT__u_mem__DOT__container
                                     [(0x0001ffffU 
                                       & ((IData)(2U) 
                                          + vlSelfRef.top__DOT__data_addr))]) 
                                    << 0x00000010U) 
                                   | (((IData)(vlSelfRef.top__DOT__u_mem__DOT__container
                                               [(0x0001ffffU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.top__DOT__data_addr))]) 
                                       << 8U) | vlSelfRef.top__DOT__u_mem__DOT__container
                                      [(0x0001ffffU 
                                        & vlSelfRef.top__DOT__data_addr)]));
        }
    }
    vlSelfRef.halt = ((IData)(vlSelfRef.top__DOT__data_fault) 
                      | (0x0001fffcU <= vlSelfRef.top__DOT__if_addr));
    vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data = 0U;
    if ((1U & (~ (IData)(top__DOT__u_cpu__DOT__mem_write)))) {
        if ((0x00004000U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 0x0000000dU)))) {
                vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                    = ((0x00001000U & vlSelfRef.top__DOT__instr)
                        ? (0x0000ffffU & top__DOT__read_data)
                        : (0x000000ffU & top__DOT__read_data));
            }
        } else if ((0x00002000U & vlSelfRef.top__DOT__instr)) {
            if ((1U & (~ (vlSelfRef.top__DOT__instr 
                          >> 0x0000000cU)))) {
                vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                    = top__DOT__read_data;
            }
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                = ((0x00001000U & vlSelfRef.top__DOT__instr)
                    ? (((- (IData)((1U & (top__DOT__read_data 
                                          >> 0x0fU)))) 
                        << 0x00000010U) | (0x0000ffffU 
                                           & top__DOT__read_data))
                    : (((- (IData)((1U & (top__DOT__read_data 
                                          >> 7U)))) 
                        << 8U) | (0x000000ffU & top__DOT__read_data)));
        }
    }
    vlSelfRef.top__DOT__write_data = 0U;
    if (top__DOT__u_cpu__DOT__mem_write) {
        if ((0U == (7U & (vlSelfRef.top__DOT__instr 
                          >> 0x0cU)))) {
            vlSelfRef.top__DOT__write_data = (0x000000ffU 
                                              & top__DOT__u_cpu__DOT__rs2_data);
        } else if ((1U == (7U & (vlSelfRef.top__DOT__instr 
                                 >> 0x0cU)))) {
            vlSelfRef.top__DOT__write_data = (0x0000ffffU 
                                              & top__DOT__u_cpu__DOT__rs2_data);
        } else if ((2U == (7U & (vlSelfRef.top__DOT__instr 
                                 >> 0x0cU)))) {
            vlSelfRef.top__DOT__write_data = top__DOT__read_data;
        }
    }
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
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

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
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
    vlSelf->top__DOT__u_cpu__DOT__alu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3482279785517445549ull);
    vlSelf->top__DOT__u_cpu__DOT__reg_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4252256717780325557ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1375488913775379883ull);
    }
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1399258308895884909ull);
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11855832878590989954ull);
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->top__DOT__u_mem__DOT__container[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16390826160958245493ull);
    }
    vlSelf->__VdfgRegularize_h6e95ff9d_0_4 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_6 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_14 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_17 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
