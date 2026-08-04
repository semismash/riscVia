import rv32i::*;

module data_mem #(
    parameter MEM_SIZE_BYTES = 65536    // 64 KB instruction memory
) (
    input logic clk,                // clock signal

    input Word lsu_addr,            // data address
    input ReqBytes req_bytes,       // number of requested bytes by lsu

    input logic write_enable,       // enable write if high, only read by default
    input Word data_in,             // write to address of lsu_addr, write req_bytes bytes
    
    output logic data_not_found      // data not found

);

endmodule