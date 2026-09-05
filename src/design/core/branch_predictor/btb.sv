import rv32i::*;

module btb(
    // clock and reset
    input logic clk,
    input logic rst_n,
    // INPUTS:
    // read from BTB
    input PCIndex access_index,     // to read from PC index for cache hit/miss
    input PCTag read_tag,           // read tag for comparison and fetching target address
    // for writing to cache
    input logic write_enable,           // if to be written at the address
    input PCIndex write_index,          // index to write to in the PC (cache replacement figured out by the module itself)
    input PCTag write_tag,              // the 22 tag bits to be used for matching
    input PCAddrNoUnused write_tgt,     // the 30 bit target address to be added to corresponding BTB entry
    // forwarding: to be checked later, theory is that it can be directly done through the current write ports
    // OUTPUTS:
    output logic cache_hit,         // indicates if cache hit or miss
    output BTBEntry data_out        // output data (target addr + tag + valid bits) upon cache hit
);
    typedef struct packed {
        BTBEntry [BTB_WAYS_C - 1 : 0] ways;
        logic [PLRU_BIT_C - 1 : 0] plru;
    } BTBSet;  
    
    BTBSet [BTB_SET_C - 1 : 0] btb_cache;
    BTBSet cur_read_set;
    BTBSet cur_write_set;
    BTBSet new_write_set;

    BTBEntry write_entry;
    logic read_0_eq, read_1_eq, read_2_eq, read_3_eq;
    logic forwarded;    // if the value is forwared or not

    always_comb begin

        // initialize driven logic and ports
        cache_hit = 1'b0;
        data_out = '0;
        forwarded = 1'b0;

        // initialize indexes
        cur_read_set = btb_cache[access_index];
        cur_write_set = btb_cache[write_index];
        new_write_set = cur_write_set;

        write_entry = '{    //sets bit to valid when writing (uwu)
            target_addr:    write_tgt, 
            pc_tag:         write_tag,
            valid:          1'b1
        }; 

        // update cache using PLRU replacement policy, and updaate respective PLRU bits
        if (cur_write_set.plru[0]) begin
            if (cur_write_set.plru[2]) begin
                new_write_set.ways[3] = write_entry;
            end else begin
                new_write_set.ways[2] = write_entry;
            end
            new_write_set.plru[2] = !new_write_set.plru[2];
        end else begin
            if (cur_write_set.plru[1]) begin
                new_write_set.ways[1] = write_entry;
            end else begin
                new_write_set.ways[0] = write_entry;
            end
            new_write_set.plru[1] = !new_write_set.plru[1];
        end
        new_write_set.plru[0] = !new_write_set.plru[0];
        
        // forwarding values to check, else check normally
        if (access_index == write_index) begin
            forwarded = 1'b1;
            read_0_eq = (new_write_set.ways[0].pc_tag == read_tag);
            read_1_eq = (new_write_set.ways[1].pc_tag == read_tag);
            read_2_eq = (new_write_set.ways[2].pc_tag == read_tag);
            read_3_eq = (new_write_set.ways[3].pc_tag == read_tag);
        end else begin
            forwarded = 1'b0;
            read_0_eq = (cur_read_set.ways[0].pc_tag == read_tag);
            read_1_eq = (cur_read_set.ways[1].pc_tag == read_tag);
            read_2_eq = (cur_read_set.ways[2].pc_tag == read_tag);
            read_3_eq = (cur_read_set.ways[3].pc_tag == read_tag);
        end

        // check if cache hit using read set
        if (read_0_eq || read_1_eq || read_2_eq || read_3_eq) begin
            cache_hit = 1'b1;
            cur_read_set.plru[0] = !cur_read_set.plru[0];   // flip bit to update plru tree
            if (read_0_eq) begin
                data_out = (forwarded) ? new_write_set.ways[0].target_addr : cur_read_set.ways[0].target_addr;
                cur_read_set.plru[1] = !cur_read_set.plru[1];
            end else if (read_1_eq) begin
                data_out = (forwarded) ? new_write_set.ways[1].target_addr : cur_read_set.ways[1].target_addr;
                cur_read_set.plru[1] = !cur_read_set.plru[1];
            end else if (read_2_eq) begin
                data_out = (forwarded) ? new_write_set.ways[2].target_addr : cur_read_set.ways[2].target_addr;
                cur_read_set.plru[2] = !cur_read_set.plru[2];
            end else begin
                data_out = (forwarded) ? new_write_set.ways[3].target_addr : cur_read_set.ways[3].target_addr;
                cur_read_set.plru[2] = !cur_read_set.plru[2];
            end
        end

    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin   // reset all valid to 0 (valid bit technically unused now, but whataever)
            for (int s = 0; s < BTB_SET_C; s++) begin
                for (int w = 0; w < BTB_WAYS_C; w++) begin
                    btb_cache[s].ways[w].valid <= 1'b0;
                end
            end
        end else if (write_enable) begin
            btb_cache[write_index] <= new_write_set;
        end else if (cache_hit) begin
            btb_cache[access_index] <= cur_read_set;
        end
    end

    // if someone sees this, please read (or not, feel free to do what you like ;]):
    // i'm an 18 year old student who is currently doing a lot of sh*t simultaneously, trying to juggle academics and projects together
    // i have no proper friends, no one to vent to, dealing with a lot of sh*t, family member with stage 4 cancer, and im at my breaking point
    // i have served as an emotional anchor for those around me, but havent been able to find anyone to anchor myself to
    // i am at my wits end, and i just scribble my notes in my notebook without any fuel to keep me going
    // thanks for understanding, sorry for this inconvenience

endmodule