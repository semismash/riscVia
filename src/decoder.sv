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
    input Instruction instr,    // instruction
    input logic alu_zero,       // feedback from ALU to resolve branch conditions

    output logic reg_write,     // if it writes back to a register
    output logic mem_write,     // if writes to data memory (for OP_I, OP_I_L, OP_R)

    output ALUOpType alu_op,    // alu specific operation
    output logic alu_in1_ropc,  // picks between alu first input being reg(0) or pc(1)
    output logic alu_in2_moi,   // picks between alu second input being reg(0) or imm(1)

    output logic mem_to_reg,    // chooses between routing alu output (0) and data mem output (1) to reg file
    output Word imm_out,        // output by immediate generator (to be moved into different file later, likely)

    output logic pc_target      // PC output control, if PC = PC + 4 (0) or PC = PC + IMM (1)
);

    import rv32i::*;

    OpCode opcode;
    ImmPackFmt imm_type;

    immediate_generator imm_gen (
        .instr   (instr),
        .imm_type(imm_type),
        .imm_out (imm_out)
    );

    function AluOp calc_alu_op();
        logic funct3 = instr[14:12];
        AluOp return_op = ADD;  //default add for safety
        case (funct3)
            3'b000: begin
                if instr[30] == 1'b0 begin  // check bit 30 to verify add/sub
                    return_op = ADD;
                end else begin
                    return_op = SUB;
                end
            end
            3'b100: return_op = XOR;
            3'b110: return_op = OR;
            3'b111: return_op = AND;
            3'b001: return_op = SLL;
            3'b101: begin
                if instr[30] == 1'b0 begin  // check bit 30 to verify srl/sra
                    return_op = SRL;
                end else begin
                    return_op = SRA;
                end
            end
            3'b010: return_op = SLT;
            3'b011: return_op = SLTU;
        endcase
        return return_op;
    endfunction

    always_comb begin
        opcode = OpCode'(instr[6:0]);
        alu_in2_ropc = 1'b0;    // by default, take alu 1 from register
        alu_in2_moi  = 1'b1;    // by default, take alu 2 from imm gen
        reg_write    = 1'b1;    // by default, write back to reg
        mem_write    = 1'b0;    // by default, don't write to mem
        mem_to_reg   = 1'b0;    // by default, always take from alu output to reg file
        pc_target    = 1'b0;    // by default, pc always incremented by 4
        case (opcode)
            OP_R: begin
                reg_write = 1'b0;
                alu_op = calc_alu_op();
                alu_in2_moi = 1'b0; // reg in this case
            end
            OP_I: begin
                
            end
            OP_I_L: begin
                
            end
            OP_I_E: begin
                
            end
            OP_S: begin
                
            end
            OP_B: begin
                
            end
            OP_J: begin
                
            end
            OP_I_J: begin
                
            end
            OP_LUI: begin
                
            end
            OP_AUIPC: begin
                
            end
            default: begin
                
            end
        endcase
    end
    
endmodule

module immediate_generator (
    input Instruction instr,
    input ImmPackFmt imm_type,

    output Word imm_out
);

    always_comb begin
        case (imm_type)
            I: imm_out = {{21{instr[31]}}, instr[30:20]};
            S: imm_out = {{21{instr[31]}}, {instr[30:25], instr[11:7]}};
            B: imm_out = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
            U: imm_out = {instr[31:12], {12{1'b0}}};
            J: imm_out = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:25], instr[24:21], 1'b0};
            default: imm_out = {32{1'b0}};
        endcase 
    end

endmodule

module alu_decoder (
    input Instruction instr,
    output ALUOpType alu_op_type
);

endmodule
