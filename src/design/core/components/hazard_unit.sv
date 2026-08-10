import rv32i::*;

module hazard_unit (    // currently, stalls for both control and data hazards
    input OpCode    if_id_opcode,  // take instruction opcode to check inst type and prevent false stalls
    // IF/ID
    input RegAddr   if_id_rs1,
    input RegAddr   if_id_rs2,
    // ID/EX
    input logic     id_ex_mem_read,
    input RegAddr   id_ex_rdst,
    input logic     branch_taken,
    // EX/MEM
    input logic     ex_mem_reg_write,
    input RegAddr   ex_mem_rdst,
    // MEM/WB
    input logic     mem_wb_reg_write,
    input RegAddr   mem_wb_rdst,

    output logic    pc_enable,
    output logic    if_id_enable,
    output logic    if_id_clear,
    output logic    id_ex_clear
);

    // 1. Control Hazard - when branch detected in ID/EX - clear and stall IF/ID for one cycle
    // 2. Data Hazard - load hazard with no gap b/w use inst (scan IF/ID and ID/EX) - stall till hazard resolved
    /* 3. Data Hazard - non-load hazard or load hazard with instruction gap (scan ID/EX, EX/MEM and MEM/WB) 
        - stall till hazard resolved but replace with forwarding later*/

    logic rs1_used;
    logic rs2_used;
    logic rs1_hazard_ex_mem;
    //logic rs1_hazard_mem_wb;
    logic rs2_hazard_ex_mem;
    //logic rs2_hazard_mem_wb;

    always_comb begin
        pc_enable = 1'b1;
        if_id_enable = 1'b1;
        if_id_clear = 1'b0;
        id_ex_clear = 1'b0;

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

        if (branch_taken) begin // Condition 1
            if_id_clear = 1'b1;
            id_ex_clear = 1'b1;
        // Condition 2, create bubble by freezing
        end else if (id_ex_mem_read && (id_ex_rdst != '0) && 
                ((rs1_used && (id_ex_rdst == if_id_rs1)) || (rs2_used && (id_ex_rdst == if_id_rs2)))) begin
            pc_enable    = 1'b0;
            if_id_enable = 1'b0;
            id_ex_clear  = 1'b1;
        // Condition 3, create a bubble
        end else if (rs1_hazard_ex_mem || rs2_hazard_ex_mem) begin
            pc_enable    = 1'b0;
            if_id_enable = 1'b0;
            id_ex_clear  = 1'b1;
        end
    end

endmodule