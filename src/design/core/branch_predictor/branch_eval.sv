import rv32i::*;

module branch_eval( // purely combinational
    // INPUTS:
    input BranchConfidenceState conf_state_in,  // from PHT
    input logic btb_hit,                        // from BTB
    input BTBEntry btb_entry,                   // from BTB
    // OUTPUTS:
    output logic take_branch,               // (0 = don't take, 1 = take)
    output PCAddrNoUnused branch_addr       // update PC with target address
);

    always_comb begin
        take_branch = 1'b0;
        branch_addr = btb_entry.target_addr;
        if (btb_hit && (BranchConfidenceState == STRONG_T || BranchConfidenceState == WEAK_T)) take_branch = 1'b1;
    end

endmodule