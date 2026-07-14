import rv32i::*;

module decoder #(
    parameter DATA_WIDTH = rv32i::DATA_WIDTH,
    parameter ADDR_WIDTH = rv32i::ADDR_WIDTH
) (
    input Instruction instr,    // instruction
    input logic alu_zero,       // feedback from ALU to resolve branch conditions

    // ALU
    output AluOp alu_op,        // alu specific operation
    output logic alu_in1_ropc,  // picks between alu first input being reg(0) or pc(1)
    output logic alu_in2_roi,   // picks between alu second input being reg(0) or imm(1)

    // LSU
    output logic reg_write,     // if it writes back to a register
    output logic mem_read,      // mem read signal to lsu
    output logic mem_write,     // if writes to data memory (for OP_S)
    output logic mem_to_reg,    // chooses between routing alu output (0) and data mem output from load (1) to reg file

    // IMM GEN
    output ImmPackFmt imm_type, // output imm type for imm gen

    // PC
    output logic pcinc_in1_pcor,    // PC inc input 1, default PC (0) or rs1 (1)
    output logic pcinc_in2_doi,     // PC inc input 2, default 4 (0) or IMM (1); PC = in1 + in2

    // panic
    output logic illegal_instr      // detects illegal instr, panics respectively
);

    import rv32i::*;

    OpCode opcode;

    function automatic AluOp calc_alu_op();

        logic [2:0] funct3;
        AluOp return_op;

        funct3 = instr[14:12];
        return_op = ADD;  //default add for safety

        case (funct3)
            3'b000: begin
                if (instr[30] == 1'b0) begin  // check bit 30 to verify add/sub
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
                if (instr[30] == 1'b0) begin  // check bit 30 to verify srl/sra
                    return_op = SRL;
                end else begin
                    return_op = SRA;
                end
            end
            3'b010: return_op = SLT;
            3'b011: return_op = SLTU;
            default: return_op = ADD;
        endcase

        return return_op;

    endfunction

    function void alu_bypass(); // alu_bypass alu
        alu_op = ADD;
        alu_in1_ropc = 1'bX;  
        alu_in2_roi = 1'bX;
    endfunction

    always_comb begin
        
        logic [2:0] funct3;

        opcode = OpCode'(instr[6:0]);

        alu_in1_ropc = 1'b0;    // by default, take alu 1 from register
        alu_in2_roi  = 1'b1;    // by default, take alu 2 from imm gen

        reg_write    = 1'b0;    // by default, dont write back to reg file
        mem_write    = 1'b0;    // by default, don't write to mem

        alu_op = ADD;           // default op is add
        mem_to_reg   = 1'b0;    // by default, always take from alu output to reg file

        pcinc_in1_pcor   = 1'b0;    // by default, always increment pc instead of set
        pcinc_in2_doi    = 1'b0;    // by default, pc always incremented by 4

        imm_type = N;
        illegal_instr = 1'b0;

        case (opcode)
            OP_R: begin // x
                reg_write = 1'b1; // write to reg file
                alu_op = calc_alu_op();
                alu_in2_roi = 1'b0; // take alu 2 reg in this case
            end
            OP_I: begin // x
                reg_write = 1'b1; 
                alu_op = calc_alu_op();
                imm_type = I;
            end
            OP_I_L: begin   // x
                reg_write = 1'b1; 
                mem_to_reg = 1'b1;  // route from data mem to reg file
                mem_read = 1'b1;
                imm_type = I;
            end
            OP_I_E: begin   
                alu_bypass();  // don't write to reg
                imm_type = I;
            end
            OP_S: begin 
                mem_write = 1'b1;
                imm_type = S;
            end
            OP_B: begin
                alu_in2_roi = 1'b0;
                funct3 = instr[14:12];
                case (funct3)
                    3'b000:  begin alu_op = XOR;  pcinc_in2_doi = alu_zero;  end // BEQ: jump if A^B == 0
                    3'b001:  begin alu_op = XOR;  pcinc_in2_doi = !alu_zero; end // BNE: jump if A^B != 0
                    3'b100:  begin alu_op = SLT;  pcinc_in2_doi = !alu_zero; end // BLT: jump if SLT result != 0
                    3'b101:  begin alu_op = SLT;  pcinc_in2_doi = alu_zero;  end // BGE: jump if SLT result == 0
                    3'b110:  begin alu_op = SLTU; pcinc_in2_doi = !alu_zero; end // BLTU: same as above but unsigned
                    3'b111:  begin alu_op = SLTU; pcinc_in2_doi = alu_zero;  end // BGEU
                    default: begin alu_op = ADD;  pcinc_in2_doi = 1'b0;      end
                endcase
                imm_type = B;
            end
            OP_J: begin
                reg_write = 1'b1; 
                alu_in1_ropc = 1'b1;    // input is PC instead
                pcinc_in2_doi = 1'b1;
                imm_type = J;
            end
            OP_I_J: begin
                reg_write = 1'b1; 
                alu_in1_ropc = 1'b1;
                pcinc_in1_pcor = 1'b1;
                pcinc_in2_doi  = 1'b1;  // PC = rs1 + imm
                imm_type = I;
            end
            OP_LUI: begin
                reg_write = 1'b1; 
                alu_bypass();
                imm_type = U;
            end
            OP_AUIPC: begin
                reg_write = 1'b1; 
                alu_in1_ropc = 1'b1;
                imm_type = U;
            end
            default: begin 
                illegal_instr = 1'b1;
            end
        endcase
    end
    
endmodule
