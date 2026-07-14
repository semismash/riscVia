import rv32i::*;

module alu #(
    parameter DATA_WIDTH = rv32i::DATA_WIDTH,
    parameter ADDR_WIDTH = rv32i::ADDR_WIDTH
)(
    input AluOP alu_op,

    input Word r_data1,
    input Word r_data2,

    input Word pc,
    input logic use_pc,     // switch between r_data1 (0) or pc (1) for data1

    input Word imm,
    input logic use_imm,    // switch between r_data2 (0) or imm (1) for data2

    output Word alu_out,
    output logic out_zero
);

    Word data1;
    Word data2;

    always_comb begin
        if (use_pc == 1'b0) data1 = r_data1;
        else data1 = pc;
        case (alu_op)
            ADD: r_out = data1 + r_data2;
            SUB: r_out = data1 - r_data2;
            XOR: r_out = data1 ^ r_data2;
            OR:  r_out = data1 | r_data2;
            AND: r_out = data1 & r_data2;
            SLL: r_out = data1 << r_data2[ADDR_WIDTH-1:0];
            SRL: r_out = data1 >> r_data2[ADDR_WIDTH-1:0];
            SRA: r_out = $signed(data1) >>> r_data2[ADDR_WIDTH-1:0];
            STL: r_out = ($signed(data1) < $signed(r_data2)) ? 1 : 0;
            STLU: r_out = (data1 < r_data2) ? 1 : 0;
            default: r_out = 0;
        endcase
    end

    assign out_zero = (r_out == 0); // set less than flag is always inverse of zero flag

endmodule