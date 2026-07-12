typedef enum logic [2:0] { 
    I, S, B, U, J
} ImmPackFmt;

typedef logic [rv32i::DATA_WIDTH-1:0] Instruction;
typedef logic [rv32i::DATA_WIDTH-1:0] Word;

import rv32i::ALUOpType;

module decoder #(
    parameter DATA_WIDTH = rv32i::DATA_WIDTH,
    parameter ADDR_WIDTH = rv32i::ADDR_WIDTH
) (
    input Instruction instr,   // instruction
    input logic alu_zero,       // feedback from ALU to resolve branch conditions

    output logic reg_write,     // if it writes back to a register
    output logic mem_write,     // if writes to data memory (for OP_I, OP_I_L, OP_R)

    output ALUOpType alu_op,        // alu specific operation (to be moved into main logic)
    output logic alu_mem_or_imm,           //picks between alu second input being reg or imm

    output logic mem_to_reg,               // chooses between routing alu output and data mem output to reg file
    output ImmPackFmt imm_out,             // method to pack the immediate, directive for immediate generator

    output logic pc_target      // PC output control, if PC + 4 or PC + BranchTarget
);

    import rv32i::ALUOpType;

    always_comb begin
        case ()
    end
    
endmodule

module immediate_generator (
    input Instruction instr,
    input ALUOpType alu_op,

    output Word imm_out
);

endmodule