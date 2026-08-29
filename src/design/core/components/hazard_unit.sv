import rv32i::*;

module hazard_unit (    // currently, stalls for both control and data hazards
    input OpCode    if_id_opcode,  // take instruction opcode to check inst type and prevent false stalls
    // IF/ID
    input RegAddr   if_id_rs1,
    input RegAddr   if_id_rs2,
    // ID/EX
    input logic     id_ex_mem_read,
    input logic     id_ex_reg_write,
    input RegAddr   id_ex_rdst,
    input logic     branch_taken,
    // EX/MEM
    input logic     ex_mem_reg_write,
    input RegAddr   ex_mem_rdst,
    // MEM/WB
    input logic     mem_wb_reg_write,
    input RegAddr   mem_wb_rdst,
    // outputs
    output logic    pc_enable,
    output logic    if_id_enable,
    output logic    if_id_clear,
    output logic    id_ex_clear,
    // forwarding
    output logic    cond_l_use_1gp, // condition load-use 1 instruction gap (forwarding unit)
    output logic    cond_raw_other, // condition for other RAW hazard (forwarding unit)
    // metadata
    output logic    meta_is_stall,
    output logic    meta_is_l_use,
    output logic    meta_branch_flush
);

    // 1. Control Hazard - when branch detected in ID/EX - clear and stall IF/ID for one cycle
    /* 2. Data Hazard - load-use hazard with (a) 0 instruction gap or (b) 1 instruction gap use inst (scan IF/ID and ID/EX) - 
        stall till hazard resolved */
    // 3. Data Hazard - non-load hazard (scan ID/EX, EX/MEM and MEM/WB) - stall till hazard resolved but replace with forwarding later

    logic rs1_used;
    logic rs2_used;
    logic rs1_hazard_ex_mem;
    //logic rs1_hazard_mem_wb;
    logic rs2_hazard_ex_mem;
    //logic rs2_hazard_mem_wb;
    logic raw_hazard_id_ex;   // true whenever id_ex's rdst matches what if_id needs (load or non-load)
    logic condition_2a;       // load-use subset of raw_hazard_id_ex
    logic condition_2b;       // non-load subset of raw_hazard_id_ex

    always_comb begin
        pc_enable = 1'b1;
        if_id_enable = 1'b1;
        if_id_clear = 1'b0;
        id_ex_clear = 1'b0;

        meta_is_stall = 1'b0;
        meta_is_l_use = 1'b0;
        meta_branch_flush = 1'b0;

        // check if rs1 or rs2 are used by the instruction, performance guardrail to prevent unnecessary stalls
        rs1_used = 
            (if_id_opcode == OP_R) ||
            (if_id_opcode == OP_I) ||
            (if_id_opcode == OP_I_L) ||
            (if_id_opcode == OP_S) ||
            (if_id_opcode == OP_B) ||
            (if_id_opcode == OP_I_J) ||
            (if_id_opcode == OP_I_E);
        rs2_used = 
            (if_id_opcode == OP_R) ||
            (if_id_opcode == OP_S) ||
            (if_id_opcode == OP_B);

        // for condition 3 data hazards
        rs1_hazard_ex_mem = rs1_used && (if_id_rs1 != '0) && ex_mem_reg_write && (if_id_rs1 == ex_mem_rdst);
        //rs1_hazard_mem_wb = rs1_used && (if_id_rs1 != '0) && mem_wb_reg_write && (if_id_rs1 == mem_wb_rdst);
        rs2_hazard_ex_mem = rs2_used && (if_id_rs2 != '0) && ex_mem_reg_write && (if_id_rs2 == ex_mem_rdst);
        //rs2_hazard_mem_wb = rs2_used && (if_id_rs2 != '0) && mem_wb_reg_write && (if_id_rs2 == mem_wb_rdst);

        // shared checks if if/id data required collides with if/ex, hence raises hazard early
        raw_hazard_id_ex = id_ex_reg_write && (id_ex_rdst != '0) &&
            ((rs1_used && (id_ex_rdst == if_id_rs1)) || (rs2_used && (id_ex_rdst == if_id_rs2)));

        condition_2a = id_ex_mem_read  && raw_hazard_id_ex;   // true load-use hazard
        condition_2b = !id_ex_mem_read && raw_hazard_id_ex;   // non-load RAW hazard (no forwarding implemetned yet)

        if (branch_taken) begin // Condition 1
            if_id_clear = 1'b1;
            id_ex_clear = 1'b1;
            meta_branch_flush = 1'b1;
        // Condition 2a, true load-use hazard: create bubble by freezing
        end else if (condition_2a) begin
            pc_enable     = 1'b0;
            if_id_enable  = 1'b0;
            id_ex_clear   = 1'b1;
            meta_is_stall = 1'b1;
            meta_is_l_use = 1'b1;
        // Condition 2b, non-load RAW hazard from EX stage (no forwarding yet): create bubble by freezing
        end else if (condition_2b) begin
            pc_enable     = 1'b0;
            if_id_enable  = 1'b0;
            id_ex_clear   = 1'b1;
            meta_is_stall = 1'b1;
        // Condition 3, create a bubble
        end else if (rs1_hazard_ex_mem || rs2_hazard_ex_mem) begin
            pc_enable     = 1'b0;
            if_id_enable  = 1'b0;
            id_ex_clear   = 1'b1;
            meta_is_stall = 1'b1;
        end
    end

endmodule/