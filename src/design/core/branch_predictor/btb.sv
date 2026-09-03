import rv32i::*;

module btb(
    // clock and reset
    input logic clk,
    input logic rst_n,
    // INPUTS:
    // read from BTB
    input PCIndex access_index,     // to read from PC index for cache hit/miss
    // for writing to cache
    input logic write_enable,           // if to be written at the address
    input PCIndex write_index,          // index to write to in the PC (cache replacement figured out by the module itself)
    input PCTag write_tag,              // the 22 tag bits to be used for matching
    input PCAddrNoUnused write_tgt,     // the 30 bit target address to be added to corresponding BTB entry
    // forwarding: to be checked later, theory is that it can be directly done through the current write ports
    // OUTPUTS:
    output logic cache_hit,         // indicates if cache hit or miss
    output PCAddrNoUnused addr_out  // output target address upon cache hit
);

endmodule