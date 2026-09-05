import rv32i::*;

module branch_predictor (
    // clk and reset
    input logic clk,
    input logic rst_n,
    // INPUTS:
    // from instruction fetch stage
    input Instruction instr,
    input Word pc,
    // from ID/EX pipeline reg and EX phase for validating branch prediction
    input Word ex_pc,
    input logic ex_is_branch,
    input logic ex_br_taken_predict,
    input logic ex_br_taken_actual,
    input BranchHistory ex_br_history,  // OLD "correct" history carried from IF, used to restore/index on misprediction
    input logic ex_btb_hit,
    input Word ex_br_target,
    // OUTPUTS:
    // to PC
    output logic branch_taken,      // high when branch taken (also to IF/ID)
    output Word pc_addr,             // override PC input accordingly to set to new value
    // to IF/ID
    output logic is_branch_out,             // to IF/ID
    output BranchHistory br_history_out,    // to IF/ID 
    output logic btb_hit_out
);

    OpCode  opcode;
    PCIndex pc_index; // 8 pc index bits
    PCTag   pc_tag;   // 22 pc tag bits

    // connection ports
    BranchHistory bh_history;    // current bht read for pc_index
    BranchConfidenceState ph_conf_state;
    logic btb_hit;
    BTBEntry btb_data;
    logic take_branch;
    PCAddrNoUnused branch_target;

    logic misprediction;
    assign misprediction = ex_is_branch && (ex_br_taken_predict != ex_br_taken_actual);

    // SPECULATION
    PCIndex bht_write_index;
    logic bh_shift;
    logic br_history_in;
    logic bh_overwrite;

    // VERIFICATION
    logic update_conf;
    logic conf_inc_or_dec;
    logic btb_write_en;
    PCIndex btb_write_index;
    PCTag btb_write_tag;
    PCAddrNoUnused btb_write_tgt;

    always_comb begin

        // decode
        opcode = instr[6:0];
        pc_index = pc[9:2];
        pc_tag = pc[31:10];

        // intiailzie
        is_branch_out = 1'b0;
        branch_taken = 1'b0;
        btb_hit_out = 1'b0;
        pc_addr = pc + 32'd4;   // pc is + 4 extra

        // if stage prediction
        if (opcode == OP_B) begin
            is_branch_out = 1'b1;
            btb_hit_out = btb_hit;
            branch_taken = take_branch;
            if (branch_taken) begin
                pc_addr = {branch_target, 2'b00}; // append 00 at the end to get back full address
            end
        end

        if (misprediction) begin
            bht_write_index = ex_pc[9:2];
            bh_overwrite = 1'b1;
            bh_shift = 1'b0;
            br_history_in = 1'b0;
        end else begin
            bht_write_index = pc_index;
            bh_overwrite = 1'b0;
            bh_shift = is_branch_out;
            br_history_in = take_branch;
        end

        // pht update
        update_conf = misprediction;
        conf_inc_or_dec = ex_br_taken_actual; // increment if actually taken, decrement if actually not taken
        // btb update
        btb_write_en = misprediction;
        btb_write_index = ex_pc[9:2];
        btb_write_tag = ex_pc[31:10];
        btb_write_tgt = ex_br_target[31:2];

    end

    bht u_bht (
        // clock and reset
        .clk               (clk),
        .rst_n             (rst_n),
        // INPUTS:
        .read_pc_index     (pc_index),
        // shifting in new history
        .write_pc_index    (bht_write_index),
        .bh_shift          (bh_shift),
        .br_history_in     (br_history_in),
        // overwriting history
        .bh_overwrite      (bh_overwrite),
        .bh_in             (ex_br_history),
        // OUTPUTS:
        .bh_out            (bh_history)
    );

    assign br_history_out = bh_history;

    pht u_pht (
        // clock and reset
        .clk            (clk),
        .rst_n          (rst_n),
        // INPUTS:
        .read_bh_in     (bh_history),
        // update confidence
        .update_conf    (update_conf),
        .inc_or_dec     (conf_inc_or_dec),
        .write_bh_in    (ex_br_history),
        // OUTPUTS:
        .conf_state     (ph_conf_state)
    );

    btb u_btb (
        // clock and reset
        .clk             (clk),
        .rst_n           (rst_n),
        // INPUTS:
        .access_index    (pc_index),
        .read_tag        (pc_tag),
        // for writing to cache
        .write_enable    (btb_write_en),
        .write_index     (btb_write_index),
        .write_tag       (btb_write_tag),
        .write_tgt       (btb_write_tgt),
        // OUTPUTS:
        .cache_hit       (btb_hit),
        .data_out        (btb_data)
    );

    branch_eval u_branch_eval (
        // INPUTS:
        .conf_state_in    (ph_conf_state),
        .btb_hit          (btb_hit),
        .btb_entry        (btb_data),
        // OUTPUTS:
        .take_branch      (take_branch),
        .branch_addr      (branch_target)
    );

endmodule