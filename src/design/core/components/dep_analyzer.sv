module dep_analyzer (   // dependency analyzer
    // IF/ID
    input RegAddr if_id_rs1,
    input RegAddr if_id_rs2,
    // ID/EX
    input RegAddr id_ex_rs1,
    input RegAddr id_ex_rs2,
    input RegAddr id_ex_rd,
    // EX/MEM
    input RegAddr ex_mem_rd,
    // MEM/WB
    input RegAddr mem_wb_rd

    // outputs (naming scheme = dep_source_dest)
    // ID/EX
    output logic dep_id_ex_rd_if_id_rs1,
    output logic dep_id_ex_rd_if_id_rs2,
    // EX/MEM
    output logic dep_ex_mem_rd_id_ex_rs1,
    output logic dep_ex_mem_rd_id_ex_rs2,
    // MEM/WB
    output logic dep_mem_wb_rd_id_ex_rs1,
    output logic dep_mem_wb_rd_id_ex_rs1,

    // extra bits to check if its not zero regiter
    output logic if_id_rs1_not_x0,
    output logic if_id_rs2_not_x0,
    output logic id_ex_rd_not_x0,
    // check if rs1 or rs2 usage is even valid
    output logic rs1_valid,
    output logic rs2_valid,
);

    // for stalls (catches load-use early)
    assign dep_id_ex_rd_if_id_rs1 = (id_ex_rd == if_id_rs1);
    assign dep_id_ex_rd_if_id_rs2 = (id_ex_rd == if_id_rs2);

    // for forwarding
    assign dep_ex_mem_rd_id_ex_rs1 = (mem_wb_rd == id_ex_rs1);
    assign dep_ex_mem_rd_id_ex_rs2 = (mem_wb_rd == id_ex_rs2);
    
    assign dep_mem_wb_rd_id_ex_rs1 = (mem_wb_rd == id_ex_rs1);
    assign dep_mem_wb_rd_id_ex_rs2 = (mem_wb_rd == id_ex_rs2);

    // non-zero check
    assign if_id_rs1_not_x0 = (if_id_rs1 != '0);
    assign if_id_rs2_not_x0 = (if_id_rs2 != '0);
    assign id_ex_rd_not_x0  = (if_id_rd  != '0);

    // rs1 & rs2 validity check
    assign rs1_valid = 
        (if_id_opcode == OP_R)      ||
        (if_id_opcode == OP_I)      ||
        (if_id_opcode == OP_I_L)    ||
        (if_id_opcode == OP_S)      ||
        (if_id_opcode == OP_B)      ||
        (if_id_opcode == OP_I_J)    ||
        (if_id_opcode == OP_I_E);
    assign rs2_valid = 
        (if_id_opcode == OP_R)      ||
        (if_id_opcode == OP_S)      ||
        (if_id_opcode == OP_B);

endmodule