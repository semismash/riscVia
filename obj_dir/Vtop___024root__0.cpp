// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
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

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0;
    __VdlyVal__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0;
    __VdlyDim0__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0;
    __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v1;
    __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v1 = 0;
    // Body
    __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 = 0U;
    __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v1 = 0U;
    if (vlSelfRef.rst_n) {
        if ((((0x00000040U & vlSelfRef.top__DOT__instr)
               ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14)
               : ((0x00000020U & vlSelfRef.top__DOT__instr)
                   ? ((vlSelfRef.top__DOT__instr >> 4U) 
                      & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6))
                   : ((0x00000010U & vlSelfRef.top__DOT__instr)
                       ? (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_6)
                       : (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_4)))) 
             & (0U != (0x0000001fU & (vlSelfRef.top__DOT__instr 
                                      >> 7U))))) {
            __VdlyVal__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 
                = ((IData)(((0U == (0x00000060U & vlSelfRef.top__DOT__instr)) 
                            & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17)))
                    ? vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data
                    : vlSelfRef.top__DOT__u_cpu__DOT__alu_out);
            __VdlyDim0__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 
                = (0x0000001fU & (vlSelfRef.top__DOT__instr 
                                  >> 7U));
            __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 = 1U;
        }
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc_next;
    } else {
        __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v1 = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc = 0U;
    }
    if (__VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[__VdlyDim0__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0] 
            = __VdlyVal__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0;
    }
    if (__VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v1) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[0U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[1U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[2U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[3U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[4U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[5U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[6U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[7U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[8U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[9U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[10U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[11U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[12U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[13U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[14U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[15U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[16U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[17U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[18U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[19U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[20U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[21U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[22U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[23U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[24U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[25U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[26U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[27U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[28U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[29U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[30U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[31U] = 0U;
    }
    vlSelfRef.top__DOT__if_addr = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __VdlyVal__top__DOT__u_mem__DOT__container__v0;
    __VdlyVal__top__DOT__u_mem__DOT__container__v0 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__u_mem__DOT__container__v0;
    __VdlyDim0__top__DOT__u_mem__DOT__container__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_mem__DOT__container__v0;
    __VdlySet__top__DOT__u_mem__DOT__container__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_mem__DOT__container__v1;
    __VdlyVal__top__DOT__u_mem__DOT__container__v1 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__u_mem__DOT__container__v1;
    __VdlyDim0__top__DOT__u_mem__DOT__container__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_mem__DOT__container__v1;
    __VdlySet__top__DOT__u_mem__DOT__container__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_mem__DOT__container__v2;
    __VdlyVal__top__DOT__u_mem__DOT__container__v2 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__u_mem__DOT__container__v2;
    __VdlyDim0__top__DOT__u_mem__DOT__container__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_mem__DOT__container__v3;
    __VdlyVal__top__DOT__u_mem__DOT__container__v3 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__u_mem__DOT__container__v3;
    __VdlyDim0__top__DOT__u_mem__DOT__container__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_mem__DOT__container__v3;
    __VdlySet__top__DOT__u_mem__DOT__container__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_mem__DOT__container__v4;
    __VdlyVal__top__DOT__u_mem__DOT__container__v4 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__u_mem__DOT__container__v4;
    __VdlyDim0__top__DOT__u_mem__DOT__container__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_mem__DOT__container__v5;
    __VdlyVal__top__DOT__u_mem__DOT__container__v5 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__u_mem__DOT__container__v5;
    __VdlyDim0__top__DOT__u_mem__DOT__container__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_mem__DOT__container__v6;
    __VdlyVal__top__DOT__u_mem__DOT__container__v6 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__u_mem__DOT__container__v6;
    __VdlyDim0__top__DOT__u_mem__DOT__container__v6 = 0;
    // Body
    __VdlySet__top__DOT__u_mem__DOT__container__v0 = 0U;
    __VdlySet__top__DOT__u_mem__DOT__container__v1 = 0U;
    __VdlySet__top__DOT__u_mem__DOT__container__v3 = 0U;
    if (((IData)(vlSelfRef.top__DOT__write_enable) 
         & (~ (IData)(vlSelfRef.top__DOT__data_fault)))) {
        if ((1U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            __VdlyVal__top__DOT__u_mem__DOT__container__v0 
                = (0x000000ffU & vlSelfRef.top__DOT__write_data);
            __VdlyDim0__top__DOT__u_mem__DOT__container__v0 
                = (0x0001ffffU & vlSelfRef.top__DOT__data_addr);
            __VdlySet__top__DOT__u_mem__DOT__container__v0 = 1U;
        } else if ((2U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            __VdlyVal__top__DOT__u_mem__DOT__container__v1 
                = (0x000000ffU & vlSelfRef.top__DOT__write_data);
            __VdlyDim0__top__DOT__u_mem__DOT__container__v1 
                = (0x0001ffffU & vlSelfRef.top__DOT__data_addr);
            __VdlySet__top__DOT__u_mem__DOT__container__v1 = 1U;
            __VdlyVal__top__DOT__u_mem__DOT__container__v2 
                = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                  >> 8U));
            __VdlyDim0__top__DOT__u_mem__DOT__container__v2 
                = (0x0001ffffU & ((IData)(1U) + vlSelfRef.top__DOT__data_addr));
        } else if ((4U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            __VdlyVal__top__DOT__u_mem__DOT__container__v3 
                = (0x000000ffU & vlSelfRef.top__DOT__write_data);
            __VdlyDim0__top__DOT__u_mem__DOT__container__v3 
                = (0x0001ffffU & vlSelfRef.top__DOT__data_addr);
            __VdlySet__top__DOT__u_mem__DOT__container__v3 = 1U;
            __VdlyVal__top__DOT__u_mem__DOT__container__v4 
                = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                  >> 8U));
            __VdlyDim0__top__DOT__u_mem__DOT__container__v4 
                = (0x0001ffffU & ((IData)(1U) + vlSelfRef.top__DOT__data_addr));
            __VdlyVal__top__DOT__u_mem__DOT__container__v5 
                = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                  >> 0x10U));
            __VdlyDim0__top__DOT__u_mem__DOT__container__v5 
                = (0x0001ffffU & ((IData)(2U) + vlSelfRef.top__DOT__data_addr));
            __VdlyVal__top__DOT__u_mem__DOT__container__v6 
                = (vlSelfRef.top__DOT__write_data >> 0x18U);
            __VdlyDim0__top__DOT__u_mem__DOT__container__v6 
                = (0x0001ffffU & ((IData)(3U) + vlSelfRef.top__DOT__data_addr));
        }
    }
    if (__VdlySet__top__DOT__u_mem__DOT__container__v0) {
        vlSelfRef.top__DOT__u_mem__DOT__container[__VdlyDim0__top__DOT__u_mem__DOT__container__v0] 
            = __VdlyVal__top__DOT__u_mem__DOT__container__v0;
    }
    if (__VdlySet__top__DOT__u_mem__DOT__container__v1) {
        vlSelfRef.top__DOT__u_mem__DOT__container[__VdlyDim0__top__DOT__u_mem__DOT__container__v1] 
            = __VdlyVal__top__DOT__u_mem__DOT__container__v1;
        vlSelfRef.top__DOT__u_mem__DOT__container[__VdlyDim0__top__DOT__u_mem__DOT__container__v2] 
            = __VdlyVal__top__DOT__u_mem__DOT__container__v2;
    }
    if (__VdlySet__top__DOT__u_mem__DOT__container__v3) {
        vlSelfRef.top__DOT__u_mem__DOT__container[__VdlyDim0__top__DOT__u_mem__DOT__container__v3] 
            = __VdlyVal__top__DOT__u_mem__DOT__container__v3;
        vlSelfRef.top__DOT__u_mem__DOT__container[__VdlyDim0__top__DOT__u_mem__DOT__container__v4] 
            = __VdlyVal__top__DOT__u_mem__DOT__container__v4;
        vlSelfRef.top__DOT__u_mem__DOT__container[__VdlyDim0__top__DOT__u_mem__DOT__container__v5] 
            = __VdlyVal__top__DOT__u_mem__DOT__container__v5;
        vlSelfRef.top__DOT__u_mem__DOT__container[__VdlyDim0__top__DOT__u_mem__DOT__container__v6] 
            = __VdlyVal__top__DOT__u_mem__DOT__container__v6;
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v0;
    __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v0 = 0;
    IData/*16:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v0;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v0;
    __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v0 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v1;
    __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v1 = 0;
    IData/*16:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v1;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v1 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v1;
    __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v1 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v2;
    __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v2 = 0;
    IData/*16:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v2;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v2 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v3;
    __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v3 = 0;
    IData/*16:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v3;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v3 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v3;
    __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v3 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v4;
    __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v4 = 0;
    IData/*16:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v4;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v4 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v5;
    __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v5 = 0;
    IData/*16:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v5;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v5 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v6;
    __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v6 = 0;
    IData/*16:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v6;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v6 = 0;
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v0 = 0U;
        __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v1 = 0U;
        __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v3 = 0U;
        if (((IData)(vlSelfRef.top__DOT__write_enable) 
             & (~ (IData)(vlSelfRef.top__DOT__data_fault)))) {
            if ((1U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v0 
                    = (0x000000ffU & vlSelfRef.top__DOT__write_data);
                __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v0 
                    = (0x0001ffffU & vlSelfRef.top__DOT__data_addr);
                __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v0 = 1U;
            } else if ((2U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v1 
                    = (0x000000ffU & vlSelfRef.top__DOT__write_data);
                __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v1 
                    = (0x0001ffffU & vlSelfRef.top__DOT__data_addr);
                __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v1 = 1U;
                __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v2 
                    = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                      >> 8U));
                __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v2 
                    = (0x0001ffffU & ((IData)(1U) + vlSelfRef.top__DOT__data_addr));
            } else if ((4U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v3 
                    = (0x000000ffU & vlSelfRef.top__DOT__write_data);
                __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v3 
                    = (0x0001ffffU & vlSelfRef.top__DOT__data_addr);
                __Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v3 = 1U;
                __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v4 
                    = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                      >> 8U));
                __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v4 
                    = (0x0001ffffU & ((IData)(1U) + vlSelfRef.top__DOT__data_addr));
                __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v5 
                    = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                      >> 0x10U));
                __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v5 
                    = (0x0001ffffU & ((IData)(2U) + vlSelfRef.top__DOT__data_addr));
                __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v6 
                    = (vlSelfRef.top__DOT__write_data 
                       >> 0x18U);
                __Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v6 
                    = (0x0001ffffU & ((IData)(3U) + vlSelfRef.top__DOT__data_addr));
            }
        }
        if (__Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v0) {
            vlSelfRef.top__DOT__u_mem__DOT__container[__Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v0] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v0;
        }
        if (__Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v1) {
            vlSelfRef.top__DOT__u_mem__DOT__container[__Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v1] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v1;
            vlSelfRef.top__DOT__u_mem__DOT__container[__Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v2] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v2;
        }
        if (__Vinline__nba_sequent__TOP__1___VdlySet__top__DOT__u_mem__DOT__container__v3) {
            vlSelfRef.top__DOT__u_mem__DOT__container[__Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v3] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v3;
            vlSelfRef.top__DOT__u_mem__DOT__container[__Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v4] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v4;
            vlSelfRef.top__DOT__u_mem__DOT__container[__Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v5] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v5;
            vlSelfRef.top__DOT__u_mem__DOT__container[__Vinline__nba_sequent__TOP__1___VdlyDim0__top__DOT__u_mem__DOT__container__v6] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__top__DOT__u_mem__DOT__container__v6;
        }
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("src/design\\top.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("src/design\\top.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("src/design\\top.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
}
#endif  // VL_DEBUG
