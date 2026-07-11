module register_file #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 5    // five bits = 32 registers for RISC-V
)(
    input logic clk,
    input logic rst_n,      //active low reset

    input logic w_enable,   //write enable
    input logic w_addr,     //write address
    input logic w_data,     //write data

    input logic r_addr1,    //read address 1
    input logic r_addr2,    //read address 2

    output logic r_data1,   //address 1 data out
    output logic r_data2    //address 2 data out
);

    logic [2**ADDR_WIDTH - 1:0] register [DATA_WIDTH - 1:0];
    assign register[0] = '0;    // hardware register 0 to 0

endmodule