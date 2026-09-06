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
    IData/*31:0*/ __VExpandSel_WordIdx_1;
    IData/*31:0*/ __VExpandSel_LoShift_1;
    CData/*0:0*/ __VExpandSel_Aligned_1;
    IData/*31:0*/ __VExpandSel_HiShift_1;
    IData/*31:0*/ __VExpandSel_HiMask_1;
    IData/*31:0*/ __VExpandSel_WordIdx_2;
    IData/*31:0*/ __VExpandSel_LoShift_2;
    CData/*0:0*/ __VExpandSel_Aligned_2;
    IData/*31:0*/ __VExpandSel_HiShift_2;
    IData/*31:0*/ __VExpandSel_HiMask_2;
    // Body
    vlSelfRef.top__DOT__data_fault = 0U;
    vlSelfRef.top__DOT__read_data = 0U;
    if ((0U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
        if ((0x00010000U < (vlSelfRef.top__DOT__data_addr 
                            + (IData)(vlSelfRef.top__DOT__req_bytes)))) {
            vlSelfRef.top__DOT__data_fault = 1U;
        } else if ((1U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
            if ((2U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
                if ((4U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
                    vlSelfRef.top__DOT__data_fault = 1U;
                }
            }
        }
        if ((0x00010000U >= (vlSelfRef.top__DOT__data_addr 
                             + (IData)(vlSelfRef.top__DOT__req_bytes)))) {
            if ((1U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                vlSelfRef.top__DOT__read_data = vlSelfRef.top__DOT__u_data_mem__DOT__container
                    [(0x0000ffffU & vlSelfRef.top__DOT__data_addr)];
            } else if ((2U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                vlSelfRef.top__DOT__read_data = ((vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                  [
                                                  (0x0000ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__data_addr))] 
                                                  << 8U) 
                                                 | vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                 [(0x0000ffffU 
                                                   & vlSelfRef.top__DOT__data_addr)]);
            } else if ((4U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                vlSelfRef.top__DOT__read_data = (((
                                                   ((IData)(vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                            [
                                                            (0x0000ffffU 
                                                             & ((IData)(3U) 
                                                                + vlSelfRef.top__DOT__data_addr))]) 
                                                    << 8U) 
                                                   | vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                   [
                                                   (0x0000ffffU 
                                                    & ((IData)(2U) 
                                                       + vlSelfRef.top__DOT__data_addr))]) 
                                                  << 0x00000010U) 
                                                 | (((IData)(vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                             [
                                                             (0x0000ffffU 
                                                              & ((IData)(1U) 
                                                                 + vlSelfRef.top__DOT__data_addr))]) 
                                                     << 8U) 
                                                    | vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                    [
                                                    (0x0000ffffU 
                                                     & vlSelfRef.top__DOT__data_addr)]));
            }
        }
    }
    vlSelfRef.top__DOT__instr = 0U;
    if ((0x0000fffcU > vlSelfRef.top__DOT__if_addr)) {
        vlSelfRef.top__DOT__instr = (((((IData)(vlSelfRef.top__DOT__u_instr_mem__DOT__container
                                                [(0x0000ffffU 
                                                  & ((IData)(3U) 
                                                     + vlSelfRef.top__DOT__if_addr))]) 
                                        << 8U) | vlSelfRef.top__DOT__u_instr_mem__DOT__container
                                       [(0x0000ffffU 
                                         & ((IData)(2U) 
                                            + vlSelfRef.top__DOT__if_addr))]) 
                                      << 0x00000010U) 
                                     | (((IData)(vlSelfRef.top__DOT__u_instr_mem__DOT__container
                                                 [(0x0000ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__if_addr))]) 
                                         << 8U) | vlSelfRef.top__DOT__u_instr_mem__DOT__container
                                        [(0x0000ffffU 
                                          & vlSelfRef.top__DOT__if_addr)]));
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index 
        = (0x000000ffU & (vlSelfRef.top__DOT__if_addr 
                          >> 2U));
    vlSelfRef.halt = ((0x0000fffcU <= vlSelfRef.top__DOT__if_addr) 
                      | ((IData)(vlSelfRef.top__DOT__data_fault) 
                         | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr)));
    vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
        = vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_result;
    if (vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_read) {
        if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3) 
                          >> 1U)))) {
                vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                    = ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))
                        ? (0x0000ffffU & vlSelfRef.top__DOT__read_data)
                        : (0x000000ffU & vlSelfRef.top__DOT__read_data));
            }
        } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3)))) {
                vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                    = vlSelfRef.top__DOT__read_data;
            }
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                = ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))
                    ? (((- (IData)((1U & (vlSelfRef.top__DOT__read_data 
                                          >> 0x0fU)))) 
                        << 0x00000010U) | (0x0000ffffU 
                                           & vlSelfRef.top__DOT__read_data))
                    : (((- (IData)((1U & (vlSelfRef.top__DOT__read_data 
                                          >> 7U)))) 
                        << 8U) | (0x000000ffU & vlSelfRef.top__DOT__read_data)));
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out 
        = (0x000000ffU & (((0U == (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                                  << 3U)))
                            ? 0U : (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table
                                    [(((IData)(7U) 
                                       + ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                          << 3U)) >> 5U)] 
                                    << ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                              << 3U))))) 
                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table
                             [(0x07ffffffU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                              >> 2U))] 
                             >> (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                                << 3U)))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data = 0ULL;
    __VExpandSel_WordIdx_1 = (0x000007ffU & (((IData)(0x000000d7U) 
                                              * (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index)) 
                                             >> 5U));
    __VExpandSel_LoShift_1 = (0x0000001fU & ((IData)(0x000000d7U) 
                                             * (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index)));
    __VExpandSel_Aligned_1 = (0U == __VExpandSel_LoShift_1);
    if (__VExpandSel_Aligned_1) {
        __VExpandSel_HiShift_1 = 0U;
        __VExpandSel_HiMask_1 = 0U;
    } else {
        __VExpandSel_HiShift_1 = ((IData)(0x00000020U) 
                                  - __VExpandSel_LoShift_1);
        __VExpandSel_HiMask_1 = 0xffffffffU;
    }
    if ((0xd6ffU >= (0x0000ffffU & ((IData)(0x000000d7U) 
                                    * (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index))))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [__VExpandSel_WordIdx_1] >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U] 
            = (0x007fffffU & (((((0x000006b1U <= __VExpandSel_WordIdx_1)
                                  ? 0U : vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                                 [((IData)(7U) + __VExpandSel_WordIdx_1)]) 
                                << __VExpandSel_HiShift_1) 
                               & __VExpandSel_HiMask_1) 
                              | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                                 [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                                 >> __VExpandSel_LoShift_1)));
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U] = 0U;
    }
    __VExpandSel_WordIdx_2 = (0x000007ffU & (((IData)(0x000000d7U) 
                                              * (0x000000ffU 
                                                 & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                                    >> 2U))) 
                                             >> 5U));
    __VExpandSel_LoShift_2 = (0x0000001fU & ((IData)(0x000000d7U) 
                                             * (0x000000ffU 
                                                & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                                   >> 2U))));
    __VExpandSel_Aligned_2 = (0U == __VExpandSel_LoShift_2);
    if (__VExpandSel_Aligned_2) {
        __VExpandSel_HiShift_2 = 0U;
        __VExpandSel_HiMask_2 = 0U;
    } else {
        __VExpandSel_HiShift_2 = ((IData)(0x00000020U) 
                                  - __VExpandSel_LoShift_2);
        __VExpandSel_HiMask_2 = 0xffffffffU;
    }
    if ((0xd6ffU >= (0x0000ffffU & ((IData)(0x000000d7U) 
                                    * (0x000000ffU 
                                       & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                          >> 2U)))))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(1U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [__VExpandSel_WordIdx_2] >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[1U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(2U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(1U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[2U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(3U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(2U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[3U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(4U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(3U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[4U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(5U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(4U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[5U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(6U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(5U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[6U] 
            = (0x007fffffU & (((((0x000006b1U <= __VExpandSel_WordIdx_2)
                                  ? 0U : vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                                 [((IData)(7U) + __VExpandSel_WordIdx_2)]) 
                                << __VExpandSel_HiShift_2) 
                               & __VExpandSel_HiMask_2) 
                              | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                                 [((IData)(6U) + __VExpandSel_WordIdx_2)] 
                                 >> __VExpandSel_LoShift_2)));
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[1U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[2U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[3U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[4U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[5U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[6U] = 0U;
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[1U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[2U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[3U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[4U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[5U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[6U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
        = (((QData)((IData)(((vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                              + vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val) 
                             >> 2U))) << 0x00000017U) 
           | (QData)((IData)((1U | (0x007ffffeU & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                                   >> 9U))))));
    if ((1U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U])) {
        if ((4U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U])) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                = ((3U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U]) 
                   | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                      << 2U));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U] 
                = (0x007fffffU & (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                                   >> 0x0000001eU) 
                                  | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                                              >> 0x00000020U)) 
                                     << 2U)));
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                = ((0x00001fffU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U]) 
                   | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                      << 0x0000000dU));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
                = (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                    >> 0x00000013U) | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                                                >> 0x00000020U)) 
                                       << 0x0000000dU));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                = ((0xfffffffcU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U]) 
                   | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                               >> 0x00000020U)) >> 0x00000013U));
        }
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
            = ((0xfffffffbU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U]) 
               | (4U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                            >> 2U)) << 2U)));
    } else {
        if ((2U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U])) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                = ((0x00ffffffU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U]) 
                   | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                      << 0x00000018U));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
                = (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                    >> 8U) | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                                       >> 0x00000020U)) 
                              << 0x00000018U));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                = ((0xffffe000U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U]) 
                   | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                               >> 0x00000020U)) >> 8U));
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                = ((7U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U]) 
                   | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                      << 3U));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                = ((0xff000000U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U]) 
                   | (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                       >> 0x0000001dU) | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                                                   >> 0x00000020U)) 
                                          << 3U)));
        }
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
            = ((0xfffffffdU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U]) 
               | (2U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                            >> 1U)) << 1U)));
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
        = ((0xfffffffeU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U]) 
           | (1U & (~ vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U])));
    if (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
         == (0x000000ffU & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                            >> 2U)))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq 
            = ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                               >> 4U)) == (vlSelfRef.top__DOT__if_addr 
                                           >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq 
            = ((0x003fffffU & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
                                << 7U) | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                                          >> 0x00000019U))) 
               == (vlSelfRef.top__DOT__if_addr >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq 
            = ((0x003fffffU & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
                                << 0x00000012U) | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                                                   >> 0x0000000eU))) 
               == (vlSelfRef.top__DOT__if_addr >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq 
            = ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                               >> 3U)) == (vlSelfRef.top__DOT__if_addr 
                                           >> 0x0000000aU));
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq 
            = ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                               >> 4U)) == (vlSelfRef.top__DOT__if_addr 
                                           >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq 
            = ((0x003fffffU & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] 
                                << 7U) | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] 
                                          >> 0x00000019U))) 
               == (vlSelfRef.top__DOT__if_addr >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq 
            = ((0x003fffffU & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] 
                                << 0x00000012U) | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] 
                                                   >> 0x0000000eU))) 
               == (vlSelfRef.top__DOT__if_addr >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq 
            = ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
                               >> 3U)) == (vlSelfRef.top__DOT__if_addr 
                                           >> 0x0000000aU));
    }
    if (((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq) 
           | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq)) 
          | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq)) 
         | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
            = ((0xfffffffeU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
               | (1U & (~ vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U])));
        if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                    ? (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                                           << 6U) | 
                                          (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                                           >> 0x0000001aU)))))
                    : (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] 
                                           << 6U) | 
                                          (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                           >> 0x0000001aU))))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffdU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (2U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 1U)) << 1U)));
        } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                    ? (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                                           << 0x00000011U) 
                                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
                                             >> 0x0000000fU)))))
                    : (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] 
                                           << 0x00000011U) 
                                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] 
                                             >> 0x0000000fU))))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffdU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (2U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 1U)) << 1U)));
        } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                    ? (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                                           << 0x0000001cU) 
                                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
                                             >> 4U)))))
                    : (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
                                           << 0x0000001cU) 
                                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] 
                                             >> 4U))))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffbU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (4U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 2U)) << 2U)));
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                    ? (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U] 
                                           << 7U) | 
                                          (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                                           >> 0x00000019U)))))
                    : (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U] 
                                           << 7U) | 
                                          (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
                                           >> 0x00000019U))))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffbU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (4U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 2U)) << 2U)));
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__conf_state 
        = (3U & ((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history) 
                   == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out)) 
                  & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite))
                  ? (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__new_write_entry)
                  : (((0U == (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                             << 1U)))
                       ? 0U : (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table
                               [(((IData)(1U) + ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                                 << 1U)) 
                                 >> 5U)] << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                                   << 1U))))) 
                     | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table
                        [(0x07ffffffU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                         >> 4U))] >> 
                        (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                        << 1U))))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_branch_eval__DOT__take_branch 
        = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit) 
           & ((3U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__conf_state)) 
              | (2U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__conf_state))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__opcode 
        = (0x0000007fU & vlSelfRef.top__DOT__instr);
    vlSelfRef.top__DOT__u_cpu__DOT__bp_is_branch = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__bp_btb_hit = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__bp_pc_addr = ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__if_addr);
    if ((0x63U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__opcode))) {
        vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_branch_eval__DOT__take_branch;
        vlSelfRef.top__DOT__u_cpu__DOT__bp_is_branch = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__bp_btb_hit 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit;
        if (vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken) {
            vlSelfRef.top__DOT__u_cpu__DOT__bp_pc_addr 
                = ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                            >> 0x00000017U)) << 2U);
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bh_shift 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__bp_is_branch));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index 
        = (0x000000ffU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite)
                           ? (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                              >> 2U) : (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index)));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__cur_write_bhr 
        = (0x000000ffU & (((0U == (0x0000001fU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U)))
                            ? 0U : (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table
                                    [(((IData)(7U) 
                                       + (0x000007ffU 
                                          & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U))) 
                                      >> 5U)] << ((IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U))))) 
                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table
                             [(0x0000003fU & (VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U) 
                                              >> 5U))] 
                             >> (0x0000001fU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U)))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__new_write_bhr 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__cur_write_bhr;
    if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__new_write_bhr 
            = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history;
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bh_shift) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__new_write_bhr 
            = ((((~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite)) 
                 & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_branch_eval__DOT__take_branch)) 
                << 7U) | (0x0000007fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__cur_write_bhr) 
                                         >> 1U)));
    }
    if (vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi) {
        if (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc_in1_sel) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_data;
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__imm_in;
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc;
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__imm_in;
        }
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
            = vlSelfRef.top__DOT__u_cpu__DOT__bp_pc_addr;
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 0U;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc;
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 4U;
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc_next 
        = (0xfffffffeU & (vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                          + vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2));
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
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

