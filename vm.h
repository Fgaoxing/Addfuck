// Copyright (c) 2026 Fgaoxing
// MIT License

#pragma once
#include <vector>
#include <array>
#include "op.h"

/**
 * 虚拟机执行函数
 * 
 * @param program 要执行的程序指令
 * @param mem 内存状态
 */
void vm(const std::vector<std::array<uint32_t, 3>>& program,
            std::vector<uint32_t>& mem);