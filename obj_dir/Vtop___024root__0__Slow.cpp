// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9124449291403006271ull);
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2324538194100007937ull);
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

extern const VlUnpacked<CData/*0:0*/, 16> Vtop__ConstPool__TABLE_h50f0aed2_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
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
    vlSelfRef.stop = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__stop_signal;
    vlSelfRef.meta_instr_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__instr_count;
    vlSelfRef.meta_stall_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__stall_count;
    vlSelfRef.meta_l_use_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__l_use_count;
    vlSelfRef.meta_br_flush_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__br_flush_count;
    vlSelfRef.meta_br_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__br_count;
    vlSelfRef.meta_mispred_count = vlSelfRef.top__DOT__u_cpu__DOT__u_meta__DOT__mispred_count;
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
    vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__if_id_rs2_valid 
        = ((0x33U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)) 
           | ((0x23U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)) 
              | (0x63U == (0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr))));
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
    vlSelfRef.top__DOT__if_addr = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_jal) 
                                                | (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_jalr));
    vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__id_ex_rs2_valid 
        = ((0x33U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_opcode)) 
           | ((0x23U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_opcode)) 
              | (0x63U == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_opcode))));
    vlSelfRef.top__DOT__data_fault = 0U;
    vlSelfRef.top__DOT__read_data = 0U;
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
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2 = ((0U 
                                                 != (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_addr)) 
                                                & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__id_ex_rs2_valid) 
                                                   | ((0x13U 
                                                       == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_opcode)) 
                                                      | ((3U 
                                                          == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_opcode)) 
                                                         | ((0x67U 
                                                             == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_opcode)) 
                                                            | (0x73U 
                                                               == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_opcode)))))));
    __VdfgRegularize_h6e95ff9d_0_1 = ((0U != (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_addr)) 
                                      & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__id_ex_rs2_valid));
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
    vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__fwd_alu_in2_ex_mem 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_1) 
           & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_reg_write) 
              & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_addr) 
                 == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rd_addr))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__fwd_alu_in2_mem_wb 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_1) 
           & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_reg_write) 
              & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr) 
                 == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_addr))));
    vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2 = 0U;
    if (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_bypass) {
        vlSelfRef.top__DOT__u_cpu__DOT__alu_out = 0U;
    } else if (vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_to_reg) {
        vlSelfRef.top__DOT__u_cpu__DOT__alu_out = vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val;
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1 
            = (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2) 
                & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_reg_write) 
                   & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_addr) 
                      == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rd_addr))))
                ? vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_result
                : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_2) 
                    & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_reg_write) 
                       & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr) 
                          == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_addr))))
                    ? vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_data
                    : ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_in1_ropc)
                        ? vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc
                        : vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_data)));
        vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2 
            = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__fwd_alu_in2_ex_mem)
                ? vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_result
                : ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__fwd_alu_in2_mem_wb)
                    ? vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_data
                    : ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_in2_roi)
                        ? vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val
                        : vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_data)));
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
    vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__imm_in 
        = (((~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__inc_or_dec)) 
            & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite))
            ? 4U : vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val);
    vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi 
        = ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite) 
           | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index 
        = (0x000000ffU & (vlSelfRef.top__DOT__if_addr 
                          >> 2U));
    vlSelfRef.top__DOT__u_cpu__DOT__hz_pc_enable = 1U;
    vlSelfRef.top__DOT__u_cpu__DOT__hz_if_id_enable = 1U;
    vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__hz_meta_is_stall = 0U;
    vlSelfRef.top__DOT__u_cpu__DOT__hz_meta_is_l_use = 0U;
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
            = ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                >> 3U) & ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U] 
                                          >> 4U)) == 
                          (vlSelfRef.top__DOT__if_addr 
                           >> 0x0000000aU)));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq 
            = ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                >> 0x00000018U) & ((0x003fffffU & (
                                                   (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U] 
                                                    << 7U) 
                                                   | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U] 
                                                      >> 0x00000019U))) 
                                   == (vlSelfRef.top__DOT__if_addr 
                                       >> 0x0000000aU)));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq 
            = ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                >> 0x0000000dU) & ((0x003fffffU & (
                                                   (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U] 
                                                    << 0x00000012U) 
                                                   | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U] 
                                                      >> 0x0000000eU))) 
                                   == (vlSelfRef.top__DOT__if_addr 
                                       >> 0x0000000aU)));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq 
            = ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                >> 2U) & ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U] 
                                          >> 3U)) == 
                          (vlSelfRef.top__DOT__if_addr 
                           >> 0x0000000aU)));
    } else {
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded = 0U;
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq 
            = ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                >> 3U) & ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                          >> 4U)) == 
                          (vlSelfRef.top__DOT__if_addr 
                           >> 0x0000000aU)));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq 
            = ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] 
                >> 0x00000018U) & ((0x003fffffU & (
                                                   (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U] 
                                                    << 7U) 
                                                   | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U] 
                                                      >> 0x00000019U))) 
                                   == (vlSelfRef.top__DOT__if_addr 
                                       >> 0x0000000aU)));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq 
            = ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] 
                >> 0x0000000dU) & ((0x003fffffU & (
                                                   (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U] 
                                                    << 0x00000012U) 
                                                   | (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U] 
                                                      >> 0x0000000eU))) 
                                   == (vlSelfRef.top__DOT__if_addr 
                                       >> 0x0000000aU)));
        vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq 
            = ((vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
                >> 2U) & ((0x003fffffU & (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U] 
                                          >> 3U)) == 
                          (vlSelfRef.top__DOT__if_addr 
                           >> 0x0000000aU)));
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
                = (0x001fffffffffffffULL & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                                             ? (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U])) 
                                                 << 0x0000003dU) 
                                                | (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U])) 
                                                    << 0x0000001dU) 
                                                   | ((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[0U])) 
                                                      >> 3U)))
                                             : (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U])) 
                                                 << 0x0000003dU) 
                                                | (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U])) 
                                                    << 0x0000001dU) 
                                                   | ((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U])) 
                                                      >> 3U)))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffdU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (2U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 1U)) << 1U)));
        } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = (0x001fffffffffffffULL & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                                             ? (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U])) 
                                                 << 0x00000028U) 
                                                | (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[2U])) 
                                                    << 8U) 
                                                   | ((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[1U])) 
                                                      >> 0x00000018U)))
                                             : (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U])) 
                                                 << 0x00000028U) 
                                                | (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[2U])) 
                                                    << 8U) 
                                                   | ((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[1U])) 
                                                      >> 0x00000018U)))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffdU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (2U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 1U)) << 1U)));
        } else if (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = (0x001fffffffffffffULL & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                                             ? (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U])) 
                                                 << 0x00000033U) 
                                                | (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[4U])) 
                                                    << 0x00000013U) 
                                                   | ((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[3U])) 
                                                      >> 0x0000000dU)))
                                             : (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U])) 
                                                 << 0x00000033U) 
                                                | (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[4U])) 
                                                    << 0x00000013U) 
                                                   | ((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[3U])) 
                                                      >> 0x0000000dU)))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffbU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (4U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 2U)) << 2U)));
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data 
                = (0x001fffffffffffffULL & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded)
                                             ? (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U])) 
                                                 << 0x0000003eU) 
                                                | (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[6U])) 
                                                    << 0x0000001eU) 
                                                   | ((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set[5U])) 
                                                      >> 2U)))
                                             : (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U])) 
                                                 << 0x0000003eU) 
                                                | (((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[6U])) 
                                                    << 0x0000001eU) 
                                                   | ((QData)((IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[5U])) 
                                                      >> 2U)))));
            vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                = ((0xfffffffbU & vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U]) 
                   | (4U & ((~ (vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set[0U] 
                                >> 2U)) << 2U)));
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__conf_state 
        = (3U & (((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_branch) 
                  & ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_br_history) 
                     == (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out)))
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
    if (vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi) {
        vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear = 1U;
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
    } else {
        if (vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__u_stall_unit__DOT__is_l_use_no_gap) {
            vlSelfRef.top__DOT__u_cpu__DOT__hz_pc_enable = 0U;
            vlSelfRef.top__DOT__u_cpu__DOT__hz_if_id_enable = 0U;
            vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear = 1U;
            vlSelfRef.top__DOT__u_cpu__DOT__hz_meta_is_stall = 1U;
            vlSelfRef.top__DOT__u_cpu__DOT__hz_meta_is_l_use = 1U;
        }
        if (vlSelfRef.top__DOT__u_cpu__DOT__bp_branch_taken) {
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                = vlSelfRef.top__DOT__u_cpu__DOT__bp_pc_addr;
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 0U;
        } else {
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                = vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc;
            vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2 = 4U;
        }
    }
    vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bh_shift 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite))) 
           && ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__bp_is_branch) 
               & ((~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi)) 
                  & (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_if_id_enable))));
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
    vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc_next 
        = (0xfffffffeU & (vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1 
                          + vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
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

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->halt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11049222807502041558ull);
    vlSelf->stop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16026904639853099817ull);
    vlSelf->meta_instr_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10015820582880033300ull);
    vlSelf->meta_stall_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14134897821726767834ull);
    vlSelf->meta_l_use_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9335564172548842940ull);
    vlSelf->meta_br_flush_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3248577445493138422ull);
    vlSelf->meta_br_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16658099839992952313ull);
    vlSelf->meta_mispred_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10046185646859532174ull);
    vlSelf->top__DOT__if_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9948625378764159429ull);
    vlSelf->top__DOT__data_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16073976394386819418ull);
    vlSelf->top__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 554206876145221615ull);
    vlSelf->top__DOT__write_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5791377118671855880ull);
    vlSelf->top__DOT__req_bytes = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16775011400878586817ull);
    vlSelf->top__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3126867797622976717ull);
    vlSelf->top__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 56483938310836132ull);
    vlSelf->top__DOT__data_fault = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8167140621540713626ull);
    vlSelf->top__DOT__u_cpu__DOT__hz_pc_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15097604899420171104ull);
    vlSelf->top__DOT__u_cpu__DOT__hz_if_id_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8078186626949710136ull);
    vlSelf->top__DOT__u_cpu__DOT__hz_id_ex_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5469036487018072866ull);
    vlSelf->top__DOT__u_cpu__DOT__hz_meta_is_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12873730535212990782ull);
    vlSelf->top__DOT__u_cpu__DOT__hz_meta_is_l_use = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16572838530136802213ull);
    vlSelf->top__DOT__u_cpu__DOT__reg_w_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10223263319588754604ull);
    vlSelf->top__DOT__u_cpu__DOT__rdst_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17065176272422443287ull);
    vlSelf->top__DOT__u_cpu__DOT__pc_in1_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4031094445959648418ull);
    vlSelf->top__DOT__u_cpu__DOT__bp_branch_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3577510388308965943ull);
    vlSelf->top__DOT__u_cpu__DOT__bp_pc_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14216141810961972162ull);
    vlSelf->top__DOT__u_cpu__DOT__bp_is_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8528291204881586506ull);
    vlSelf->top__DOT__u_cpu__DOT__bp_btb_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5617170129417906027ull);
    vlSelf->top__DOT__u_cpu__DOT__if_id_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1709853132189231410ull);
    vlSelf->top__DOT__u_cpu__DOT__if_id_instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18411245862516480260ull);
    vlSelf->top__DOT__u_cpu__DOT__if_id_br_taken_predict = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 174540372068962857ull);
    vlSelf->top__DOT__u_cpu__DOT__if_id_br_history = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16108662465658813694ull);
    vlSelf->top__DOT__u_cpu__DOT__if_id_btb_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7618566511523305916ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_to_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5494201134156193131ull);
    vlSelf->top__DOT__u_cpu__DOT__imm_to_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10333335306906697625ull);
    vlSelf->top__DOT__u_cpu__DOT__illegal_instr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14818882104295685375ull);
    vlSelf->top__DOT__u_cpu__DOT__d_is_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15609380771558330870ull);
    vlSelf->top__DOT__u_cpu__DOT__d_is_jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10496328843272864426ull);
    vlSelf->top__DOT__u_cpu__DOT__d_is_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 67005864643446593ull);
    vlSelf->top__DOT__u_cpu__DOT__d_stop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13525898123576513929ull);
    vlSelf->top__DOT__u_cpu__DOT__d_valid_instr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15351992385630302526ull);
    vlSelf->top__DOT__u_cpu__DOT__imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17771432074263927410ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13811012327199315214ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_rs1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5510206514123928825ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_rs2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11391892174079173309ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1284006743651788119ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7200547187505777306ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 685965317621172872ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_imm_val = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6943186970993868990ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_alu_in1_ropc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2604175333716274025ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_alu_in2_roi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17683051422305902623ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5414918197405413712ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_alu_bypass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12459983598956300446ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12647249009249248702ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16655142461626830243ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7048750492435766523ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_pc_in1_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14392788305842454303ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_is_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7944670826139486196ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_is_jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3809299081348756410ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_is_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2795056145993351996ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16251735131458765682ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_imm_to_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9222393995847866136ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_mem_to_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18405855007728579971ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_stop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6628400893274382243ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_valid_instr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9884091738772220562ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_br_taken_predict = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13773974335724794432ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_br_history = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5295105059140241774ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_btb_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18110128902579461257ull);
    vlSelf->top__DOT__u_cpu__DOT__id_ex_opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 7288527285578457779ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12758967225510099876ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_in1_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15870090315687284172ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_in2_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15916634701875632495ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_bypass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9049029015462005213ull);
    vlSelf->top__DOT__u_cpu__DOT__alu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3482279785517445549ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_rs2_val = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2732589158360952590ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13775499201085202000ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3986449201690900979ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6891396199096775498ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16433501515530112205ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7358728625184629902ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11669702140753607184ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_mem_to_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13334913426715958517ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_stop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9505698503944766965ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_valid_instr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14393220491820429867ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_is_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12506702814757181150ull);
    vlSelf->top__DOT__u_cpu__DOT__ex_mem_bp_mispredict = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18026941027443344803ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11728375109217349596ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8396010597759043545ull);
    vlSelf->top__DOT__u_cpu__DOT__reg_write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4252256717780325557ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_wb_rd_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9841072902432727225ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_wb_rd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17994396378917634444ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_wb_reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5380692490876238206ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_wb_stop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7768551789704405039ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_wb_valid_instr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3769117203145249260ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_wb_is_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5714463951215134530ull);
    vlSelf->top__DOT__u_cpu__DOT__mem_wb_bp_mispredict = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14454648250083423030ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1375488913775379883ull);
    }
    vlSelf->top__DOT__u_cpu__DOT__u_reg_file__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3297519375640141125ull);
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17573726952508183958ull);
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__imm_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11631770352401890670ull);
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1399258308895884909ull);
    vlSelf->top__DOT__u_cpu__DOT__u_pc__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11855832878590989954ull);
    vlSelf->top__DOT__u_cpu__DOT__u_hazard_unit__DOT__fwd_alu_in2_ex_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15328666864928392262ull);
    vlSelf->top__DOT__u_cpu__DOT__u_hazard_unit__DOT__fwd_alu_in2_mem_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14742287847833388096ull);
    vlSelf->top__DOT__u_cpu__DOT__u_hazard_unit__DOT__if_id_rs2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8193924015858267261ull);
    vlSelf->top__DOT__u_cpu__DOT__u_hazard_unit__DOT__id_ex_rs2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5874509529767932806ull);
    vlSelf->top__DOT__u_cpu__DOT__u_hazard_unit__DOT__u_stall_unit__DOT__is_l_use_no_gap = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4307761914958492497ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 6727381099428965190ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__pc_index = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16656309097725164040ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7788499457822584054ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__btb_data = VL_SCOPED_RAND_RESET_Q(53, __VscopeHash, 2400407248088820513ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bht_write_index = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12662209568466290407ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__bh_shift = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3903354310374643707ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_overwrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13295760651213486612ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bh_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2931257789733389845ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__bht_table, __VscopeHash, 10489823746853041606ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__cur_write_bhr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10614345637660186687ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_bht__DOT__new_write_bhr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8169176365701565290ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__inc_or_dec = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12882501418335172138ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__conf_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4954241668834266696ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__pht_table, __VscopeHash, 15848850205898049393ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__cur_write_entry = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6366623970649886264ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_pht__DOT__new_write_entry = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3461016664459120179ull);
    VL_ZERO_RESET_W(215, vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_h565829a1__0);
    VL_ZERO_RESET_W(215, vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT____Vlvbound_heb32bb28__0);
    VL_SCOPED_RAND_RESET_W(55040, vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__btb_cache, __VscopeHash, 3542456217383412941ull);
    VL_SCOPED_RAND_RESET_W(215, vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_read_set, __VscopeHash, 5579746156283747507ull);
    VL_SCOPED_RAND_RESET_W(215, vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__cur_write_set, __VscopeHash, 11609737907280578536ull);
    VL_SCOPED_RAND_RESET_W(215, vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__new_write_set, __VscopeHash, 14518329426639004999ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__write_entry = VL_SCOPED_RAND_RESET_Q(53, __VscopeHash, 7374746383423574497ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_0_eq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1621291984661929779ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_1_eq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17028873346380580605ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_2_eq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17887688076632173772ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__read_3_eq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12300544737604732781ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__forwarded = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4770252345339044903ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_btb__DOT__unnamedblk1__DOT__s = 0;
    vlSelf->top__DOT__u_cpu__DOT__u_branch_predictor__DOT__u_branch_eval__DOT__take_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18371544548753344519ull);
    vlSelf->top__DOT__u_cpu__DOT__u_decoder__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 14033807547098626134ull);
    vlSelf->top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4286665488713578528ull);
    vlSelf->top__DOT__u_cpu__DOT__u_alu__DOT__data1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14033296306717898790ull);
    vlSelf->top__DOT__u_cpu__DOT__u_alu__DOT__data2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12677144840115112110ull);
    vlSelf->top__DOT__u_cpu__DOT__u_branch_unit__DOT__branch_passed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5030301645421667381ull);
    vlSelf->top__DOT__u_cpu__DOT__u_meta__DOT__stop_signal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12421637888803468164ull);
    vlSelf->top__DOT__u_cpu__DOT__u_meta__DOT__instr_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15613914127732262431ull);
    vlSelf->top__DOT__u_cpu__DOT__u_meta__DOT__stall_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11702730034716601678ull);
    vlSelf->top__DOT__u_cpu__DOT__u_meta__DOT__l_use_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 385372348010913071ull);
    vlSelf->top__DOT__u_cpu__DOT__u_meta__DOT__br_flush_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12465170206570378654ull);
    vlSelf->top__DOT__u_cpu__DOT__u_meta__DOT__br_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6658932395790357237ull);
    vlSelf->top__DOT__u_cpu__DOT__u_meta__DOT__mispred_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11569530497910611401ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->top__DOT__u_instr_mem__DOT__container[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17838547526792547713ull);
    }
    vlSelf->top__DOT__u_instr_mem__DOT__addr_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17482381438776612688ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->top__DOT__u_data_mem__DOT__container[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6583783866916463061ull);
    }
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__0__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__0__return_op = 0;
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__u_cpu__DOT__u_decoder__DOT__calc_alu_op__1__return_op = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_2 = 0;
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
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
