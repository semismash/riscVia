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
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.top__DOT__u_cpu__DOT__u_stop__DOT__stop_signal));
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__u_cpu__DOT__hz_pc_enable));
        bufp->chgBit(oldp+2,(vlSelfRef.top__DOT__u_cpu__DOT__hz_if_id_enable));
        bufp->chgBit(oldp+3,(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__branch_taken));
        bufp->chgBit(oldp+4,(vlSelfRef.top__DOT__u_cpu__DOT__hz_id_ex_clear));
        bufp->chgBit(oldp+5,(vlSelfRef.top__DOT__u_cpu__DOT__reg_w_enable));
        bufp->chgCData(oldp+6,((0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                               >> 7U))),5);
        bufp->chgCData(oldp+7,((0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                               >> 0x0000000fU))),5);
        bufp->chgCData(oldp+8,((0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                               >> 0x00000014U))),5);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__rs1_in),32);
        bufp->chgIData(oldp+10,((vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers
                                 [(0x0000001fU & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                  >> 0x00000014U))] 
                                 & (- (IData)((0U != 
                                               (0x0000001fU 
                                                & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                                   >> 0x00000014U))))))),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc),32);
        bufp->chgBit(oldp+12,(vlSelfRef.top__DOT__u_cpu__DOT__pc_in1_sel));
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__u_cpu__DOT__if_id_pc),32);
        bufp->chgIData(oldp+14,(vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr),32);
        bufp->chgCData(oldp+15,((0x0000007fU & vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr)),7);
        bufp->chgBit(oldp+16,(vlSelfRef.top__DOT__u_cpu__DOT__mem_to_reg));
        bufp->chgBit(oldp+17,(vlSelfRef.top__DOT__u_cpu__DOT__imm_to_reg));
        bufp->chgBit(oldp+18,(vlSelfRef.top__DOT__u_cpu__DOT__illegal_instr));
        bufp->chgBit(oldp+19,(vlSelfRef.top__DOT__u_cpu__DOT__d_is_branch));
        bufp->chgBit(oldp+20,(vlSelfRef.top__DOT__u_cpu__DOT__d_is_jal));
        bufp->chgBit(oldp+21,(vlSelfRef.top__DOT__u_cpu__DOT__d_is_jalr));
        bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__u_cpu__DOT__d_stop));
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__imm_in),32);
        bufp->chgIData(oldp+24,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc),32);
        bufp->chgCData(oldp+25,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_addr),5);
        bufp->chgCData(oldp+26,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_addr),5);
        bufp->chgCData(oldp+27,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rd_addr),5);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs1_data),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_rs2_data),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_val),32);
        bufp->chgBit(oldp+31,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_in1_ropc));
        bufp->chgBit(oldp+32,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_in2_roi));
        bufp->chgCData(oldp+33,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_op),4);
        bufp->chgBit(oldp+34,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_alu_bypass));
        bufp->chgBit(oldp+35,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_read));
        bufp->chgBit(oldp+36,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_write));
        bufp->chgCData(oldp+37,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_funct3),3);
        bufp->chgBit(oldp+38,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_pc_in1_sel));
        bufp->chgBit(oldp+39,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_branch));
        bufp->chgBit(oldp+40,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_jal));
        bufp->chgBit(oldp+41,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_is_jalr));
        bufp->chgBit(oldp+42,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_reg_write));
        bufp->chgBit(oldp+43,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_imm_to_reg));
        bufp->chgBit(oldp+44,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_mem_to_reg));
        bufp->chgBit(oldp+45,(vlSelfRef.top__DOT__u_cpu__DOT__id_ex_stop));
        bufp->chgCData(oldp+46,(vlSelfRef.top__DOT__u_cpu__DOT__alu_op),4);
        bufp->chgBit(oldp+47,(vlSelfRef.top__DOT__u_cpu__DOT__alu_in1_sel));
        bufp->chgBit(oldp+48,(vlSelfRef.top__DOT__u_cpu__DOT__alu_in2_sel));
        bufp->chgBit(oldp+49,(vlSelfRef.top__DOT__u_cpu__DOT__alu_bypass));
        bufp->chgBit(oldp+50,((0U == vlSelfRef.top__DOT__u_cpu__DOT__alu_out)));
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__u_cpu__DOT__alu_out),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rs2_val),32);
        bufp->chgCData(oldp+53,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_rd_addr),5);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_result),32);
        bufp->chgBit(oldp+55,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_read));
        bufp->chgBit(oldp+56,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_write));
        bufp->chgCData(oldp+57,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_funct3),3);
        bufp->chgBit(oldp+58,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_reg_write));
        bufp->chgBit(oldp+59,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_mem_to_reg));
        bufp->chgBit(oldp+60,(vlSelfRef.top__DOT__u_cpu__DOT__ex_mem_stop));
        bufp->chgCData(oldp+61,((7U & (vlSelfRef.top__DOT__u_cpu__DOT__if_id_instr 
                                       >> 0x0000000cU))),3);
        bufp->chgBit(oldp+62,(vlSelfRef.top__DOT__u_cpu__DOT__mem_read));
        bufp->chgBit(oldp+63,(vlSelfRef.top__DOT__u_cpu__DOT__mem_write));
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__u_cpu__DOT__reg_write_data),32);
        bufp->chgCData(oldp+65,(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_addr),5);
        bufp->chgIData(oldp+66,(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_rd_data),32);
        bufp->chgBit(oldp+67,(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_reg_write));
        bufp->chgBit(oldp+68,(vlSelfRef.top__DOT__u_cpu__DOT__mem_wb_stop));
        bufp->chgIData(oldp+69,(vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data1),32);
        bufp->chgIData(oldp+70,(vlSelfRef.top__DOT__u_cpu__DOT__u_alu__DOT__data2),32);
        bufp->chgBit(oldp+71,(vlSelfRef.top__DOT__u_cpu__DOT__u_branch_unit__DOT__branch_passed));
        bufp->chgCData(oldp+72,(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__opcode),7);
        bufp->chgCData(oldp+73,(vlSelfRef.top__DOT__u_cpu__DOT__u_decoder__DOT__imm_type),3);
        bufp->chgBit(oldp+74,(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__rs1_used));
        bufp->chgBit(oldp+75,(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__rs2_used));
        bufp->chgBit(oldp+76,(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__rs1_hazard_ex_mem));
        bufp->chgBit(oldp+77,(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__rs1_hazard_mem_wb));
        bufp->chgBit(oldp+78,(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__rs2_hazard_ex_mem));
        bufp->chgBit(oldp+79,(vlSelfRef.top__DOT__u_cpu__DOT__u_hazard_unit__DOT__rs2_hazard_mem_wb));
        bufp->chgBit(oldp+80,((1U & (~ (IData)(vlSelfRef.top__DOT__u_cpu__DOT__hz_if_id_enable)))));
        bufp->chgIData(oldp+81,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__pc_next),32);
        bufp->chgIData(oldp+82,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in1),32);
        bufp->chgIData(oldp+83,(vlSelfRef.top__DOT__u_cpu__DOT__u_pc__DOT__unnamedblk1__DOT__in2),32);
        Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 84, vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__registers);
        bufp->chgIData(oldp+116,(vlSelfRef.top__DOT__u_cpu__DOT__u_reg_file__DOT__i),32);
    }
    bufp->chgBit(oldp+117,(vlSelfRef.clk));
    bufp->chgBit(oldp+118,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+119,(vlSelfRef.halt));
    bufp->chgIData(oldp+120,(vlSelfRef.top__DOT__if_addr),32);
    bufp->chgIData(oldp+121,(vlSelfRef.top__DOT__data_addr),32);
    bufp->chgIData(oldp+122,(vlSelfRef.top__DOT__write_data),32);
    bufp->chgBit(oldp+123,(vlSelfRef.top__DOT__write_enable));
    bufp->chgCData(oldp+124,(vlSelfRef.top__DOT__req_bytes),3);
    bufp->chgIData(oldp+125,(vlSelfRef.top__DOT__instr),32);
    bufp->chgBit(oldp+126,((0x0000fffcU <= vlSelfRef.top__DOT__if_addr)));
    bufp->chgBit(oldp+127,(vlSelfRef.top__DOT__data_fault));
    bufp->chgIData(oldp+128,(vlSelfRef.top__DOT__u_data_mem__DOT__data_out),32);
    bufp->chgIData(oldp+129,(vlSelfRef.top__DOT__u_instr_mem__DOT__addr_reg),32);
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
}
