import rv32i::*;

module if_id #(
    parameter REG_WIDTH = 64    // 64 bits = 32 (pc) + 32 (instr)
) (
    input logic clk,
    input logic rst_n,  // active low
    input logic stall,

    input Word pc,
    input Instruction instr,

    output Word pc,
    output Instruction instr
);

    logic [REG_WIDTH-1:0] register;
    logic [REG_WIDTH-1:0] next;

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