extern const VlWide<64>/*2047:0*/ Vtop__ConstPool__CONST_h6be9aa18_0;
extern const VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_h93e1b771_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vtop__ConstPool__TABLE_h50f0aed2_0;

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
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
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__i = 0x00000020U;
    }
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc_in1_sel 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__pc_in1_sel));
    vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_to_reg 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_to_reg));
    vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_write 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_write));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_btb_hit = 
        ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
         && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__if_id_btb_hit));
    vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_read 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_read));
    vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__stop_signal 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_stop));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_taken_predict 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__if_id_br_taken_predict));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_bypass 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_bypass));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_in2_roi 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_in1_ropc 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_to_reg 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__imm_to_reg));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_jal = 
        ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
         && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__d_is_jal));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_jalr = 
        ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
         && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__d_is_jalr));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_branch 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__d_is_branch));
    if ((1U & ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_id_ex__DOT__o_opcode = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_addr = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_addr = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_data = 0U;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_id_ex__DOT__o_opcode 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_id_ex__DOT__i_opcode;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_addr 
            = (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                              >> 0x00000014U));
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_addr 
            = (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                              >> 0x0000000fU));
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op 
            = vlSelfRef.top__DOT__u_cpu__DOT__alu_op;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val 
            = ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type))
                ? ((- (IData)((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type))))) 
                   & ((((- (IData)((vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                    >> 0x0000001fU))) 
                        << 0x00000014U) | ((((0x000001feU 
                                              & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                 >> 0x0000000bU)) 
                                             | (1U 
                                                & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                   >> 0x00000014U))) 
                                            << 0x0000000bU) 
                                           | (0x000007feU 
                                              & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                 >> 0x00000014U)))) 
                      & (- (IData)((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type) 
                                             >> 1U)))))))
                : ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type))
                        ? (0xfffff000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                        : (((- (IData)((vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | ((0x00000800U 
                                                & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                   << 4U)) 
                                               | ((0x000007e0U 
                                                   & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001eU 
                                                     & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                        >> 7U))))))
                    : (((- (IData)((vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                    >> 0x0000001fU))) 
                        << 0x0000000bU) | (0x000007ffU 
                                           & ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type))
                                               ? ((0x000007e0U 
                                                   & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001fU 
                                                     & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                        >> 7U)))
                                               : (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                  >> 0x00000014U))))));
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_data 
            = ((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_reg_write) 
                 & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr) 
                    == (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                       >> 0x0000000fU))))
                 ? vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_data
                 : vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
                [(0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                 >> 0x0000000fU))]) 
               & (- (IData)((0U != (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                   >> 0x0000000fU))))));
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.top__DOT__u_cpu__DOT__hz_meta_is_stall) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__stall_count 
                = ((IData)(1U) + vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__stall_count);
        }
        if (vlSelfRef.top__DOT__u_cpu__DOT__hz_meta_is_l_use) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__l_use_count 
                = ((IData)(1U) + vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__l_use_count);
        }
        if (vlSelfRef.top__DOT__u_cpu__DOT__hz_meta_branch_flush) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__br_flush_count 
                = ((IData)(2U) + vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__br_flush_count);
        }
        if (vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_valid_instr) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__instr_count 
                = ((IData)(1U) + vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__instr_count);
        }
        if (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_reg_write) 
             & (0U != (IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr)))) {
            __VdlyVal__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 
                = vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_data;
            __VdlyDim0__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 
                = vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr;
            __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v0 = 1U;
        }
        VL_ASSIGNSEL_WI(2048, 8, (0x000007ffU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U)), vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table, vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__new_write_bhr);
        if (vlSelfRef.top__DOT__u_cpu__DOT__hz_pc_enable) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc_next;
        }
        VL_ASSIGNSEL_WI(512, 2, (0x000001ffU & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history), 1U)), vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table, vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__new_write_entry);
        vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3 
            = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_funct3;
        vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rs2_val 
            = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_data;
        vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_result 
            = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0)
                ? ((IData)(4U) + vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc)
                : vlSelfRef.top__DOT__u_cpu__DOT__alu_out);
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__stall_count = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__l_use_count = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__br_flush_count = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__instr_count = 0U;
        __VdlySet__top__DOT__u_cpu__DOT__u_reg_file__DOT__registers__v1 = 1U;
        VL_ASSIGN_W(2048, vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table, Vtop__ConstPool__CONST_h6be9aa18_0);
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc = 0U;
        VL_ASSIGN_W(512, vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table, Vtop__ConstPool__CONST_h93e1b771_0);
        vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3 = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rs2_val = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_result = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0[0U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0[1U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0[2U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0[3U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0[4U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0[5U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0[6U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U];
            if ((0xd6ffU >= (0x0000ffffU & ((IData)(0x000000d7U) 
                                            * (0x000000ffU 
                                               & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                                  >> 2U)))))) {
                VL_ASSIGNSEL_WW(55040, 215, (0x0000ffffU 
                                             & ((IData)(0x000000d7U) 
                                                * (0x000000ffU 
                                                   & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                                      >> 2U)))), vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache, vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0);
            }
        } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0[0U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0[1U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0[2U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0[3U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0[4U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0[5U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U];
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0[6U] 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U];
            if ((0xd6ffU >= (0x0000ffffU & ((IData)(0x000000d7U) 
                                            * (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index))))) {
                VL_ASSIGNSEL_WW(55040, 215, (0x0000ffffU 
                                             & ((IData)(0x000000d7U) 
                                                * (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index))), vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache, vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0);
            }
        }
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s = 0U;
        while (VL_GTS_III(32, 0x00000100U, vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s)) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache[(
                                                                                ((IData)(3U) 
                                                                                + 
                                                                                (0x0000ffffU 
                                                                                & ((IData)(0x000000d7U) 
                                                                                * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s))) 
                                                                                >> 5U)] 
                = ((~ ((IData)(1U) << (0x0000001fU 
                                       & ((IData)(3U) 
                                          + (0x0000ffffU 
                                             & ((IData)(0x000000d7U) 
                                                * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s)))))) 
                   & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                   [(((IData)(3U) + (0x0000ffffU & 
                                     ((IData)(0x000000d7U) 
                                      * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s))) 
                     >> 5U)]);
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache[(
                                                                                ((IData)(0x00000038U) 
                                                                                + 
                                                                                (0x0000ffffU 
                                                                                & ((IData)(0x000000d7U) 
                                                                                * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s))) 
                                                                                >> 5U)] 
                = ((~ ((IData)(1U) << (0x0000001fU 
                                       & ((IData)(0x00000038U) 
                                          + (0x0000ffffU 
                                             & ((IData)(0x000000d7U) 
                                                * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s)))))) 
                   & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                   [(((IData)(0x00000038U) + (0x0000ffffU 
                                              & ((IData)(0x000000d7U) 
                                                 * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s))) 
                     >> 5U)]);
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache[(
                                                                                ((IData)(0x0000006dU) 
                                                                                + 
                                                                                (0x0000ffffU 
                                                                                & ((IData)(0x000000d7U) 
                                                                                * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s))) 
                                                                                >> 5U)] 
                = ((~ ((IData)(1U) << (0x0000001fU 
                                       & ((IData)(0x0000006dU) 
                                          + (0x0000ffffU 
                                             & ((IData)(0x000000d7U) 
                                                * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s)))))) 
                   & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                   [(((IData)(0x0000006dU) + (0x0000ffffU 
                                              & ((IData)(0x000000d7U) 
                                                 * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s))) 
                     >> 5U)]);
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache[(
                                                                                ((IData)(0x000000a2U) 
                                                                                + 
                                                                                (0x0000ffffU 
                                                                                & ((IData)(0x000000d7U) 
                                                                                * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s))) 
                                                                                >> 5U)] 
                = ((~ ((IData)(1U) << (0x0000001fU 
                                       & ((IData)(0x000000a2U) 
                                          + (0x0000ffffU 
                                             & ((IData)(0x000000d7U) 
                                                * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s)))))) 
                   & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                   [(((IData)(0x000000a2U) + (0x0000ffffU 
                                              & ((IData)(0x000000d7U) 
                                                 * vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s))) 
                     >> 5U)]);
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s 
                = ((IData)(1U) + vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s);
        }
    }
    if ((1U & ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) {
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_funct3 = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_data = 0U;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history 
            = vlSelfRef.top__DOT__u_cpu__DOT__if_id_br_history;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_funct3 
            = (7U & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                     >> 0x0000000cU));
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_data 
            = ((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_reg_write) 
                 & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr) 
                    == (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                       >> 0x00000014U))))
                 ? vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_data
                 : vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
                [(0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                 >> 0x00000014U))]) 
               & (- (IData)((0U != (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                   >> 0x00000014U))))));
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_data 
            = vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data;
        vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr 
            = vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rd_addr;
        vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rd_addr 
            = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rd_addr;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_data = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rd_addr = 0U;
    }
    if ((1U & ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) {
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rd_addr = 0U;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc = vlSelfRef.top__DOT__u_cpu__DOT__if_id_pc;
        vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rd_addr 
            = (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                              >> 7U));
    }
    vlSelfRef.meta_stall_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__stall_count;
    vlSelfRef.meta_l_use_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__l_use_count;
    vlSelfRef.meta_br_flush_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__br_flush_count;
    vlSelfRef.meta_instr_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__instr_count;
    vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_valid_instr 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_valid_instr));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_to_reg 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_to_reg));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_write 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_write));
    if ((1U & ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi)))) {
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_btb_hit = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_br_taken_predict = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_br_history = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_pc = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr = 0U;
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__hz_if_id_enable) {
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_btb_hit 
            = vlSelfRef.top__DOT__u_cpu__DOT__bp_btb_hit;
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_br_taken_predict 
            = vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken;
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_br_history 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out;
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_pc = vlSelfRef.top__DOT__if_addr;
        vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
            = vlSelfRef.top__DOT__instr;
    }
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_read 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_read));
    vlSelfRef.stop = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__stop_signal;
    vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_stop = ((IData)(vlSelfRef.rst_n) 
                                                   && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_stop));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_jal) 
                                                | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_jalr));
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
    vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_valid_instr 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_valid_instr));
    vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_stop = ((IData)(vlSelfRef.rst_n) 
                                                   && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_stop));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__cur_write_entry 
        = (3U & (((0U == (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history) 
                                         << 1U))) ? 0U
                   : (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table
                      [(((IData)(1U) + ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history) 
                                        << 1U)) >> 5U)] 
                      << ((IData)(0x00000020U) - (0x0000001fU 
                                                  & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history) 
                                                     << 1U))))) 
                 | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table
                    [(0x07ffffffU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history) 
                                     >> 4U))] >> (0x0000001fU 
                                                  & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history) 
                                                     << 1U)))));
    vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_reg_write 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_reg_write));
    vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2 = 0U;
    if (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_bypass) {
        vlSelfRef.top__DOT__u_cpu__DOT__alu_out = 0U;
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_to_reg) {
        vlSelfRef.top__DOT__u_cpu__DOT__alu_out = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
            = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_in1_ropc)
                ? vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc
                : vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_data);
        vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2 
            = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_in2_roi)
                ? vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val
                : vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_data);
        vlSelfRef.top__DOT__u_cpu__DOT__alu_out = (
                                                   (8U 
                                                    & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                       ? 
                                                      (VL_LTS_III(32, vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1, vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
                                                        < vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2)
                                                        ? 1U
                                                        : 0U)))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                       ? 
                                                      VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1, 
                                                                     (0x0000001fU 
                                                                      & vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2))
                                                       : 
                                                      (vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
                                                       >> 
                                                       (0x0000001fU 
                                                        & vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2)))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                       ? 0U
                                                       : 
                                                      (vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
                                                       << 
                                                       (0x0000001fU 
                                                        & vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2)))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                       ? 0U
                                                       : 
                                                      (vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
                                                       & vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                       ? 
                                                      (vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
                                                       | vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2)
                                                       : 
                                                      (vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
                                                       ^ vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2)))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op))
                                                       ? 
                                                      (vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
                                                       - vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2)
                                                       : 
                                                      (vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
                                                       + vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2)))));
    }
    __Vtableidx1 = (((0U == vlSelfRef.top__DOT__u_cpu__DOT__alu_out) 
                     << 3U) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_funct3));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_unit__DOT__branch_passed 
        = Vtop__ConstPool__TABLE_h50f0aed2_0[__Vtableidx1];
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_valid_instr 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__d_valid_instr));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_stop = ((1U 
                                                   & (~ 
                                                      ((~ (IData)(vlSelfRef.rst_n)) 
                                                       | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
                                                  && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__d_stop));
    vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_reg_write 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_reg_write));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__inc_or_dec 
        = (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_branch) 
            & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_unit__DOT__branch_passed)) 
           | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__new_write_entry 
        = (3U & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__inc_or_dec)
                  ? (((IData)(1U) + (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__cur_write_entry)) 
                     | (- (IData)((3U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__cur_write_entry)))))
                  : (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__cur_write_entry) 
                      - (IData)(1U)) & (- (IData)((0U 
                                                   != (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__cur_write_entry)))))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite 
        = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_branch) 
           & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_taken_predict) 
              != (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__inc_or_dec)));
    vlSelfRef.top__DOT__u_cpu__DOT__id_ex_reg_write 
        = ((1U & (~ ((~ (IData)(vlSelfRef.rst_n)) | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear)))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable));
    vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__imm_in 
        = (((~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__inc_or_dec)) 
            & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite))
            ? 4U : vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val);
    vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi 
        = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite) 
           | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__if_id_rs2_valid 
        = ((0x33U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)) 
           | ((0x23U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)) 
              | (0x63U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode 
        = (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr);
    vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel = 1U;
    vlSelfRef.top__DOT__u_cpu__DOT__alu_bypass = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__mem_write = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__mem_read = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__alu_op = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__mem_to_reg = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__imm_to_reg = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__pc_in1_sel = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__d_is_branch = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__d_is_jal = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__d_is_jalr = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 5U;
    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__d_stop = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__d_valid_instr = 1U;
    if ((0x00000040U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
        if ((0x00000020U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                if ((8U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                                vlSelfRef.top__DOT__u_cpu__DOT__alu_bypass = 1U;
                                vlSelfRef.top__DOT__u_cpu__DOT__d_stop = 1U;
                                vlSelfRef.top__DOT__u_cpu__DOT__d_valid_instr = 0U;
                            } else {
                                vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                            }
                        } else {
                            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                        }
                    } else {
                        vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                    }
                } else if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                        vlSelfRef.top__DOT__u_cpu__DOT__alu_bypass = 1U;
                        vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 0U;
                        vlSelfRef.top__DOT__u_cpu__DOT__d_stop = 1U;
                    } else {
                        vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                }
            } else if ((8U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                            vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable = 1U;
                            vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel = 1U;
                            vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 4U;
                            vlSelfRef.top__DOT__u_cpu__DOT__d_is_jal = 1U;
                        } else {
                            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                        }
                    } else {
                        vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                }
            } else if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                        vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable = 1U;
                        vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel = 1U;
                        vlSelfRef.top__DOT__u_cpu__DOT__pc_in1_sel = 1U;
                        vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 0U;
                        vlSelfRef.top__DOT__u_cpu__DOT__d_is_jalr = 1U;
                    } else {
                        vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel = 0U;
                    vlSelfRef.top__DOT__u_cpu__DOT__alu_op 
                        = ((0x00004000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                            ? ((0x00002000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                ? 0x0cU : 0x0dU) : 
                           ((0x00002000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                             ? 0U : 4U));
                    vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 2U;
                    vlSelfRef.top__DOT__u_cpu__DOT__d_is_branch = 1U;
                } else {
                    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                }
            } else {
                vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
            }
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
        if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            if ((8U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
            } else if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                        vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable = 1U;
                        vlSelfRef.top__DOT__u_cpu__DOT__imm_to_reg = 1U;
                        vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 3U;
                    } else {
                        vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                    }
                } else {
                    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    vlSelfRef.__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__0__return_op 
                        = ((0x00004000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                            ? ((0x00002000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                ? ((0x00001000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                    ? 6U : 5U) : ((0x00001000U 
                                                   & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                                   ? 
                                                  ((0x40000000U 
                                                    & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                                    ? 0x0bU
                                                    : 0x0aU)
                                                   : 4U))
                            : ((0x00002000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                ? ((0x00001000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                    ? 0x0cU : 0x0dU)
                                : ((0x00001000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                    ? 8U : ((0x40000000U 
                                             & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                             ? 1U : 0U))));
                    vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable = 1U;
                    vlSelfRef.__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__0__Vfuncout 
                        = vlSelfRef.__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__0__return_op;
                    vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel = 0U;
                    vlSelfRef.top__DOT__u_cpu__DOT__alu_op 
                        = vlSelfRef.__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__0__Vfuncout;
                } else {
                    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                }
            } else {
                vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
            }
        } else if ((8U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
        } else if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
        } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                vlSelfRef.top__DOT__u_cpu__DOT__mem_write = 1U;
                vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 1U;
            } else {
                vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
            }
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
        if ((8U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
        } else if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                    vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable = 1U;
                    vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel = 1U;
                    vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 3U;
                } else {
                    vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
                }
            } else {
                vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
                vlSelfRef.__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__return_op 
                    = ((0x00004000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                        ? ((0x00002000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                            ? ((0x00001000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                ? 6U : 5U) : ((0x00001000U 
                                               & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                               ? ((0x40000000U 
                                                   & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                                   ? 0x0bU
                                                   : 0x0aU)
                                               : 4U))
                        : ((0x00002000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                            ? ((0x00001000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                                ? 0x0cU : 0x0dU) : 
                           ((0x00001000U & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)
                             ? 8U : 0U)));
                vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable = 1U;
                vlSelfRef.__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__Vfuncout 
                    = vlSelfRef.__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__return_op;
                vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 0U;
                vlSelfRef.top__DOT__u_cpu__DOT__alu_op 
                    = vlSelfRef.__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__Vfuncout;
            } else {
                vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
            }
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
        }
    } else if ((8U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
        vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
    } else if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
        vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
    } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
            vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable = 1U;
            vlSelfRef.top__DOT__u_cpu__DOT__mem_to_reg = 1U;
            vlSelfRef.top__DOT__u_cpu__DOT__mem_read = 1U;
            vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = 0U;
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
        }
    } else if ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode))) {
        vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr = 1U;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__d_valid_instr = 0U;
    }
    vlSelfRef.top__DOT__u_cpu__DOT__hz_pc_enable = 1U;
    vlSelfRef.top__DOT__u_cpu__DOT__hz_if_id_enable = 1U;
    vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__meta_is_stall = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__meta_is_l_use = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__u_stall_unit__DOT__is_l_use_no_gap 
        = ((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_read) 
             & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_reg_write)) 
            & (0U != (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rd_addr))) 
           & ((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__if_id_rs2_valid) 
                | ((0x13U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)) 
                   | ((3U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)) 
                      | ((0x67U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)) 
                         | (0x73U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)))))) 
               & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rd_addr) 
                  == (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__if_id_rs2_valid) 
                 & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rd_addr) 
                    == (0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                       >> 0x00000014U))))));
    if (vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi) {
        vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear = 1U;
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__u_stall_unit__DOT__is_l_use_no_gap) {
        vlSelfRef.top__DOT__u_cpu__DOT__hz_pc_enable = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__hz_if_id_enable = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__meta_is_stall = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__meta_is_l_use = 1U;
    }
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __VdlyVal__top__DOT__u_data_mem__DOT__container__v0;
    __VdlyVal__top__DOT__u_data_mem__DOT__container__v0 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__u_data_mem__DOT__container__v0;
    __VdlyDim0__top__DOT__u_data_mem__DOT__container__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_data_mem__DOT__container__v0;
    __VdlySet__top__DOT__u_data_mem__DOT__container__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_data_mem__DOT__container__v1;
    __VdlyVal__top__DOT__u_data_mem__DOT__container__v1 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__u_data_mem__DOT__container__v1;
    __VdlyDim0__top__DOT__u_data_mem__DOT__container__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_data_mem__DOT__container__v1;
    __VdlySet__top__DOT__u_data_mem__DOT__container__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_data_mem__DOT__container__v2;
    __VdlyVal__top__DOT__u_data_mem__DOT__container__v2 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__u_data_mem__DOT__container__v2;
    __VdlyDim0__top__DOT__u_data_mem__DOT__container__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_data_mem__DOT__container__v3;
    __VdlyVal__top__DOT__u_data_mem__DOT__container__v3 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__u_data_mem__DOT__container__v3;
    __VdlyDim0__top__DOT__u_data_mem__DOT__container__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_data_mem__DOT__container__v3;
    __VdlySet__top__DOT__u_data_mem__DOT__container__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_data_mem__DOT__container__v4;
    __VdlyVal__top__DOT__u_data_mem__DOT__container__v4 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__u_data_mem__DOT__container__v4;
    __VdlyDim0__top__DOT__u_data_mem__DOT__container__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_data_mem__DOT__container__v5;
    __VdlyVal__top__DOT__u_data_mem__DOT__container__v5 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__u_data_mem__DOT__container__v5;
    __VdlyDim0__top__DOT__u_data_mem__DOT__container__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__u_data_mem__DOT__container__v6;
    __VdlyVal__top__DOT__u_data_mem__DOT__container__v6 = 0;
    SData/*15:0*/ __VdlyDim0__top__DOT__u_data_mem__DOT__container__v6;
    __VdlyDim0__top__DOT__u_data_mem__DOT__container__v6 = 0;
    // Body
    __VdlySet__top__DOT__u_data_mem__DOT__container__v0 = 0U;
    __VdlySet__top__DOT__u_data_mem__DOT__container__v1 = 0U;
    __VdlySet__top__DOT__u_data_mem__DOT__container__v3 = 0U;
    if (((IData)(vlSelfRef.top__DOT__write_enable) 
         & (~ (IData)(vlSelfRef.top__DOT__data_fault)))) {
        if ((1U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            __VdlyVal__top__DOT__u_data_mem__DOT__container__v0 
                = (0x000000ffU & vlSelfRef.top__DOT__write_data);
            __VdlyDim0__top__DOT__u_data_mem__DOT__container__v0 
                = (0x0000ffffU & vlSelfRef.top__DOT__data_addr);
            __VdlySet__top__DOT__u_data_mem__DOT__container__v0 = 1U;
        } else if ((2U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            __VdlyVal__top__DOT__u_data_mem__DOT__container__v1 
                = (0x000000ffU & vlSelfRef.top__DOT__write_data);
            __VdlyDim0__top__DOT__u_data_mem__DOT__container__v1 
                = (0x0000ffffU & vlSelfRef.top__DOT__data_addr);
            __VdlySet__top__DOT__u_data_mem__DOT__container__v1 = 1U;
            __VdlyVal__top__DOT__u_data_mem__DOT__container__v2 
                = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                  >> 8U));
            __VdlyDim0__top__DOT__u_data_mem__DOT__container__v2 
                = (0x0000ffffU & ((IData)(1U) + vlSelfRef.top__DOT__data_addr));
        } else if ((4U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
            __VdlyVal__top__DOT__u_data_mem__DOT__container__v3 
                = (0x000000ffU & vlSelfRef.top__DOT__write_data);
            __VdlyDim0__top__DOT__u_data_mem__DOT__container__v3 
                = (0x0000ffffU & vlSelfRef.top__DOT__data_addr);
            __VdlySet__top__DOT__u_data_mem__DOT__container__v3 = 1U;
            __VdlyVal__top__DOT__u_data_mem__DOT__container__v4 
                = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                  >> 8U));
            __VdlyDim0__top__DOT__u_data_mem__DOT__container__v4 
                = (0x0000ffffU & ((IData)(1U) + vlSelfRef.top__DOT__data_addr));
            __VdlyVal__top__DOT__u_data_mem__DOT__container__v5 
                = (0x000000ffU & (vlSelfRef.top__DOT__write_data 
                                  >> 0x10U));
            __VdlyDim0__top__DOT__u_data_mem__DOT__container__v5 
                = (0x0000ffffU & ((IData)(2U) + vlSelfRef.top__DOT__data_addr));
            __VdlyVal__top__DOT__u_data_mem__DOT__container__v6 
                = (vlSelfRef.top__DOT__write_data >> 0x18U);
            __VdlyDim0__top__DOT__u_data_mem__DOT__container__v6 
                = (0x0000ffffU & ((IData)(3U) + vlSelfRef.top__DOT__data_addr));
        }
    }
    vlSelfRef.top__DOT__u_instr_mem__DOT__addr_reg 
        = vlSelfRef.top__DOT__if_addr;
    if (__VdlySet__top__DOT__u_data_mem__DOT__container__v0) {
        vlSelfRef.top__DOT__u_data_mem__DOT__container[__VdlyDim0__top__DOT__u_data_mem__DOT__container__v0] 
            = __VdlyVal__top__DOT__u_data_mem__DOT__container__v0;
    }
    if (__VdlySet__top__DOT__u_data_mem__DOT__container__v1) {
        vlSelfRef.top__DOT__u_data_mem__DOT__container[__VdlyDim0__top__DOT__u_data_mem__DOT__container__v1] 
            = __VdlyVal__top__DOT__u_data_mem__DOT__container__v1;
        vlSelfRef.top__DOT__u_data_mem__DOT__container[__VdlyDim0__top__DOT__u_data_mem__DOT__container__v2] 
            = __VdlyVal__top__DOT__u_data_mem__DOT__container__v2;
    }
    if (__VdlySet__top__DOT__u_data_mem__DOT__container__v3) {
        vlSelfRef.top__DOT__u_data_mem__DOT__container[__VdlyDim0__top__DOT__u_data_mem__DOT__container__v3] 
            = __VdlyVal__top__DOT__u_data_mem__DOT__container__v3;
        vlSelfRef.top__DOT__u_data_mem__DOT__container[__VdlyDim0__top__DOT__u_data_mem__DOT__container__v4] 
            = __VdlyVal__top__DOT__u_data_mem__DOT__container__v4;
        vlSelfRef.top__DOT__u_data_mem__DOT__container[__VdlyDim0__top__DOT__u_data_mem__DOT__container__v5] 
            = __VdlyVal__top__DOT__u_data_mem__DOT__container__v5;
        vlSelfRef.top__DOT__u_data_mem__DOT__container[__VdlyDim0__top__DOT__u_data_mem__DOT__container__v6] 
            = __VdlyVal__top__DOT__u_data_mem__DOT__container__v6;
    }
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VExpandSel_WordIdx_1;
    IData/*31:0*/ __VExpandSel_LoShift_1;
    CData/*0:0*/ __VExpandSel_Aligned_1;
    IData/*31:0*/ __VExpandSel_HiShift_1;
    IData/*31:0*/ __VExpandSel_HiMask_1;
    IData/*31:0*/ __VExpandSel_WordIdx_2;
    IData/*31:0*/ __VExpandSel_LoShift_2;
    CData/*0:0*/ __VExpandSel_Aligned_2;
    IData/*31:0*/ __VExpandSel_HiShift_2;
    IData/*31:0*/ __VExpandSel_HiMask_2;
    // Body
    vlSelfRef.top__DOT__write_enable = 0U;
    vlSelfRef.top__DOT__write_data = 0U;
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_read)))) {
        if (vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_write) {
            vlSelfRef.top__DOT__write_enable = 1U;
            if ((0U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
                vlSelfRef.top__DOT__write_data = (0x000000ffU 
                                                  & vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rs2_val);
            } else if ((1U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
                vlSelfRef.top__DOT__write_data = (0x0000ffffU 
                                                  & vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rs2_val);
            } else if ((2U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
                vlSelfRef.top__DOT__write_data = vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rs2_val;
            }
        }
    }
    vlSelfRef.top__DOT__data_addr = vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_result;
    vlSelfRef.top__DOT__req_bytes = 0U;
    if (vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_read) {
        if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3) 
                          >> 1U)))) {
                vlSelfRef.top__DOT__req_bytes = ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))
                                                  ? 2U
                                                  : 1U);
            }
        } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3)))) {
                vlSelfRef.top__DOT__req_bytes = 4U;
            }
        } else {
            vlSelfRef.top__DOT__req_bytes = ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))
                                              ? 2U : 1U);
        }
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_write) {
        if ((0U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            vlSelfRef.top__DOT__req_bytes = 1U;
        } else if ((1U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            vlSelfRef.top__DOT__req_bytes = 2U;
        } else if ((2U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            vlSelfRef.top__DOT__req_bytes = 4U;
        }
    }
    vlSelfRef.top__DOT__if_addr = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc;
    vlSelfRef.top__DOT__data_fault = 0U;
    if ((0U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
        if ((0x00010000U < (vlSelfRef.top__DOT__data_addr 
                            + (IData)(vlSelfRef.top__DOT__req_bytes)))) {
            vlSelfRef.top__DOT__data_fault = 1U;
        } else if ((1U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
            if ((2U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
                if ((4U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
                    vlSelfRef.top__DOT__data_fault = 1U;
                }
            }
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index 
        = (0x000000ffU & (vlSelfRef.top__DOT__if_addr 
                          >> 2U));
    vlSelfRef.top__DOT__instr = 0U;
    if ((0x0000fffcU > vlSelfRef.top__DOT__if_addr)) {
        vlSelfRef.top__DOT__instr = (((((IData)(vlSelfRef.top__DOT__u_instr_mem__DOT__container
                                                [(0x0000ffffU 
                                                  & ((IData)(3U) 
                                                     + vlSelfRef.top__DOT__if_addr))]) 
                                        << 8U) | vlSelfRef.top__DOT__u_instr_mem__DOT__container
                                       [(0x0000ffffU 
                                         & ((IData)(2U) 
                                            + vlSelfRef.top__DOT__if_addr))]) 
                                      << 0x00000010U) 
                                     | (((IData)(vlSelfRef.top__DOT__u_instr_mem__DOT__container
                                                 [(0x0000ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__if_addr))]) 
                                         << 8U) | vlSelfRef.top__DOT__u_instr_mem__DOT__container
                                        [(0x0000ffffU 
                                          & vlSelfRef.top__DOT__if_addr)]));
    }
    vlSelfRef.halt = ((0x0000fffcU <= vlSelfRef.top__DOT__if_addr) 
                      | ((IData)(vlSelfRef.top__DOT__data_fault) 
                         | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr)));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out 
        = (0x000000ffU & (((0U == (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                                  << 3U)))
                            ? 0U : (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table
                                    [(((IData)(7U) 
                                       + ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                          << 3U)) >> 5U)] 
                                    << ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                              << 3U))))) 
                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table
                             [(0x07ffffffU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                              >> 2U))] 
                             >> (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
                                                << 3U)))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data = 0ULL;
    __VExpandSel_WordIdx_1 = (0x000007ffU & (((IData)(0x000000d7U) 
                                              * (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index)) 
                                             >> 5U));
    __VExpandSel_LoShift_1 = (0x0000001fU & ((IData)(0x000000d7U) 
                                             * (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index)));
    __VExpandSel_Aligned_1 = (0U == __VExpandSel_LoShift_1);
    if (__VExpandSel_Aligned_1) {
        __VExpandSel_HiShift_1 = 0U;
        __VExpandSel_HiMask_1 = 0U;
    } else {
        __VExpandSel_HiShift_1 = ((IData)(0x00000020U) 
                                  - __VExpandSel_LoShift_1);
        __VExpandSel_HiMask_1 = 0xffffffffU;
    }
    if ((0xd6ffU >= (0x0000ffffU & ((IData)(0x000000d7U) 
                                    * (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index))))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [__VExpandSel_WordIdx_1] >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                 << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                  >> __VExpandSel_LoShift_1));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U] 
            = (0x007fffffU & (((((0x000006b1U <= __VExpandSel_WordIdx_1)
                                  ? 0U : vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                                 [((IData)(7U) + __VExpandSel_WordIdx_1)]) 
                                << __VExpandSel_HiShift_1) 
                               & __VExpandSel_HiMask_1) 
                              | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                                 [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                                 >> __VExpandSel_LoShift_1)));
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U] = 0U;
    }
    __VExpandSel_WordIdx_2 = (0x000007ffU & (((IData)(0x000000d7U) 
                                              * (0x000000ffU 
                                                 & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                                    >> 2U))) 
                                             >> 5U));
    __VExpandSel_LoShift_2 = (0x0000001fU & ((IData)(0x000000d7U) 
                                             * (0x000000ffU 
                                                & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                                   >> 2U))));
    __VExpandSel_Aligned_2 = (0U == __VExpandSel_LoShift_2);
    if (__VExpandSel_Aligned_2) {
        __VExpandSel_HiShift_2 = 0U;
        __VExpandSel_HiMask_2 = 0U;
    } else {
        __VExpandSel_HiShift_2 = ((IData)(0x00000020U) 
                                  - __VExpandSel_LoShift_2);
        __VExpandSel_HiMask_2 = 0xffffffffU;
    }
    if ((0xd6ffU >= (0x0000ffffU & ((IData)(0x000000d7U) 
                                    * (0x000000ffU 
                                       & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                          >> 2U)))))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(1U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [__VExpandSel_WordIdx_2] >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[1U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(2U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(1U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[2U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(3U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(2U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[3U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(4U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(3U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[4U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(5U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(4U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[5U] 
            = (((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                 [((IData)(6U) + __VExpandSel_WordIdx_2)] 
                 << __VExpandSel_HiShift_2) & __VExpandSel_HiMask_2) 
               | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                  [((IData)(5U) + __VExpandSel_WordIdx_2)] 
                  >> __VExpandSel_LoShift_2));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[6U] 
            = (0x007fffffU & (((((0x000006b1U <= __VExpandSel_WordIdx_2)
                                  ? 0U : vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                                 [((IData)(7U) + __VExpandSel_WordIdx_2)]) 
                                << __VExpandSel_HiShift_2) 
                               & __VExpandSel_HiMask_2) 
                              | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache
                                 [((IData)(6U) + __VExpandSel_WordIdx_2)] 
                                 >> __VExpandSel_LoShift_2)));
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[1U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[2U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[3U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[4U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[5U] = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[6U] = 0U;
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[1U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[2U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[3U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[4U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[5U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U] 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[6U];
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
        = (((QData)((IData)(((vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                              + vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val) 
                             >> 2U))) << 0x00000017U) 
           | (QData)((IData)((1U | (0x007ffffeU & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                                                   >> 9U))))));
    if ((1U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U])) {
        if ((4U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U])) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                = ((3U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U]) 
                   | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                      << 2U));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U] 
                = (0x007fffffU & (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                                   >> 0x0000001eU) 
                                  | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                                              >> 0x00000020U)) 
                                     << 2U)));
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                = ((0x00001fffU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U]) 
                   | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                      << 0x0000000dU));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
                = (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                    >> 0x00000013U) | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                                                >> 0x00000020U)) 
                                       << 0x0000000dU));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                = ((0xfffffffcU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U]) 
                   | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                               >> 0x00000020U)) >> 0x00000013U));
        }
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
            = ((0xfffffffbU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U]) 
               | (4U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                            >> 2U)) << 2U)));
    } else {
        if ((2U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set[0U])) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                = ((0x00ffffffU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U]) 
                   | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                      << 0x00000018U));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
                = (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                    >> 8U) | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                                       >> 0x00000020U)) 
                              << 0x00000018U));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                = ((0xffffe000U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U]) 
                   | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                               >> 0x00000020U)) >> 8U));
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                = ((7U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U]) 
                   | ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                      << 3U));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                = ((0xff000000U & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U]) 
                   | (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry) 
                       >> 0x0000001dU) | ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry 
                                                   >> 0x00000020U)) 
                                          << 3U)));
        }
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
            = ((0xfffffffdU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U]) 
               | (2U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                            >> 1U)) << 1U)));
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
        = ((0xfffffffeU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U]) 
           | (1U & (~ vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U])));
    if (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index) 
         == (0x000000ffU & (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                            >> 2U)))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq 
            = ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                               >> 4U)) == (vlSelfRef.top__DOT__if_addr 
                                           >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq 
            = ((0x003fffffU & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
                                << 7U) | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                                          >> 0x00000019U))) 
               == (vlSelfRef.top__DOT__if_addr >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq 
            = ((0x003fffffU & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
                                << 0x00000012U) | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                                                   >> 0x0000000eU))) 
               == (vlSelfRef.top__DOT__if_addr >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq 
            = ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                               >> 3U)) == (vlSelfRef.top__DOT__if_addr 
                                           >> 0x0000000aU));
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq 
            = ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                               >> 4U)) == (vlSelfRef.top__DOT__if_addr 
                                           >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq 
            = ((0x003fffffU & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] 
                                << 7U) | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] 
                                          >> 0x00000019U))) 
               == (vlSelfRef.top__DOT__if_addr >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq 
            = ((0x003fffffU & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] 
                                << 0x00000012U) | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] 
                                                   >> 0x0000000eU))) 
               == (vlSelfRef.top__DOT__if_addr >> 0x0000000aU));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq 
            = ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
                               >> 3U)) == (vlSelfRef.top__DOT__if_addr 
                                           >> 0x0000000aU));
    }
    if (((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq) 
           | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq)) 
          | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq)) 
         | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq))) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
            = ((0xfffffffeU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
               | (1U & (~ vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U])));
        if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                    ? (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                                           << 6U) | 
                                          (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                                           >> 0x0000001aU)))))
                    : (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] 
                                           << 6U) | 
                                          (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                           >> 0x0000001aU))))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffdU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (2U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 1U)) << 1U)));
        } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                    ? (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                                           << 0x00000011U) 
                                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
                                             >> 0x0000000fU)))))
                    : (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] 
                                           << 0x00000011U) 
                                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] 
                                             >> 0x0000000fU))))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffdU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (2U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 1U)) << 1U)));
        } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                    ? (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                                           << 0x0000001cU) 
                                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
                                             >> 4U)))))
                    : (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
                                           << 0x0000001cU) 
                                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] 
                                             >> 4U))))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffbU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (4U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 2U)) << 2U)));
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                    ? (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U] 
                                           << 7U) | 
                                          (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                                           >> 0x00000019U)))))
                    : (QData)((IData)((0x3fffffffU 
                                       & ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U] 
                                           << 7U) | 
                                          (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
                                           >> 0x00000019U))))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffbU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (4U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 2U)) << 2U)));
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__conf_state 
        = (3U & ((((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history) 
                   == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out)) 
                  & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite))
                  ? (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__new_write_entry)
                  : (((0U == (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                             << 1U)))
                       ? 0U : (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table
                               [(((IData)(1U) + ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                                 << 1U)) 
                                 >> 5U)] << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                                   << 1U))))) 
                     | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table
                        [(0x07ffffffU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                         >> 4U))] >> 
                        (0x0000001fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out) 
                                        << 1U))))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_branch_eval__DOT__take_branch 
        = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit) 
           & ((3U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__conf_state)) 
              | (2U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__conf_state))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__opcode 
        = (0x0000007fU & vlSelfRef.top__DOT__instr);
    vlSelfRef.top__DOT__u_cpu__DOT__bp_is_branch = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__bp_btb_hit = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__bp_pc_addr = ((IData)(4U) 
                                                  + vlSelfRef.top__DOT__if_addr);
    if ((0x63U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__opcode))) {
        vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_branch_eval__DOT__take_branch;
        vlSelfRef.top__DOT__u_cpu__DOT__bp_is_branch = 1U;
        vlSelfRef.top__DOT__u_cpu__DOT__bp_btb_hit 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit;
        if (vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken) {
            vlSelfRef.top__DOT__u_cpu__DOT__bp_pc_addr 
                = ((IData)((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                            >> 0x00000017U)) << 2U);
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bh_shift 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite))) 
           && (IData)(vlSelfRef.top__DOT__u_cpu__DOT__bp_is_branch));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index 
        = (0x000000ffU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite)
                           ? (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc 
                              >> 2U) : (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index)));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__cur_write_bhr 
        = (0x000000ffU & (((0U == (0x0000001fU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U)))
                            ? 0U : (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table
                                    [(((IData)(7U) 
                                       + (0x000007ffU 
                                          & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U))) 
                                      >> 5U)] << ((IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U))))) 
                          | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table
                             [(0x0000003fU & (VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U) 
                                              >> 5U))] 
                             >> (0x0000001fU & VL_SHIFTL_III(11,32,32, (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index), 3U)))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__new_write_bhr 
        = vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__cur_write_bhr;
    if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__new_write_bhr 
            = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history;
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bh_shift) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__new_write_bhr 
            = ((((~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite)) 
                 & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_branch_eval__DOT__take_branch)) 
                << 7U) | (0x0000007fU & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__cur_write_bhr) 
                                         >> 1U)));
    }
    if (vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi) {
        if (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc_in1_sel) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_data;
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__imm_in;
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc;
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__imm_in;
        }
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken) {
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
            = vlSelfRef.top__DOT__u_cpu__DOT__bp_pc_addr;
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 0U;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
            = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc;
        vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 4U;
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc_next 
        = (0xfffffffeU & (vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                          + vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2));
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__read_data = 0U;
    if ((0U != (IData)(vlSelfRef.top__DOT__req_bytes))) {
        if ((0x00010000U >= (vlSelfRef.top__DOT__data_addr 
                             + (IData)(vlSelfRef.top__DOT__req_bytes)))) {
            if ((1U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                vlSelfRef.top__DOT__read_data = vlSelfRef.top__DOT__u_data_mem__DOT__container
                    [(0x0000ffffU & vlSelfRef.top__DOT__data_addr)];
            } else if ((2U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                vlSelfRef.top__DOT__read_data = ((vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                  [
                                                  (0x0000ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__data_addr))] 
                                                  << 8U) 
                                                 | vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                 [(0x0000ffffU 
                                                   & vlSelfRef.top__DOT__data_addr)]);
            } else if ((4U == (IData)(vlSelfRef.top__DOT__req_bytes))) {
                vlSelfRef.top__DOT__read_data = (((
                                                   ((IData)(vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                            [
                                                            (0x0000ffffU 
                                                             & ((IData)(3U) 
                                                                + vlSelfRef.top__DOT__data_addr))]) 
                                                    << 8U) 
                                                   | vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                   [
                                                   (0x0000ffffU 
                                                    & ((IData)(2U) 
                                                       + vlSelfRef.top__DOT__data_addr))]) 
                                                  << 0x00000010U) 
                                                 | (((IData)(vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                             [
                                                             (0x0000ffffU 
                                                              & ((IData)(1U) 
                                                                 + vlSelfRef.top__DOT__data_addr))]) 
                                                     << 8U) 
                                                    | vlSelfRef.top__DOT__u_data_mem__DOT__container
                                                    [
                                                    (0x0000ffffU 
                                                     & vlSelfRef.top__DOT__data_addr)]));
            }
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
        = vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_result;
    if (vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_read) {
        if ((4U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3) 
                          >> 1U)))) {
                vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                    = ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))
                        ? (0x0000ffffU & vlSelfRef.top__DOT__read_data)
                        : (0x000000ffU & vlSelfRef.top__DOT__read_data));
            }
        } else if ((2U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))) {
            if ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3)))) {
                vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                    = vlSelfRef.top__DOT__read_data;
            }
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data 
                = ((1U & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3))
                    ? (((- (IData)((1U & (vlSelfRef.top__DOT__read_data 
                                          >> 0x0fU)))) 
                        << 0x00000010U) | (0x0000ffffU 
                                           & vlSelfRef.top__DOT__read_data))
                    : (((- (IData)((1U & (vlSelfRef.top__DOT__read_data 
                                          >> 7U)))) 
                        << 8U) | (0x000000ffU & vlSelfRef.top__DOT__read_data)));
        }
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
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
