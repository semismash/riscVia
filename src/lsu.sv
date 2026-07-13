import rv32i::*;

module lsu #(
    parameter DATA_WIDTH = rv32i::DATA_WIDTH;
) (
    input logic [2:0] funct3;   // RV32I uses funct3 to differentiate between req_bytes for loads and stores
    input Word alu_res;         // ALU result to calculate load/store location
    input logic is_mem_write;   // if write instruction to data memory
    input Word rs2_in;          // check rs2 if store

    input Word data_in;         // data from data mem output (raw data)
    
    output logic write_enable;  // if to write to data memory
    output Word write_data;     // formatted data bytes to write address
    output ReqBytes req_bytes;  // output for the requested bytes from data mem

    output Word reg_data;       // 32 bit word to be written to reg file after loading
);


    
endmodule