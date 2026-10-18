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
    input logic i_fault,

    output Word o_pc,
    output Instruction o_instr,
    output logic o_br_taken_predict,
    output BranchHistory o_br_history,
    output logic o_btb_hit,
    output logic o_fault
);

    initial begin               // power-up value is a canonical NOP bubble, so IF/ID never holds 0x00000000 before the first reset/fetch
        o_pc    = '0;           
        o_instr = NOP_INSTR;    
        o_fault = 1'b0;         
        o_br_taken_predict = 1'b0;  // power-up value for predictor fields
        o_br_history = '0;          
        o_btb_hit = 1'b0;           
    end                         

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin       // async reset split from the synchronous clear (was `!rst_n || clear`, which is a sim/synthesis mismatch)
            o_pc <= '0;
            o_instr <= NOP_INSTR;   // reset to canonical NOP
            o_fault <= 1'b0;        // reset fetch fault bit
            o_br_taken_predict <= '0;
            o_br_history <= '0;
            o_btb_hit <= '0;
        end else if (clear) begin   // synchronous clear (flush), now its own branch
            o_pc    <= '0;          // flush value
            o_instr <= NOP_INSTR;   // flush to NOP
            o_fault <= 1'b0;        // flushed instruction can't fault
            o_br_taken_predict <= '0;   // flushed bubble carries no prediction
            o_br_history <= '0;         
            o_btb_hit <= '0;            
        end else if (!stall) begin  // do normal logic if NOT a stall
            o_pc    <= i_pc;
            o_instr <= i_instr;
            o_fault <= i_fault;     // latch fetch fault alongside the instruction
            o_br_taken_predict <= i_br_taken_predict;
            o_br_history <= i_br_history;
            o_btb_hit <= i_btb_hit;
        end
    end

endmodule