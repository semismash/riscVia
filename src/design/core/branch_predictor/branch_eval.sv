import rv32i::*;

module branch_eval( // purely combinational
    // INPUTS:
    input BranchConfidenceState conf_state_in,  // from PHT
    input logic btb_hit,                        // from BTB
    input PCAddrNoUnused btb_target_addr,       // from BTB
    // OUTPUTS:
    output logic take_branch,               // (0 = don't take, 1 = take)
    output PCAddrNoUnused branch_addr       // update PC with target address
);

endmodule