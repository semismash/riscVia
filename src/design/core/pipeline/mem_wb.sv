import rv32i::*;

module if_id #(
    parameter REG_WIDTH = 38    // 38 bits
) (
    input logic clk,
    input logic rst_n,  // active low
    input logic stall,

    input RegAddr rd_addr,      // 5 bits
    input Word rd_data,         // 32 bits
    input logic reg_write,      // 1 bit

    output RegAddr rd_addr,
    output Word rd_data,
    output logic reg_write
);

    logic [REG_WIDTH-1:0] register;
    logic [REG_WIDTH-1:0] next;

    always_comb begin
        next = 
        {rs2_val,
        rd_addr,
        result,
        alu_zero,
        mem_read,
        mem_write,
        funct3,
        reg_write,
        mem_to_reg};
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            register <= '0;
        end else if (!stall) begin  // do normal logic if NOT a stall
            register <= next;
        end
    end

endmodule