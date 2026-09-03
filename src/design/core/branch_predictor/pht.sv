import rv32i::*;

module pht (
    // clock and reset
    input logic clk,
    input logic rst_n,
    // INPUTS:
    // branch history
    input BranchHistory bh_in,      // ph indexed by branch history
    // update confidence
    input logic update_conf,            // if confidence is to be updated for the selected entry
    input logic inc_or_dec,             // if conf to be incremented (1) or decremented (0)
    input BranchHistory write_bh_in,    // index a entry in BHR to update confidence (forwarding handled automatically and internally)
    // OUTPUTS:
    input BranchConfidenceState conf_state      // confidence state for branch prediction, indexed by bh_in
);

endmodule