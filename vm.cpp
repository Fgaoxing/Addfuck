#include "vm.h"
#include <iostream>
#include <string>
#include <locale>

void vm(const std::vector<std::array<uint32_t, 3>>& program,
            std::vector<uint32_t>& mem)
{
    // 设置控制台编码为UTF-8
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.imbue(std::locale(""));

    if (mem.size() < 2)
        mem.resize(2, 0);

    while (true) {
        uint32_t pc = mem[0];
        if (pc >= program.size())
            return;

        const auto& inst = program[pc];
        Op op = static_cast<Op>(inst[0]);
        uint32_t dst = inst[1];
        uint32_t src = inst[2];

        if (dst >= mem.size())
            mem.resize(dst + 1, 0);

        switch (op) {
            // A：立即数加法
            case Op::A: {
                uint64_t sum = (uint64_t)mem[dst] + src;
                mem[dst] = (uint32_t)sum;
                mem[1] = (sum > NUM_MAX) ? 1U : 0U;
                break;
            }

            // CA：条件内存加法
            case Op::CA: {
                if (mem[1] == 0) break;
                if (src >= mem.size()) mem.resize(src + 1, 0);
                uint64_t sum = (uint64_t)mem[dst] + mem[src];
                mem[dst] = (uint32_t)sum;
                mem[1] = (sum > NUM_MAX) ? 1U : 0U;
                break;
            }

            // IA：间接加法
            case Op::IA: {
                if (src >= mem.size()) mem.resize(src + 1, 0);
                uint32_t ptr = mem[src];
                if (ptr >= mem.size()) mem.resize(ptr + 1, 0);
                uint64_t sum = (uint64_t)mem[dst] + mem[ptr];
                mem[dst] = (uint32_t)sum;
                mem[1] = (sum > NUM_MAX) ? 1U : 0U;
                break;
            }

            // I：输入指令
            case Op::I: {
                // 移除额外提示
                std::string inputStr;
                std::cin >> inputStr;
                
                // 读取输入字符串，存储到指定缓冲区，长度由参数指定
                uint32_t bufPos = dst;
                uint32_t length = src;
                
                for (uint32_t i = 0; i < length && i < inputStr.size(); ++i) {
                    if (bufPos + i >= mem.size()) {
                        mem.resize(bufPos + i + 1, 0);
                    }
                    mem[bufPos + i] = static_cast<uint32_t>(inputStr[i]);
                }
                break;
            }

            // O：输出指令
            case Op::O: {
                // 从指定缓冲区位置读取数据，输出指定长度的字符
                uint32_t bufPos = dst;
                uint32_t length = src;
                
                // 移除额外提示
                for (uint32_t i = 0; i < length; ++i) {
                    if (bufPos + i < mem.size()) {
                        char ch = static_cast<char>(mem[bufPos + i]);
                        std::cout << ch;
                    }
                }
                break;
            }
        }
        mem[0]++;
    }
}