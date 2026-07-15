# riscVia

A minimalist & modular RISC-V processor based on the RV32I architecture.

## Specifications

The CPU is based on the RV32I architecture. It contains implementation the base 40 instructions (minus `FENCE`, which is a NOP). Specifications include 32 General Purpose Registers (x0 hardwired to 0), 32-bit word size, 32-bit instruction size, and a 32-bit program counter (PC). For more information related to the RV32I architecture, please check the [official RISC-V specification.](https://docs.riscv.org/reference/isa/v20260120/unpriv/rv32.html)

## Diagram

![RISC-V Processor Image](diagram/RISCVIA-CORE-V1.png)

## Modules and Working

The CPU uses the IF -> ID -> EX -> MEM -> WB cycle. The main parts and modules of the CPU include -  

- [**Register File**](src/design/reg_file.sv) - Register File containing the 32 general purpose registers. Outputs of the module are `r_data1` and `r_data2`, used by the execution units as operands, and which can be selected via their respective address inputed. Includes a provision for writing to a register, via selcting `w_enable`, the `w_addr`, and `w_data` to be written. `x0` is permanently hardwired to zero. Updated on positive clock edge, and allows asynchronous reset on negative edge on active low input.
- [**Program Counter**](src/design/pc.sv) - Program counter of the CPU, which points to the byte of the currently executing instruction in the main memory. Always initialized at byte 0. Increments by 4 by default on every positive clock edge. However, depending on the instruction, the PC can either be incremented by `IMM`, or be set to `rs1 + IMM`, based on the `pcinc_in1_pcor` and `pcinc_in2_doi` inputs respectively. Allows asynchronous reset on negative edge on active low input.
- [**Fetch Unit**](src/design/fetch.sv) - Fetch unit of the CPU, responsible for fetching the instructions from the main memory with the help of the program counter, and feeding it to the decoder. Currently functions largely as a wrapper around the `pc`, `instr`, and `mem_fault` lines. Purely combinational, and feeds `mem_fault` signals to the `HALT` unit.
- [**Decoder**](src/design/decoder.sv) - Decoder of the CPU, part of the controller responsible for decoding instructions for the rest of the CPU to execute. Purely combinational, and primarily decodes instructions based on the 7 `opcode` bits of the CPU. In addition, for arithmetic and logic instructions, the ALU looks at the `funct3` and `funct7` bits of the instruction to generate an equivalent signal for the ALU operation, given by the `alu_op` output. In addition, the decoder signals the Immediate Generator the respective format required to unpack immediate values for the instruction. Also gives signals to the PC, Reg File, and LSU to perform an operation based on the instruction.
- [**Immediate Generator**](src/design/imm_gen.sv) - Part of the decoder which generates immediate values from the instructions, and unpacks them based on signals given by the decoder, based on I, S, B, U, and J instructions. After unpacking, the module sends the value as a Word with respective sign-extended or zero-padded bits to either the ALU's `input_2` or the Reg File directly, if the instruction can bypass the ALU (eg. `LUI`).
