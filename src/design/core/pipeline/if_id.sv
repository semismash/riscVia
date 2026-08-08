import rv32i::*;

module if_id #(
    parameter REG_WIDTH = 64    // 64 bits = 32 (pc) + 32 (instr)
) (
    input logic clk,
    input logic rst_n,  // asynchronous active low reset
    input logic stall,
    input logic clear,  // synchronous active high clear

    input Word i_pc,
    input Instruction i_instr,

    output Word o_pc,
    output Instruction o_instr
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n || clear) begin
            o_pc <= '0;
            o_instr <= '0;
        end else if (!stall) begin  // do normal logic if NOT a stall
            o_pc    <= i_pc;
            o_instr <= i_instr;
        end
    end

endmodule