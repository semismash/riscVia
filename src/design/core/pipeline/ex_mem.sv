import rv32i::*;

module if_id #(
    parameter REG_WIDTH = 77    // 77 bits
) (
    input logic clk,
    input logic rst_n,  // active low
    input logic stall,

    input Word rs2_val,         // 32 bits
    input RegAddr rd_addr,      // 5 bits
    input Word result,          // 32 bits
    input logic alu_zero,       // 1 bit
    input logic mem_read,       // 1 bit
    input logic mem_write,      // 1 bit
    input logic [2:0] funct3,   // 3 bits
    input logic reg_write,      // 1 bit
    input logic mem_to_reg,     // 1 bit

    output Word rs2_val,
    output RegAddr rd_addr,
    output Word result,
    output logic alu_zero,
    output logic mem_read,
    output logic mem_write,
    output logic [2:0] funct3,
    output logic reg_write,
    output logic mem_to_reg
);

    logic [REG_WIDTH-1:0] register;
    logic [REG_WIDTH-1:0] next;

    always_comb begin
        next = 
        {rs2_val,
        rd_addr,
        result,
        alu_zero,
        mem_read,
        mem_write,
        funct3,
        reg_write,
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