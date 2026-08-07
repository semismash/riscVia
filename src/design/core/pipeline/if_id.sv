import rv32i::*;

module if_id (
    input logic clk;
    input logic rst_n;  // active low
    input logic stall;

    input Instruction instr;
    input Word pc;

    output Instruction instr;
    output Word pc;
);

    input logic [63:0] register;    // 64 bits = 32 (pc) + 32 (instr)
    input logic [63:0] next;

    always_comb begin
        next = {pc, instr};
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            register <= '0;
        end else if (!stall) begin  // do normal logic if NOT a stall
            register <= next;
        end
    end

endmodule