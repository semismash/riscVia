import rv32i::*;

module rv32i_core (
    input logic clk,           // CPU clock
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

    output logic halt,          // halt on panic
);
    reg_file u_reg_file(
        // clk and reset
        .clk            (),
        .rst_n          (), 
        // write
        .w_enable       (),
        .w_addr         (),
        .w_data         (),
        // read address
        .r_addr1        (),
        .r_addr2        (),
        // read data output
        .r_data1        (),
        .r_data2        ()
    );

    pc u_pc(
        // clk and reset
        .clk            (),
        .rst_n          (),
        // from decoder
        .pcinc_in1_pcor (),
        .pcinc_in2_doi  (),
        // from reg and imm gen, based on decoder signal
        .rs1_in         (),
        .imm_in         (),
        // out
        .pc_out         ()
    );

    fetch u_fetch(
        // IN
        .pc_in          (),
        .instr_in       (),
        .is_not_found   (),
        // OUT
        .mem_fetch_addr (),
        .instr_out      (),
        .mem_fault      ()
    );

    decoder u_decoder(
        // IN
        .instr          (),
        .alu_zero       (),
        // ALU
        .alu_op         (),
        .alu_in1_ropc   (),
        .alu_in2_roi    (),
        // LSU
        .reg_write      (),
        .mem_write      (),
        .mem_to_reg     (),
        // IMM GEN
        .imm_type       (),
        // PC
        .pcinc_in1_pcor (),
        .pcinc_in2_doi  ()
    );

    imm_gen u_imm_gen(
        // IN
        .instr          (),
        .imm_type       (),
        // OUT
        .imm_out        (),
    );

    alu u_alu(
        // from ID
        .alu_op         (),
        // from REG FILE
        .r_data1        (),
        .r_data2        (),
        //  from PC & ID
        .pc             (),
        .use_pc         (),
        // OUT
        .r_out          (),
        .out_zero       ()
    );

    lsu u_lsu(
        // IN
        .funct3         (),
        .alu_res        (),
        .is_mem_write   (),
        .rs2_in         (),
        .data_in        (),
        // OUT
        .mem_addr       (),
        .write_enable   (),
        .write_data     (),
        .req_bytes      (),
        .reg_data       ()
    );

endmodule