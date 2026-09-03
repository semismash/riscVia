import rv32i::*;

module bht(
    // clock and reset
    input logic clk,
    input logic rst_n,
    // INPUTS:
    // pc index
    input PCIndex read_pc_index,         // PC index for selecting branch history for read (respective BHR), indexed by PC index bits
    // shifting in new history
    input PCIndex write_pc_index,       // for writing and overwriting
    input logic bh_shift,           // if a new bit is to be shifted into the selected BHR
    input logic br_history_in,      // result to be shifted in (0 = NT, 1 = T)
    // overwriting hsitory
    input logic bh_overwrite,       // if the selected BHR is to be overwritten
    input BranchHistory bh_in,      // branch history to overwrite with
    // OUTPUTS:
    output BranchHistory bh_out     // output branch history of selected PC index
);

    BranchHistory [BHT_ENTRY_C - 1 : 0] bht_table;
    BranchHistory cur_read_bhr;
    BranchHistory cur_write_bhr;
    BranchHistory new_write_bhr;

    always_comb begin

        // initializing
        bh_out = '0;
        cur_read_bhr = bh_in[read_pc_index];
        cur_write_bhr = bh_in[write_pc_index];
        new_write_bhr = cur_write_bhr;

        if (bh_overwrite) begin
            new_write_bhr = bh_in;
        end else if (bh_shift) begin
            new_write_bhr = {br_history_in, cur_write_bhr[HISTORY_BIT_C - 1 : 1]}
        end
        bh_out = cur_read_bhr;
        
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            cur_write_bhr <= '0;
        end else begin
            cur_write_bhr <= new_write_bhr;
        end
    end

endmodule