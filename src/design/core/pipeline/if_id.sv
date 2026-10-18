import rv32i::*;

module if_id (  // 64 bits
    input logic clk,
    input logic rst_n,  // asynchronous active low reset
    input logic stall,
    input logic clear,  // synchronous active high clear

    input Word i_pc,
    input Instruction i_instr,
    input logic i_fault,            // instruction fetch fault, travels with the instruction so a wrong-path fault gets flushed instead of halting

    output Word o_pc,
    output Instruction o_instr,
    output logic o_fault
);

    initial begin
        o_pc    = '0;
        o_instr = NOP_INSTR;
        o_fault = 1'b0;
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin       // async reset split from the synchronous clear (was `!rst_n || clear`, which is a sim/synthesis mismatch)
            o_pc <= '0;
            o_instr <= NOP_INSTR;   // reset to canonical NOP instead of 0x00000000
            o_fault <= 1'b0;        // reset fetch fault bit
        end else if (clear) begin   // synchronous clear (flush), now its own branch
            o_pc    <= '0;          // flush value
            o_instr <= NOP_INSTR;   // flush to canonical NOP instead of 0x00000000
            o_fault <= 1'b0;        // a flushed instruction can't fault
        end else if (!stall) begin  // do normal logic if NOT a stall
            o_pc    <= i_pc;
            o_instr <= i_instr;
            o_fault <= i_fault;     // latch fetch fault alongside the instruction
        end
    end

endmodule