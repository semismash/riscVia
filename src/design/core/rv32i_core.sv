import rv32i::*;

module rv32i_core (
    input logic clk,            // CPU clock
    input logic rst_n,          // active low reset

    input Instruction instr_in, // next instruction (MEM -> FU)
    input Word data_in,         // input data from (MEM -> LSU)
    input logic if_fault,       // instruction fetch fault (MEM -> FU)
    input logic data_fault,     // data fetch fault (MEM) 

    output Word if_addr,        // instruction fetch address (FU)
    output Word data_addr,      // data address (LSU)
    output Word data_out,       // data out (LSU)    
    output logic write_en,      // write enable (LSU)
    output ReqBytes req_bytes,  // requested bytes amount (LSU)

    output logic halt           // halt on panic
);

    // fetch
    logic if_fault_out;
    Instruction instr;

    // Reg File
    logic   w_enable;
    RegAddr rdst_addr;
    Word    rdst_data;
    RegAddr rs1_addr;
    RegAddr rs2_addr;
    Word    rs1_data;
    Word    rs2_data;

    // PC
    Word pc;
    logic pc_in1_sel;
    logic pc_in2_sel;

    // IF/ID
    Word if_id_pc;
    Instruction if_id_instr;

    // decoder
    logic alu_or_mem_to_reg;
    logic imm_to_reg;        
    logic illegal_instr;

    // imm
    Word imm_val;
    ImmPackFmt imm_type;

    // ID/EX
    Word id_ex_pc;
    RegAddr id_ex_rs1_addr;
    RegAddr id_ex_rs2_addr;
    RegAddr id_ex_rd_addr;
    Word id_ex_rs1_data;
    Word id_ex_rs2_data;
    logic id_ex_alu_in1_pcor;
    logic id_ex_alu_in2_roi;    // reconsider this, replace with branch taken condition later on
    AluOp id_ex_alu_op;
    logic id_ex_alu_bypass;
    logic id_ex_mem_read;
    logic id_ex_mem_write;
    logic [2:0] id_ex_funct3;
    logic id_ex_is_branch;
    logic id_ex_reg_write;
    logic id_ex_imm_to_reg;
    logic id_ex_mem_to_reg;

    // alu
    AluOp alu_op;
    logic alu_in1_sel;
    logic alu_in2_sel;
    logic alu_zero;
    Word alu_out;

    // EX/MEM
    logic ex_mem_rs2_val;
    RegAddr ex_mem_rd_addr;
    Word ex_mem_result;
    logic ex_mem_mem_read;
    logic ex_mem_mem_write;
    logic [2:0] ex_mem_funct3;
    logic ex_mem_reg_write;
    logic ex_mem_mem_to_reg;

    // lsu
    logic [2:0] funct3;
    logic mem_read;
    logic mem_write;
    Word reg_write_data;

    // MEM/WB
    RegAddr mem_wb_rd_addr;
    Word mem_wb_rd_data;
    logic mem_wb_reg_write;

    // integrated
    assign funct3 = instr[14:12];
    assign rdst_addr = RegAddr'(instr[11:7]);
    assign rs1_addr = RegAddr'(instr[19:15]);
    assign rs2_addr = RegAddr'(instr[24:20]);

    // route reg data input write based on imm (LUI), alu output, or mem write output
    always_comb begin
        if (imm_to_reg == 1'b1) rdst_data = imm_val;          // lui now bypasses alu
        else if (alu_or_mem_to_reg == 1'b0) rdst_data = alu_out;
        else rdst_data = reg_write_data;
    end

    reg_file u_reg_file(
        // clk and reset
        .clk            (clk),
        .rst_n          (rst_n), 
        // write
        .w_enable       (w_enable),
        .w_addr         (rdst_addr),
        .w_data         (rdst_data),
        // read address
        .r_addr1        (rs1_addr),
        .r_addr2        (rs2_addr),
        // reg data output
        .r_data1        (rs1_data),
        .r_data2        (rs2_data)
    );

    pc u_pc(    // x
        // clk and reset
        .clk            (clk),
        .rst_n          (rst_n),
        // from decoder
        .pcinc_in1_pcor (pc_in1_sel),
        .pcinc_in2_doi  (pc_in2_sel),
        // from reg and imm gen, based on decoder signal
        .rs1_in         (rs1_data),
        .imm_in         (imm_val),
        // out
        .pc_out         (pc)
    );

    hazard_unit u_hazard_unit (
        // input
        .if_id_opcode       (  ),
        .if_id_rs1          (  ),
        .if_id_rs2          (  ),
        .id_ex_mem_read     (  ),
        .id_ex_rdst         (  ),
        .branch_taken       (  ),
        .ex_mem_reg_write   (  ),
        .ex_mem_rdst        (  ),
        .mem_wb_reg_write   (  ),
        .mem_wb_rdst        (  ),
        // output
        .pc_enable          (  ),
        .if_id_enable       (  ),
        .if_id_clear        (  ),
        .id_ex_clear        (  )
    );

    fetch u_fetch(  // x
        // IN
        .pc_in          (pc),
        .instr_in       (instr_in),
        .is_not_found   (if_fault),
        // OUT
        .mem_fetch_addr (if_addr),
        .instr_out      (instr),
        .mem_fault      (if_fault_out)
    );

    if_id u_if_id (
        // clk and reset
        .clk      (clk),
        .rst_n    (rst_n),
        .stall    (  ),
        .clear    (  ),
        // input
        .i_pc     (pc),
        .i_instr  (instr),
        // output
        .o_pc     (if_id_pc),
        .o_instr  (if_id_instr)
    );

    decoder u_decoder(
        // IN
        .instr          (if_id_instr),
        .alu_zero       (alu_zero),
        // ALU
        .alu_op         (alu_op),
        .alu_in1_ropc   (alu_in1_sel),
        .alu_in2_roi    (alu_in2_sel),
        // REG FILE
        .reg_write      (w_enable),
        // LSU
        .mem_read       (mem_read),
        .mem_write      (mem_write),
        .mem_to_reg     (alu_or_mem_to_reg),
        .imm_to_reg     (imm_to_reg),
        // IMM GEN
        .imm_val        (imm_val),
        // PC
        .pcinc_in1_pcor (pc_in1_sel),
        .pcinc_in2_doi  (pc_in2_sel),
        // panic
        .illegal_instr  (illegal_instr)
    );

    id_ex u_id_ex (
        // clk and reset
        .clk              (clk),
        .rst_n            (rst_n),
        .stall            (  ),
        .clear            (  ),
        // input
        .i_pc             (  ),
        .i_rs1_addr       (  ),
        .i_rs2_addr       (  ),
        .i_rd_addr        (  ),
        .i_rs1_data       (  ),
        .i_rs2_data       (  ),
        .i_alu_in1_pcor   (  ),
        .i_alu_in2_roi    (  ),
        .i_alu_op         (  ),
        .i_alu_bypass     (  ),
        .i_mem_read       (  ),
        .i_mem_write      (  ),
        .i_funct3         (  ),
        .i_is_branch      (  ),
        .i_reg_write      (  ),
        .i_imm_to_reg     (  ),
        .i_mem_to_reg     (  ),
        // output
        .o_pc             (id_ex_pc),
        .o_rs1_addr       (id_ex_rs1_addr),
        .o_rs2_addr       (id_ex_rs2_addr),
        .o_rd_addr        (id_ex_rd_addr),
        .o_rs1_data       (id_ex_rs1_data),
        .o_rs2_data       (id_ex_rs2_data),
        .o_alu_in1_pcor   (id_ex_alu_in1_pcor),
        .o_alu_in2_roi    (id_ex_alu_in2_roi),
        .o_alu_op         (id_ex_alu_op),
        .o_alu_bypass     (id_ex_alu_bypass),
        .o_mem_read       (id_ex_mem_read),
        .o_mem_write      (id_ex_mem_write),
        .o_funct3         (id_ex_funct3),
        .o_is_branch      (id_ex_is_branch),
        .o_reg_write      (id_ex_reg_write),
        .o_imm_to_reg     (id_ex_imm_to_reg),
        .o_mem_to_reg     (id_ex_mem_to_reg)
    );

    alu u_alu(  // x
        // from ID
        .alu_op         (alu_op),
        // from REG FILE
        .r_data1        (rs1_data),
        .r_data2        (rs2_data),
        // from PC & ID
        .pc             (pc),
        .use_pc         (alu_in1_sel),
        // from IMM & ID
        .imm            (imm_val),
        .use_imm        (alu_in2_sel),  
        // OUT
        .alu_out        (alu_out),
        .out_zero       (alu_zero)
    );

    branch_unit u_branch_unit (
        .is_branch    (  ),
        .id_ex_funct3 (  ),
        .alu_zero     (  ),
        .branch_taken (  )
    );

    ex_mem u_ex_mem (
        // clk and reset
        .clk          (clk),
        .rst_n        (rst_n),
        .stall        (  ),
        .clear        (  ),
        // input
        .i_rs2_val    (  ),
        .i_rd_addr    (  ),
        .i_result     (  ),
        .i_mem_read   (  ),
        .i_mem_write  (  ),
        .i_funct3     (  ),
        .i_reg_write  (  ),
        .i_mem_to_reg (  ),
        // output
        .o_rs2_val    (ex_mem_rs2_val),
        .o_rd_addr    (ex_mem_rd_addr),
        .o_result     (ex_mem_result),
        .o_mem_read   (ex_mem_mem_read),
        .o_mem_write  (ex_mem_mem_write),
        .o_funct3     (ex_mem_funct3),
        .o_reg_write  (ex_mem_reg_write),
        .o_mem_to_reg (ex_mem_mem_to_reg)
    );

    lsu u_lsu(
        // IN
        .funct3         (funct3),
        .alu_res        (alu_out),
        .is_mem_read    (mem_read),
        .is_mem_write   (mem_write),
        .rs2_in         (rs2_data),
        .data_in        (data_in),
        // OUT
        .mem_addr       (data_addr),
        .write_enable   (write_en),
        .write_data     (data_out),
        .req_bytes      (req_bytes),
        .reg_data       (reg_write_data)
    );

    mem_wb u_mem_wb (
        // clk
        .clk         (clk),
        .rst_n       (rst_n),
        .stall       (  ),
        .clear       (  ),
        // input
        .i_rd_addr   (  ),
        .i_rd_data   (  ),
        .i_reg_write (  ),
        // output
        .o_rd_addr   (mem_wb_rd_addr),
        .o_rd_data   (mem_wb_rd_data),
        .o_reg_write (mem_wb_reg_write)
    );

    assign halt = if_fault_out | data_fault | illegal_instr;

endmodule