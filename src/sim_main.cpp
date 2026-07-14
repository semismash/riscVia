#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <verilated.h>
#include <verilated_vcd_c.h>
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
    Verilated::traceEverOn(true);

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
    auto trace = std::make_unique<VerilatedVcdC>();
    DUT->trace(trace.get(), 99);
    trace->open("waveform.vcd");

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
    trace->dump(0);
    
    DUT->rst_n = 1;
    DUT->eval(); 
    std::cout << "[TB] Reset de-asserted. Commencing execution loop..." << std::endl;

    uint64_t cycles = 0;
    uint64_t sim_time = 1;
    while (!Verilated::gotFinish() && !DUT->halt) {
        DUT->clk = 0;
        DUT->eval();
        trace->dump(sim_time++);

        DUT->clk = 1;
        DUT->eval();
        trace->dump(sim_time++);
        cycles++;

        uint32_t current_pc    = DUT->rootp->top__DOT__if_addr;
        uint32_t instruction   = DUT->rootp->top__DOT__instr;
        uint32_t mem_data_addr = DUT->rootp->top__DOT__data_addr;
        uint32_t mem_wdata     = DUT->rootp->top__DOT__write_data;
        bool     mem_we        = DUT->rootp->top__DOT__write_enable;

        uint32_t r1 = DUT->rootp->top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[1];
        uint32_t r2 = DUT->rootp->top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[2];
        uint32_t r3 = DUT->rootp->top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[3];
        uint32_t r4 = DUT->rootp->top__DOT__u_cpu__DOT__u_reg_file__DOT__registers[4];

        std::cout << "\n========================================================" << std::endl;
        std::cout << "[CYCLE " << std::dec << cycles << "]  Executing at PC: 0x" 
                  << std::hex << std::setw(8) << std::setfill('0') << current_pc << std::endl;
        std::cout << " -> Raw Instruction Hex:  0x" << std::setw(8) << instruction << std::endl;
        std::cout << " -------------------- REGISTER FILE --------------------" << std::endl;
        std::cout << " -> x1: 0x" << std::setw(8) << r1 << " | x2: 0x" << std::setw(8) << r2 << std::endl;
        std::cout << " -> x3: 0x" << std::setw(8) << r3 << " | x4: 0x" << std::setw(8) << r4 << std::endl;
        std::cout << " ----------------------- CONTROLS ----------------------" << std::endl;
        std::cout << " -> Data Memory Access:   [" << (mem_we ? "WRITE" : "READ") << "] "
                  << "Addr: 0x" << mem_data_addr << " | WData: 0x" << mem_wdata << std::endl;

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

    trace->close();
    DUT->final();
    return 0;
}
