// main memory

import rv32i::*;

module mem #(
    parameter MEM_SIZE_BYTES = 131072   //128 KB memory
)(
    input logic clk,

    input Word if_addr,             // instruction fetch address
    input Word lsu_addr,            // data address
    input ReqBytes req_bytes,       // number of requested bytes by lsu

    output Instruction instr_out,   // instruction fetch data
    output Word data_out,           // fetched data

    input logic write_enable,       // enable write if high, only read by default
    input Word data_in,             // write to address of lsu_addr, write req_bytes bytes

    output logic if_not_found,      // instruction not found 
    output logic lsu_not_found      // data not found
);
    localparam INST_SIZE_BYTES = DATA_WIDTH >> 3;

    Byte container [MEM_SIZE_BYTES - 1: 0];

    // instruction read
    always_comb begin
        instr_out = '0;
        if_not_found = 1'b0;
        if (if_addr >= MEM_SIZE_BYTES - INST_SIZE_BYTES) if_not_found = 1'b1;
        else instr_out = 
            {  container[if_addr + 3], // do INST_SIZE_BYTES times
                container[if_addr + 2], 
                container[if_addr + 1], 
                container[if_addr] 
                };
    end

    // data read
    always_comb begin
        data_out = '0;
        lsu_not_found = 1'b0;
        if (req_bytes == ZERO) begin    // dont do anything if zero
        end else if ((lsu_addr + req_bytes) > MEM_SIZE_BYTES) begin
            lsu_not_found = 1'b1;
        end else begin
            case (req_bytes)    // DATA_WIDTH IN BYTES MUST BE >= THAN ALL ReqBytes CASES
                ONE: data_out = 
                    {{(DATA_WIDTH - 8){1'b0}}, container[lsu_addr]};
                TWO: data_out = 
                    {{(DATA_WIDTH - 16){1'b0}}, 
                        container[lsu_addr + 1], 
                        container[lsu_addr]
                        };
                FOUR: data_out = 
                    {{(DATA_WIDTH - 32){1'b0}}, 
                        container[lsu_addr + 3], 
                        container[lsu_addr + 2], 
                        container[lsu_addr + 1], 
                        container[lsu_addr]
                        };
                default: lsu_not_found = 1'b1;
            endcase
        end
    end

    // data write
    always_ff @(posedge clk) begin
        if (write_enable && !lsu_not_found) begin
            case(req_bytes)
                ONE: begin
                    container[lsu_addr]     <= data_in[7:0];
                end
                TWO: begin
                    container[lsu_addr]     <= data_in[7:0];
                    container[lsu_addr + 1] <= data_in[15:8];
                end
                FOUR: begin
                    container[lsu_addr]     <= data_in[7:0];
                    container[lsu_addr + 1] <= data_in[15:8];
                    container[lsu_addr + 2] <= data_in[23:16];
                    container[lsu_addr + 3] <= data_in[31:24];
                end
                default: begin end
            endcase
        end
    end

endmodule
