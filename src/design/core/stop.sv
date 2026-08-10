// stop unit (flip-flop) for debugging

module stop (
    input logic clk,
    input logic rst_n,
    input logic stop_in,
    // output
    output logic stop_out,
);

    logic stop_signal;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            stop_signal <= 1'b0;
        end else begin
            stop_signal <= stop_in;
        end
    end

    assign stop_out = stop_signal;

endmodule