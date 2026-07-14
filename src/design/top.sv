import rv32i::*;

module top(
    input logic clk,    // clock
    input logic rst_n,  // active low reset
    output logic halt   // halt detect
);

    // from CPU
    Word if_addr        /* verilator public_flat_rw */;
    Word data_addr      /* verilator public_flat_rw */;
    Word write_data     /* verilator public_flat_rw */;
    logic write_enable  /* verilator public_flat_rw */;
    ReqBytes req_bytes  /* verilator public_flat_rw */;

    // to CPU
    Instruction instr;
    Word read_data;
    logic if_fault;
    logic data_fault;

    rv32i_core u_cpu(
        //clk and reset
        .clk(clk),
        .rst_n(rst_n),
        // IN
        .instr_in(instr),
        .data_in(read_data),
        .if_fault(if_fault),
        .data_fault(data_fault),
        // OUT
        .if_addr(if_addr),
        .data_addr(data_addr),
        .data_out(write_data), 
        .write_en(write_enable),
        .req_bytes(req_bytes),
        // HALT
        .halt(halt)
    );

    mem u_mem(
        // reset
        .clk(clk),
        // in
        .if_addr(if_addr),
        .lsu_addr(data_addr),
        .req_bytes(req_bytes),
        .write_enable(write_enable), 
        .data_in(write_data),
        // out
        .instr_out(instr),
        .data_out(read_data),
        // mem faults
        .if_not_found(if_fault),
        .lsu_not_found(data_fault)
    );

endmodule
