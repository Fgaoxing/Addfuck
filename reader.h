#pragma once
#include <vector>
#include <array>
#include <string>
#include <cstdint>

/**
 * 从文件中读取程序指令
 * 
 * @param filePath 文件路径
 * @param program 存储读取的程序指令
 * @return 读取是否成功
 */
bool readProgramFromFile(const std::string& filePath, 
                           std::vector<std::array<uint32_t, 3>>& program);