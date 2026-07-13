import rv32i::*;

module alu #(
    parameter DATA_WIDTH = rv32i::DATA_WIDTH,
    parameter ADDR_WIDTH = rv32i::ADDR_WIDTH
)(
    input AluOP alu_op,

    input logic [DATA_WIDTH-1:0] r_data1,
    input logic [DATA_WIDTH-1:0] r_data2,

    output logic [DATA_WIDTH-1:0] r_out,
    output logic out_zero
);

    always_comb begin
        case (alu_op)
            ADD: r_out = r_data1 + r_data2;
            SUB: r_out = r_data1 - r_data2;
            XOR: r_out = r_data1 ^ r_data2;
            OR:  r_out = r_data1 | r_data2;
            AND: r_out = r_data1 & r_data2;
            SLL: r_out = r_data1 << r_data2[ADDR_WIDTH-1:0];
            SRL: r_out = r_data1 >> r_data2[ADDR_WIDTH-1:0];
            SRA: r_out = $signed(r_data1) >>> r_data2[ADDR_WIDTH-1:0];
            STL: r_out = ($signed(r_data1) < $signed(r_data2)) ? 1 : 0;
            STLU: r_out = (r_data1 < r_data2) ? 1 : 0;
            default: r_out = 0;
        endcase
    end

    assign out_zero = (r_out == 0); // set less than flag is always inverse of zero flag

endmodule