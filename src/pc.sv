import rv32i::*;
localparam INST_BYTE_SIZE = DATA_WIDTH >> 3;

module pc(
    input logic clk,
    input logic rst_n,      // active low reset
    
    input logic pcinc_in1_pcor, // choose whether in1 of alu inc is pc or rs1
    input logic pcinc_in2_doi,  // choose whether in2 of alu inc is 4 (default) or imm

    input Word rs1_in,      // take rs1 if req
    input Word imm_in,      // take imm_in if req

    output Word pc_out      // pc output (cur val)
);

    Word pc;      // pc cur value
    Word pc_next; // pc next value

    always_comb begin
        Word in1;
        Word in2;
        if (pcinc_in1_pcor == 1'b0) in1 = pc;
        else in1 = rs1_in;
        if (pcinc_in2_doi == 1'b0) in2 = INST_BYTE_SIZE;    // default: 4
        else in2 = imm_in;
        pc_next = in1 + in2;
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= '0;
        end else begin
            pc <= pc_next;
        end
    end

    assign pc_out = pc;

endmodule