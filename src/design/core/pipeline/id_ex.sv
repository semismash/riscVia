import rv32i::*;

module id_ex #(
    parameter REG_WIDTH = 159    // 159 bits
) (
    input logic clk,
    input logic rst_n,  // active low
    input logic stall,

    input Word pc,              // 32 bits
    input RegAddr rs1_addr,     // 5 bits
    input RegAddr rs2_addr,     // 5 bits
    input RegAddr rd_addr,      // 5 bits
    input Word rs1_data,        // 32 bits
    input Word rs2_data,        // 32 bits
    input logic alu_in1_pcor,   // 1 bit
    input logic alu_in2_roi,    // 1 bit
    input ALUOp alu_op,         // 4 bits
    input logic alu_bypass,     // 1 bit
    input logic mem_read,       // 1 bit
    input logic mem_write,      // 1 bit
    input logic [2:0] funct3,   // 3 bits
    input logic is_branch,      // 1 bit
    input logic reg_write,      // 1 bit
    input logic imm_to_reg,     // 1 bit
    input logic mem_to_reg,     // 1 bit

    output Word pc,
    output RegAddr rs1_addr,
    output RegAddr rs2_addr,
    output RegAddr rd_addr,
    output Word rs1_data,
    output Word rs2_data,
    output logic alu_in1_pcor,
    output logic alu_in2_roi,
    output ALUOp alu_op,
    output logic alu_bypass,
    output logic mem_read,
    output logic mem_write,
    output logic [2:0] funct3,
    output logic is_branch,
    output logic reg_write,
    output logic imm_to_reg,
    output logic mem_to_reg
);

    logic [REG_WIDTH-1:0] register;
    logic [REG_WIDTH-1:0] next;

    always_comb begin
        next = 
        {pc,
        rs1_addr,
        rs1_addr,
        rd_addr,
        rs1_data,
        rs2_data,
        alu_in1_pcor,
        alu_in2_roi,
        alu_op,
        alu_bypass,
        mem_read,
        mem_write,
        funct3,
        reg_write,
        imm_to_reg,
        mem_to_reg};
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            register <= '0;
        end else if (!stall) begin  // do normal logic if NOT a stall
            register <= next;
        end
    end

endmodule