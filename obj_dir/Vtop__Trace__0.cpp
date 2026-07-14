// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[5U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__instr),32);
        bufp->chgCData(oldp+1,((0x0000001fU & (vlSelfRef.top__DOT__instr 
                                               >> 7U))),5);
        bufp->chgCData(oldp+2,((0x0000001fU & (vlSelfRef.top__DOT__instr 
                                               >> 0x0000000fU))),5);
        bufp->chgCData(oldp+3,((0x0000001fU & (vlSelfRef.top__DOT__instr 
                                               >> 0x00000014U))),5);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__r_data1),32);
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__r_data2),32);
        bufp->chgCData(oldp+6,((7U & (vlSelfRef.top__DOT__instr 
                                      >> 0x0000000cU))),3);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[2U] 
                       | vlSelfRef.__Vm_traceActivity[3U]) 
                      | vlSelfRef.__Vm_traceActivity[6U])))) {
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__read_data),32);
        bufp->chgBit(oldp+8,(vlSelfRef.top__DOT__data_fault));
        bufp->chgBit(oldp+9,(vlSelfRef.top__DOT__u_cpu__DOT__w_enable));
        bufp->chgBit(oldp+10,(vlSelfRef.top__DOT__u_cpu__DOT__pc_in1_sel));
        bufp->chgBit(oldp+11,(vlSelfRef.top__DOT__u_cpu__DOT__pc_in2_sel));
        bufp->chgBit(oldp+12,(vlSelfRef.top__DOT__u_cpu__DOT__alu_or_mem_to_reg));
        bufp->chgBit(oldp+13,(vlSelfRef.top__DOT__u_cpu__DOT__imm_to_reg));
        bufp->chgBit(oldp+14,(vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr));
        bufp->chgCData(oldp+15,(vlSelfRef.top__DOT__u_cpu__DOT__imm_type),3);
        bufp->chgCData(oldp+16,(vlSelfRef.top__DOT__u_cpu__DOT__alu_op),4);
        bufp->chgBit(oldp+17,(vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel));
        bufp->chgBit(oldp+18,(vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel));
        bufp->chgBit(oldp+19,((0U == vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__alu_out)));
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__alu_out),32);
        bufp->chgBit(oldp+21,(vlSelfRef.top__DOT__u_cpu__DOT__mem_read));
        bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__u_cpu__DOT__mem_write));
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data),32);
        bufp->chgCData(oldp+24,(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode),7);
        bufp->chgCData(oldp+25,(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__unnamedblk1__DOT__funct3),3);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc_next),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc),32);
        Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 30, vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers);
        bufp->chgIData(oldp+62,(vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__i),32);
    }
    bufp->chgBit(oldp+63,(vlSelfRef.clk));
    bufp->chgBit(oldp+64,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+65,(vlSelfRef.halt));
    bufp->chgIData(oldp+66,(vlSelfRef.top__DOT__if_addr),32);
    bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__data_addr),32);
    bufp->chgIData(oldp+68,(vlSelfRef.top__DOT__write_data),32);
    bufp->chgBit(oldp+69,(vlSelfRef.top__DOT__write_enable));
    bufp->chgCData(oldp+70,(vlSelfRef.top__DOT__req_bytes),3);
    bufp->chgBit(oldp+71,((0x0001fffcU <= vlSelfRef.top__DOT__if_addr)));
    bufp->chgIData(oldp+72,(((IData)(vlSelfRef.top__DOT__u_cpu__DOT__imm_to_reg)
                              ? vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__imm
                              : ((IData)(vlSelfRef.top__DOT__u_cpu__DOT__alu_or_mem_to_reg)
                                  ? vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data
                                  : vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__alu_out))),32);
    bufp->chgIData(oldp+73,(vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__imm),32);
    bufp->chgIData(oldp+74,(vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1),32);
    bufp->chgIData(oldp+75,(vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2),32);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[31]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[0]),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
