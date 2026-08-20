VERILATOR = verilator
SIM_EXE   = ./obj_dir/Vtop.exe
SRC_DIR = src

# RISC-V Toolchain Configurations
AS      = riscv-none-elf-as
LD      = riscv-none-elf-ld
OBJCOPY = riscv-none-elf-objcopy

# design
VERILOG_SRCS = \
	$(SRC_DIR)/design/rv32i.sv \
    $(SRC_DIR)/design/core/components/hazard_unit.sv \
    $(SRC_DIR)/design/core/components/pc.sv \
    $(SRC_DIR)/design/core/components/reg_file.sv \
    $(SRC_DIR)/design/core/pipeline/ex_mem.sv \
    $(SRC_DIR)/design/core/pipeline/id_ex.sv \
    $(SRC_DIR)/design/core/pipeline/if_id.sv \
    $(SRC_DIR)/design/core/pipeline/mem_wb.sv \
    $(SRC_DIR)/design/core/units/alu.sv \
    $(SRC_DIR)/design/core/units/branch_unit.sv \
    $(SRC_DIR)/design/core/units/decoder.sv \
    $(SRC_DIR)/design/core/units/fetch.sv \
    $(SRC_DIR)/design/core/units/imm_gen.sv \
    $(SRC_DIR)/design/core/units/lsu.sv \
    $(SRC_DIR)/design/core/stop.sv \
    $(SRC_DIR)/design/core/rv32i_core.sv \
    $(SRC_DIR)/design/mem/data_mem.sv \
    $(SRC_DIR)/design/mem/instr_mem.sv \
    $(SRC_DIR)/design/top.sv

# testbench
CPP_SRCS = $(SRC_DIR)/sim_main.cpp

# --- Build Rules ---
.PHONY: all compile run clean asm

all: compile

# Target to compile your assembly source file into the expected program.bin
asm:
	@if [ ! -f program.s ]; then \
		echo "[MAKE ERROR] program.s not found in root directory!"; \
		exit 1; \
	fi
	@echo "[MAKE] Assembling program.s..."
	$(AS) -march=rv32i -mabi=ilp32 -o program.o program.s
	@echo "[MAKE] Linking ELF image at base address 0x0..."
	$(LD) -Ttext 0x0 -o program.elf program.o
	@echo "[MAKE] Extracting raw machine bytes to program.bin..."
	$(OBJCOPY) -O binary program.elf program.bin
	@echo "[MAKE] Appending 0xFFFFFFFF terminal STOP token..."
	@printf "\xff\xff\xff\xff" >> program.bin
	@rm -f program.o program.elf
	@echo "[MAKE] Assembly compilation complete!"

compile: $(VERILOG_SRCS) $(CPP_SRCS)
	@echo "[MAKE] Compiling SystemVerilog core and C++ testbench..."
	$(VERILATOR) --cc --exe --build -j -Wall -Wno-fatal --trace -I$(SRC_DIR) \
		-CFLAGS "-O2" \
		-LDFLAGS "-O2" \
		$(VERILOG_SRCS) $(CPP_SRCS) --top-module top

# Updated run rule: Automatically rebuilds program.bin if program.s changes
run: asm compile
	@echo "[MAKE] Executing simulation wrapper..."
	$(SIM_EXE)

clean:
	@echo "[MAKE] Sweeping away generated simulation files..."
	rm -rf obj_dir program.bin program.o program.elf
