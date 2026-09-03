import rv32i::*;

module bht(
    // clock and reset
    input logic clk,
    input logic rst_n,
    // INPUTS:
    // pc index
    input PCIndex pc_index,         // PC index for selecting branch history (respective BHR), indexed by PC index bits
    // shifting in new history
    input logic bh_shift,           // if a new bit is to be shifted into the selected BHR
    input logic br_history_in,      // result to be shifted in (0 = NT, 1 = T)
    // overwriting hsitory
    input logic bh_overwrite,       // if the selected BHR is to be overwritten
    input BranchHistory bh_in,      // branch history to overwrite with
    // OUTPUTS:
    output BranchHistory bh_out     // output branch history of selected PC index
);

endmodule