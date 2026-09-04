import rv32i::*;

module branch_validator (
    // INPUTS:
    // classification for misprediction
    input logic is_branch,
    input logic br_taken_predict,   // 1 is taken, 0 is not taken
    input logic br_taken_actual,    // 1 is taken, 0 is not taken
    // history bits from pipeline register
    //input logic new_history_bit,
    input BranchHistory old_history,
    input Word pc_addr,             // PC from pipeline register directly from EX phase
    input Word imm_val,             // immediate value from pipeline register in EX phase
    // OUTPUTS:
    // BHT
    output logic overwrite_bht,
    output BranchHistory restored_bh,
    // PHT
    output logic update_pht,
    output logic inc_or_dec,    // inc = 1, dec = 0
    // BTB
    output logic btb_write_en,
    output PCIndex pc_index_out,
    output PCTag pc_tag_out,
    output PCAddrNoUnused pc_tgt_out
);

    logic misprediction;
    assign misprediction = br_taken_predict != br_taken_actual;

    always_comb begin
        
        // intiailization
        overwrite_bht = 1'b0;
        restored_bh = '0;
        update_pht = 1'b0;
        inc_or_dec = 1'b0;
        btb_write_en = 1'b0;
        pc_index_out = '0;
        pc_tag_out = '0;
        pc_tgt_out = '0;

        if (is_branch && misprediction) begin
            // BHT
            overwrite_bht = 1'b1;
            restored_bh = old_history;          // also used by PHT
            // PHT
            update_pht = 1'b1;
            if (br_taken_actual) inc_or_dec = 1'b1;     // increment if branch was meant to be taken
            else inc_or_dec = 1'b0;                     // decrement if branch was not meant to be taken
            // BTB
            btb_write_en = 1'b1;
            pc_index_out = pc_addr[9:2];
            pc_tag_out = pc_addr[31:10];
            pc_tgt_out = pc_addr + imm_val;     // recalculates target like PC does for PC <= PC + imm, to be updated to old on mispreediction
        end

    end

endmodule