VERILATOR = verilator
SIM_EXE   = ./obj_dir/Vtop.exe
SRC_DIR = src

# design
VERILOG_SRCS = \
	$(SRC_DIR)/design/rv32i.sv \
	$(SRC_DIR)/design/alu.sv \
	$(SRC_DIR)/design/decoder.sv \
	$(SRC_DIR)/design/fetch.sv \
	$(SRC_DIR)/design/imm_gen.sv \
	$(SRC_DIR)/design/lsu.sv \
	$(SRC_DIR)/design/mem.sv \
	$(SRC_DIR)/design/pc.sv \
	$(SRC_DIR)/design/reg_file.sv \
	$(SRC_DIR)/design/rv32i_core.sv \
	$(SRC_DIR)/design/top.sv

# VERILOG_SRCS = $(wildcard $(SRC_DIR)/*.sv)

# testbench
CPP_SRCS = $(SRC_DIR)/sim_main.cpp

# --- Build Rules ---
.PHONY: all compile run clean

all: compile

compile: $(VERILOG_SRCS) $(CPP_SRCS)
	@echo "[MAKE] Compiling SystemVerilog core and C++ testbench..."
	$(VERILATOR) --cc --exe --build -j -Wall -Wno-fatal --trace -I$(SRC_DIR) \
		-CFLAGS "-O2" \
		-LDFLAGS "-O2" \
		$(VERILOG_SRCS) $(CPP_SRCS) --top-module top

run: compile
	@if [ -f program.bin ]; then \
		echo "[MAKE] Executing simulation wrapper..."; \
		$(SIM_EXE); \
	else \
		echo "[MAKE ERROR] program.bin not found! Please create it before running."; \
		exit 1; \
	fi

clean:
	@echo "[MAKE] Sweeping away generated simulation files..."
	rm -rf obj_dir program.bin
