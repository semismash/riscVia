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
);

    // for stalls (catches load-use early)
    assign dep_id_ex_rd_if_id_rs1 = (id_ex_rd == if_id_rs1);
    assign dep_id_ex_rd_if_id_rs2 = (id_ex_rd == if_id_rs2);

    // for forwarding
    assign dep_ex_mem_rd_id_ex_rs1 = (mem_wb_rd == id_ex_rs1);
    assign dep_ex_mem_rd_id_ex_rs2 = (mem_wb_rd == id_ex_rs2);
    
    assign dep_mem_wb_rd_id_ex_rs1 = (mem_wb_rd == id_ex_rs1);
    assign dep_mem_wb_rd_id_ex_rs2 = (mem_wb_rd == id_ex_rs2);

endmodule