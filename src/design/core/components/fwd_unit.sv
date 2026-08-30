module fwd_unit (
    // Dependencies
    // ID/EX
    input logic dep_id_ex_rd_if_id_rs1,
    input logic dep_id_ex_rd_if_id_rs2,
    // EX/MEM
    input logic dep_ex_mem_rd_id_ex_rs1,
    input logic dep_ex_mem_rd_id_ex_rs2,
    // MEM/WB
    input logic dep_mem_wb_rd_id_ex_rs1,
    input logic dep_mem_wb_rd_id_ex_rs1,
    // non-zero bits to prevent accidental stalls if using locked zero register
    input logic id_ex_rs1_not_x0,
    input logic id_ex_rs2_not_x0,
    // if read registers are even valid to begin with
    input logic id_ex_rs1_valid,
    input logic id_ex_rs2_valid,
    // write signal from registers
    input logic ex_mem_reg_write,
    input logic mem_wb_reg_write,
    // OUTPUT
    output logic fwd_alu_in1_id_ex, // forward to alu in 1 from src res
    output logic fwd_alu_in2_id_ex, // forward to alu in 2 from src res
    output Word alu_in1_data,       // multiplexed data to alu in 1
    output Word alu_in2_data        // multiplexed data to alu in 2
);

    // Conditions for forwarding
    /*
    1. If EX/MEM[rd] == ID/EX[rs1 | rs2] for R/I type instructions
    2. If MEM/WB[rd] == ID/EX[rs1 | rs2] for R/I type instructions
    3. If MEM/WB[rd] == ID/EX[rs1 | rs2] for load type instructions
    */

    logic rs1_hazard_ex_mem;
    logic rs1_hazard_mem_wb;
    logic rs2_hazard_ex_mem;
    logic rs2_hazard_mem_wb;

    always_comb begin
        rs1_hazard_ex_mem = rs1_valid && id_ex_rs1_not_x0 && ex_mem_reg_write && (if_id_rs1 == ex_mem_rdst);
        rs1_hazard_mem_wb = rs1_valid && id_ex_rs1_not_x0 && mem_wb_reg_write && (if_id_rs1 == mem_wb_rdst);
        rs2_hazard_ex_mem = rs2_valid && id_ex_rs2_not_x0 && ex_mem_reg_write && (if_id_rs2 == ex_mem_rdst);
        rs2_hazard_mem_wb = rs2_valid && id_ex_rs2_not_x0 && mem_wb_reg_write && (if_id_rs2 == mem_wb_rdst);
    end

endmodule