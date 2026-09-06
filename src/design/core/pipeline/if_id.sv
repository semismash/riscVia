import rv32i::*;

module if_id (  // 74 bits
    input logic clk,
    input logic rst_n,  // asynchronous active low reset
    input logic stall,
    input logic clear,  // synchronous active high clear

    input Word i_pc,
    input Instruction i_instr,
    input logic i_br_taken_predict,
    input BranchHistory i_br_history,
    input logic i_btb_hit,

    output Word o_pc,
    output Instruction o_instr,
    output logic o_br_taken_predict,
    output BranchHistory o_br_history,
    output logic o_btb_hit
);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n || clear) begin
            o_pc <= '0;
            o_instr <= '0;
            o_br_taken_predict <= '0;
            o_br_history <= '0;
            o_btb_hit <= '0;
        end else if (!stall) begin  // do normal logic if NOT a stall
            o_pc    <= i_pc;
            o_instr <= i_instr;
            o_br_taken_predict <= i_br_taken_predict;
            o_br_history <= i_br_history;
            o_btb_hit <= i_btb_hit;
        end
    end

endmodule