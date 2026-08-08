import rv32i::*;

module branch_unit (
    input logic is_branch,
    input logic [2:0] id_ex_funct3,
    input logic alu_zero,
    
    output logic branch_taken,
);

    always_comb begin
        case (id_ex_funct3)
            3'b000:  branch_passed = alu_zero_out;   // BEQ
            3'b001:  branch_passed = !alu_zero_out;  // BNE
            3'b100:  branch_passed = !alu_zero_out;  // BLT
            3'b101:  branch_passed = alu_zero_out;   // BGE
            3'b110:  branch_passed = !alu_zero_out;  // BLTU
            3'b111:  branch_passed = alu_zero_out;   // BGEU
            default: branch_passed = 1'b0;
        endcase
    end

    // do branch taken only if actually a branch instruction
    assign branch_taken = is_branch && branch_passed;

endmodule