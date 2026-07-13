import rv32i::*;

module rv32i_core (
    input Instruction instr_in, // next instruction (MEM -> FU)
    input Word data_in,         // input data from (MEM -> LSU)
    input logic if_fault,       // instruction fetch fault (MEM -> FU)
    input logic data_fault,     // data fetch fault (MEM)

    output logic clk,           // CPU clock

    output Word if_addr,        // instruction fetch address (FU)
    output Word data_addr,      // data address (LSU)
    output Word data_out,       // data out (LSU)    
    output logic write_en,      // write enable (LSU)
    output ReqBytes req_bytes,  // requested bytes amount (LSU)
);

endmodule