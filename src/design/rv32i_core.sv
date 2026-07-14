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

    // decoder
    logic alu_or_mem_to_reg;
    logic illegal_instr;

    // imm
    Word imm_val;
    ImmPackFmt imm_type;

    // alu
    AluOp alu_op;
    logic alu_in1_sel;
    logic alu_in2_sel;
    logic alu_zero;
    Word alu_out;

    // lsu
    logic [2:0] funct3 = instr[14:12];
    logic mem_write;
    Word reg_write_data;

    // integrated
    assign rdst_addr = RegAddr'(instr[11:7]);
    assign rs1_addr = RegAddr'(instr[19:15]);
    assign rs2_addr = RegAddr'(instr[24:20]);

    // route reg data input write based on alu output or mem write output
    always_comb begin
        if (alu_or_mem_to_reg == 1'b0) rdst_data = alu_out;
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

    decoder u_decoder(
        // IN
        .instr          (instr),
        .alu_zero       (alu_zero),
        // ALU
        .alu_op         (alu_op),
        .alu_in1_ropc   (alu_in1_sel),
        .alu_in2_roi    (alu_in2_sel),
        // REG FILE
        .reg_write      (w_enable),
        // LSU
        .mem_write      (mem_write),
        .mem_to_reg     (alu_or_mem_to_reg),
        // IMM GEN
        .imm_type       (imm_type),
        // PC
        .pcinc_in1_pcor (pc_in1_sel),
        .pcinc_in2_doi  (pc_in2_sel),
        // panic
        .illegal_instr  (illegal_instr)
    );

    imm_gen u_imm_gen(  // x
        // IN
        .instr          (instr),
        .imm_type       (imm_type),
        // OUT
        .imm_out        (imm_val)
    );

    alu u_alu(  // x
        // from ID
        .alu_op         (alu_op),
        // from REG FILE
        .r_data1        (rs1_data),
        .r_data2        (rs2_data),
        //  from PC & ID
        .pc             (pc),
        .use_pc         (alu_in1_sel),
        // from IMM & ID
        .imm            (imm_val),
        .use_imm        (alu_in2_sel),  
        // OUT
        .alu_out        (alu_out),
        .out_zero       (alu_zero)
    );

    lsu u_lsu(
        // IN
        .funct3         (funct3),
        .alu_res        (alu_out),
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

    assign halt = if_fault_out | data_fault | illegal_instr;

endmodule
