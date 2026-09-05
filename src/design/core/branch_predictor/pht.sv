import rv32i::*;

module pht (
    // clock and reset
    input logic clk,
    input logic rst_n,
    // INPUTS:
    // branch history
    input BranchHistory read_bh_in,      // ph indexed by branch history
    // update confidence
    input logic update_conf,            // if confidence is to be updated for the selected entry
    input logic inc_or_dec,             // if conf to be incremented (1) or decremented (0)
    input BranchHistory write_bh_in,    // index a entry in BHR to update confidence (forwarding handled automatically and internally)
    // OUTPUTS:
    output BranchConfidenceState conf_state      // confidence state for branch prediction, indexed by bh_in
);

    BranchConfidenceState [PHT_ENTRY_C - 1 : 0] pht_table;
    BranchConfidenceState cur_read_entry;
    BranchConfidenceState cur_write_entry;
    BranchConfidenceState new_write_entry;

    always_comb begin

        // intialize default
        conf_state = STRONG_NT;
        cur_read_entry = pht_table[read_bh_in];
        cur_write_entry = pht_table[write_bh_in];
        new_write_entry = cur_write_entry;

        if (inc_or_dec) begin
            new_write_entry = (cur_write_entry == STRONG_T) ? STRONG_T : cur_write_entry + 1'b1;
        end else begin
            new_write_entry = (cur_write_entry == STRONG_NT) ? STRONG_NT : cur_write_entry - 1'b1;
        end
        if (update_conf && (read_bh_in == write_bh_in)) begin // forward new value if updation
            conf_state = new_write_entry;     
        end else begin
            conf_state = cur_read_entry;
        end
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pht_table <= '0;
        end else begin
            pht_table[write_bh_in] <= new_write_entry;
        end
    end

endmodule