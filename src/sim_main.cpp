#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <verilated.h>
#include "Vtop.h"
#include "Vtop___024root.h"

// 128 KB boundary matching MEM_SIZE_BYTES param
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
    
    auto DUT = std::make_unique<Vtop>();

    std::ifstream file("program.bin", std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "[TB ERROR] Could not open program.bin! Did you create it?" << std::endl;
        return -1;
    }

    std::streamsize file_size = file.tellg();
    if (file_size > RAM_SIZE) {
        std::cerr << "[TB ERROR] Binary size (" << file_size << " bytes) exceeds 128KB limit!" << std::endl;
        return -1;
    }
    
    file.seekg(0, std::ios::beg);
    std::vector<char> ram_buffer(file_size);
    if (!file.read(ram_buffer.data(), file_size)) {
        std::cerr << "[TB ERROR] Failed to read program.bin content." << std::endl;
        return -1;
    }

    for (size_t i = 0; i < ram_buffer.size(); ++i) {
        DUT->rootp->top__DOT__u_mem__DOT__container[i] = ram_buffer[i];
    }
    std::cout << "[TB] Backdoor loaded " << ram_buffer.size() << " bytes into Unified RAM." << std::endl;

    DUT->rst_n = 0;
    DUT->clk = 0;
    DUT->eval(); 
    
    DUT->clk = 1;
    DUT->eval(); 
    
    DUT->rst_n = 1;
    std::cout << "[TB] Reset de-asserted. Commencing execution loop..." << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    uint64_t cycles = 0;
    while (!Verilated::gotFinish() && !DUT->halt) {
        // falling edge
        DUT->clk = 0;
        DUT->eval();

        // rising edge
        DUT->clk = 1;
        DUT->eval();
        cycles++;

        // logger
        std::cout << "[CYCLE " << std::dec << cycles << "] "
                  << "PC: 0x" << std::hex << std::setw(8) << std::setfill('0') 
                  << DUT->rootp->top__DOT__if_addr << " | "
                  << "Writeback EN: " << (int)DUT->rootp->top__DOT__write_enable
                  << std::endl;

        // infinite loop breakout
        if (cycles > 1000) {
            std::cout << "[TB WARNING] Safety simulation cutoff breached!" << std::endl;
            break;
        }
    }

    std::cout << "--------------------------------------------------------" << std::endl;
    if (DUT->halt) {
        std::cout << "[TB INFO] Core reached a global safe HALT signal." << std::endl;
        
        // print final address
        std::cout << "[FINAL STATUS]" << std::endl;
        std::cout << " -> Final Target Address: 0x" << std::hex << DUT->rootp->top__DOT__data_addr << std::endl;
        std::cout << " -> Final Output Data:   0x" << std::hex << DUT->rootp->top__DOT__write_data << std::endl;
    } else {
        std::cout << "[TB INFO] Simulation finished processing." << std::endl;
    }

    DUT->final();
    return 0;
}
