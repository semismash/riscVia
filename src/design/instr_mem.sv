import rv32i::*;

module instr_mem #(
    parameter MEM_SIZE_BYTES = 65536    // 64 KB instruction memory
) (
    input logic clk,        // clock signal
    input Word instr_addr,  // instruction memory address

    output Word instr_out,   // output fetched instruction
    output logic instr_not_found, // if instruction not found, raise fault
);



endmodule