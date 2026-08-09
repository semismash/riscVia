import rv32i::*;

module id_ex (  // 161 bits
    input logic clk,
    input logic rst_n,  // asynchronous active low reset
    input logic stall,
    input logic clear,  // synchronous active high clear

    input Word i_pc,              // 32 bits
    input RegAddr i_rs1_addr,     // 5 bits
    input RegAddr i_rs2_addr,     // 5 bits
    input RegAddr i_rd_addr,      // 5 bits
    input Word i_rs1_data,        // 32 bits
    input Word i_rs2_data,        // 32 bits
    input logic i_alu_in1_pcor,   // 1 bit
    input logic i_alu_in2_roi,    // 1 bit
    input ALUOp i_alu_op,         // 4 bits
    input logic i_alu_bypass,     // 1 bit
    input logic i_mem_read,       // 1 bit
    input logic i_mem_write,      // 1 bit
    input logic [2:0] i_funct3,   // 3 bits
    input logic i_is_branch,      // 1 bit
    input logic i_is_jal,         // 1 bit
    input logic i_is_jalr,        // 1 bit
    input logic i_reg_write,      // 1 bit
    input logic i_imm_to_reg,     // 1 bit
    input logic i_mem_to_reg,     // 1 bit

    output Word o_pc,
    output RegAddr o_rs1_addr,
    output RegAddr o_rs2_addr,
    output RegAddr o_rd_addr,
    output Word o_rs1_data,
    output Word o_rs2_data,
    output logic o_alu_in1_pcor,
    output logic o_alu_in2_roi,
    output ALUOp o_alu_op,
    output logic o_alu_bypass,
    output logic o_mem_read,
    output logic o_mem_write,
    output logic [2:0] o_funct3,
    output logic o_is_branch,
    output logic o_reg_write,
    output logic o_imm_to_reg,
    output logic o_mem_to_reg
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n || clear) begin
            o_pc           <= '0;
            o_rs1_addr     <= '0;
            o_rs2_addr     <= '0;
            o_rd_addr      <= '0;
            o_rs1_data     <= '0;
            o_rs2_data     <= '0;
            o_alu_in1_pcor <= '0;
            o_alu_in2_roi  <= '0;
            o_alu_op       <= ADD;    // add by default
            o_alu_bypass   <= '0;
            o_mem_read     <= '0;
            o_mem_write    <= '0;
            o_funct3       <= '0;
            o_is_branch    <= '0;
            o_reg_write    <= '0;
            o_imm_to_reg   <= '0;
            o_mem_to_reg   <= '0;
        end else if (!stall) begin  // do normal logic if NOT a stall
            o_pc           <= i_pc;
            o_rs1_addr     <= i_rs1_addr;
            o_rs2_addr     <= i_rs2_addr;
            o_rd_addr      <= i_rd_addr;
            o_rs1_data     <= i_rs1_data;
            o_rs2_data     <= i_rs2_data;
            o_alu_in1_pcor <= i_alu_in1_pcor;
            o_alu_in2_roi  <= i_alu_in2_roi;
            o_alu_op       <= i_alu_op;
            o_alu_bypass   <= i_alu_bypass;
            o_mem_read     <= i_mem_read;
            o_mem_write    <= i_mem_write;
            o_funct3       <= i_funct3;
            o_is_branch    <= i_is_branch;
            o_reg_write    <= i_reg_write;
            o_imm_to_reg   <= i_imm_to_reg;
            o_mem_to_reg   <= i_mem_to_reg;
        end
    end

endmodule