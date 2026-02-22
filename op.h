// Copyright (c) 2026 Fgaoxing
// MIT License

#pragma once
#include <cstdint>

// PC mem[0]
// CF mem[1]

enum class Op : uint32_t {
    A   = 1,  // 加法 mem imm
    CA  = 2,  // 条件加法 CF=1时 mem[dst] += mem[src]
    IA  = 3,  // 间接加法 mem[dst] += mem[mem[src]]
    I   = 4,  // 输入 mem[dst] = 输入值
    O   = 5   // 输出 打印mem[dst]的值
};

#define NUM_MAX 0xFFFFFFFFU