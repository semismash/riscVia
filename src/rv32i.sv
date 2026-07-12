package rv32i;
    
    localparam DATA_WIDTH = 32;
    localparam ADDR_WIDTH = 5;

    typedef enum logic [6:0] {  //7 bits for opcode
        OP_R =      7'b0110011,
        OP_I =      7'b0010011,
        OP_I_L =    7'b0000011,
        OP_S =      7'b0100011,
        OP_B =      7'b1100011,
        OP_J =      7'b1101111,
        OP_LUI =    7'b0110111,
        OP_AUIPC =  7'b0010111,
        OP_I_E =    7'b1110011
    } OpCode;

endpackage