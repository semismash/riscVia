#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <verilated.h>
#include "Vtop.h"
#include "Vtop___024root.h"

constexpr size_t RAM_SIZE = 131072;

double sc_time_stamp() {
    return 0;
}

namespace std {
    namespace __cxx11 {
        template class basic_string<char>;
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    std::ifstream file("program.bin", std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "[TB ERROR] Could not open program.bin!" << std::endl;
        return -1;
    }

    std::streamsize file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> ram_buffer(file_size);
    if (!file.read(ram_buffer.data(), file_size)) {
        std::cerr << "[TB ERROR] Failed to read program.bin content." << std::endl;
        return -1;
    }

    std::cout << "========================================================" << std::endl;
    std::cout << "[TB] VERIFYING PROGRAM.BIN BYTES (LITTLE-ENDIAN WORDS):" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    for (size_t i = 0; i < ram_buffer.size(); i += 4) {
        std::cout << "Addr 0x" << std::hex << std::setw(8) << std::setfill('0') << i << ": 0x";
        for (int b = 3; b >= 0; --b) {
            if (i + b < ram_buffer.size()) {
                std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)(uint8_t)ram_buffer[i + b];
            } else {
                std::cout << "00";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "========================================================\n" << std::endl;

    auto DUT = std::make_unique<Vtop>();

    if (file_size > RAM_SIZE) {
        std::cerr << "[TB ERROR] Binary size exceeds 128KB limit!" << std::endl;
        return -1;
    }
    
    for (size_t i = 0; i < ram_buffer.size(); ++i) {
        DUT->rootp->top__DOT__u_mem__DOT__container[i] = ram_buffer[i];
    }

    DUT->rst_n = 0;
    DUT->clk = 0;
    DUT->eval(); 
    DUT->clk = 1;
    DUT->eval(); 
    DUT->rst_n = 1;
    
    std::cout << "[TB] Reset de-asserted. Commencing execution loop..." << std::endl;

    uint64_t cycles = 0;
    while (!Verilated::gotFinish() && !DUT->halt) {
        DUT->clk = 0;
        DUT->eval();

        DUT->clk = 1;
        DUT->eval();
        cycles++;

        uint32_t current_pc    = DUT->rootp->top__DOT__if_addr;
        uint32_t instruction   = DUT->rootp->top__DOT__instr;
        uint32_t mem_data_addr = DUT->rootp->top__DOT__data_addr;
        uint32_t mem_wdata     = DUT->rootp->top__DOT__write_data;
        bool     mem_we        = DUT->rootp->top__DOT__write_enable;
        uint32_t alu_out       = DUT->rootp->top__DOT__u_cpu__DOT__alu_out;
        uint32_t next_pc_calc  = DUT->rootp->top__DOT__u_cpu__DOT__u_pc__DOT__pc_next;

        bool     alu_in2_sel   = DUT->rootp->top__DOT__u_cpu__DOT__alu_in2_sel;
        uint32_t rs2_data      = DUT->rootp->top__DOT__u_cpu__DOT__rs2_data;
        //bool     alu_zero      = DUT->rootp->top__DOT__u_cpu__DOT__u_pc__DOT__pcinc_in2_doi;

        std::cout << "\n========================================================" << std::endl;
        std::cout << "[CYCLE " << std::dec << cycles << "]  Executing at PC: 0x" 
                  << std::hex << std::setw(8) << std::setfill('0') << current_pc << std::endl;
        std::cout << " -> Raw Instruction Hex:  0x" << std::setw(8) << instruction << std::endl;
        std::cout << " ----------------------- DATAPATH ----------------------" << std::endl;
        std::cout << " -> ALU Result Output:    0x" << std::setw(8) << alu_out << std::endl;
        std::cout << " -> Computed Next PC:     0x" << std::setw(8) << next_pc_calc << std::endl;
        std::cout << " -> Register rs2 Data:    0x" << std::setw(8) << rs2_data << std::endl;
        std::cout << " ----------------------- CONTROLS ----------------------" << std::endl;
        std::cout << " -> Data Memory Access:   [" << (mem_we ? "WRITE" : "READ") << "] "
                  << "Addr: 0x" << mem_data_addr << " | WData: 0x" << mem_wdata << std::endl;
        std::cout << " -> ALU Input 2 Select:   " << (int)alu_in2_sel << std::endl;
        //std::cout << " -> ALU Zero Indicator:   " << (int)alu_zero << std::endl;

        if (cycles > 100) {
            std::cout << "\n[TB WARNING] Safety simulation cutoff breached!" << std::endl;
            break;
        }
    }

    std::cout << "\n========================================================" << std::endl;
    if (DUT->halt) {
        std::cout << "[TB INFO] Core reached a global safe HALT signal." << std::endl;
        std::cout << "[FINAL STATUS]" << std::endl;
        std::cout << " -> Final Data Address: 0x" << std::hex << DUT->rootp->top__DOT__data_addr << std::endl;
        std::cout << " -> Final Data Out:     0x" << std::hex << DUT->rootp->top__DOT__write_data << std::endl;
    } else {
        std::cout << "[TB INFO] Simulation finished processing." << std::endl;
    }

    DUT->final();
    return 0;
}
