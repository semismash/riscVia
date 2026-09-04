import rv32i::*;

module branch_predictor(
    // clk and reset
    input logic clk,
    input logic rst_n,
    // INPUTS:
    // from instruction fetch stage
    input Instruction instr,
    input Word pc,
    // from ID/EX pipeline reg and EX phase for validating branch
    input logic ex_is_branch,
    input logic ex_br_taken_predict,
    input logic ex_br_taken_actual,
    input BranchHistory ex_br_history,
    // OUTPUTS:
    // to PC
    output logic pc_update,                 // high when branch taken
    output Word pc_val,                     // override PC input accordingly to set to new value
    // to IF/ID
    output logic is_branch_out,             // to IF/ID
    output BranchHistory br_history_out,    // to IF/ID
);

    logic OpCode opcode;
    logic PCIndex pc_index; // 8 pc index bits
    logic PCTag pc_tag;     // 22 pc tag bits

    always_comb begin

        opcode = instr[6:0];
        pc_index = pc[9:2];
        pc_tag = pc[31:10];

        if (opcode == OP_B) begin   // check if branch instruction
            is_branch_out = 1'b1;
        end

    end

    // connection ports
    logic bh_history;
    logic ph_conf_state;

    logic btb_hit;
    BTBEntry btb_data;

    bht u_bht (
        // clock and reset
        .clk               (clk),       // X
        .rst_n             (rst_n),     // X
        // INPUTS:
        .read_pc_index     (pc_index),  // X
        // shifting in new history
        .write_pc_index    (write_pc_index),
        .bh_shift          (bh_shift),
        .br_history_in     (br_history_in),
        // overwriting hsitory
        .bh_overwrite      (bh_overwrite),
        .bh_in             (bh_in),
        // OUTPUTS:
        .bh_out            (bh_history)     // X

    );

    assign br_history_out = bh_history;

    pht u_pht (
        // clock and reset
        .clk            (clk),      // X
        .rst_n          (rst_n),    // X
        // INPUTS:
        .read_bh_in     (bh_history),   // X
        // update confidence
        .update_conf    (update_conf),
        .inc_or_dec     (inc_or_dec),
        .write_bh_in    (write_bh_in),
        // OUTPUTS:
        .conf_state     (ph_conf_state) // X
    );

    btb u_btb (
        // clock and reset
        .clk             (clk),         // X
        .rst_n           (rst_n),       // X
        // INPUTS:
        .access_index    (pc_index),    // X
        .read_tag        (pc_tag),      // X
        // for writing to cache
        .write_enable    (write_enable),
        .write_index     (write_index),
        .write_tag       (write_tag),
        .write_tgt       (write_tgt),
        // OUTPUTS:
        .cache_hit       (btb_hit),     // X
        .data_out        (btb_data)     // X
    );

    branch_eval u_branch_eval (
        // INPUTS:
        .conf_state_in    (ph_conf_state),  // from PHT (X)
        .btb_hit          (btb_hit),        // from BTB (X)
        .btb_entry        (btb_data),       // from BTB (X)
        // OUTPUTS:
        .take_branch      (is_branch_out),  // X
        .branch_addr      (pc_addr)         // X    
    );

endmodule