// stop unit (flip-flop) for debugging, and instruction counter too

module stop (
    input logic clk,
    input logic rst_n,
    input logic stop_in,
    input logic valid_instr,
    // output
    output logic stop_out,
    output logic [31:0] instr_count_out
);

    logic stop_signal;
    logic [31:0] instr_count;   // upto 2^32 instructions tracking

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            stop_signal <= 1'b0;
            instr_count <= '0;
        end else begin
            stop_signal <= stop_in;
            if (valid_instr) begin
                instr_count <= instr_count + 1'b1;
            end
        end
    end

    assign stop_out = stop_signal;
    assign instr_count_out = instr_count;

endmodule