module fwd_unit (
    // Dependencies
    // ID/EX
    input logic dep_id_ex_rd_if_id_rs1,
    input logic dep_id_ex_rd_if_id_rs2,
    // EX/MEM
    input logic dep_ex_mem_rd_id_ex_rs1,
    input logic dep_ex_mem_rd_id_ex_rs2,
    // MEM/WB
    input logic dep_mem_wb_rd_id_ex_rs1,
    input logic dep_mem_wb_rd_id_ex_rs1,
    // 
);

    // Conditions for forwarding
    /*
    1. If EX/MEM[rd] == ID/EX[rs1 | rs2] for R/I type instructions
    2. If MEM/WB[rd] == ID/EX[rs1 | rs2] for R/I type instructions
    3. If MEM/WB[rd] == ID/EX[rs1 | rs2] for load type instructions
    */

    

endmodule