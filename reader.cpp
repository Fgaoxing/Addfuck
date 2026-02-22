#include "reader.h"
#include "op.h"
#include <iostream>
#include <fstream>
#include <sstream>


/**
 * 从文件中读取程序指令
 * 
 * @param filePath 文件路径
 * @param program 存储读取的程序指令
 * @return 读取是否成功
 */
bool readProgramFromFile(const std::string& filePath, 
                           std::vector<std::array<uint32_t, 3>>& program) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filePath << std::endl;
        return false;
    }
    
    std::string line;
    uint32_t lineNumber = 0;
    
    while (std::getline(file, line)) {
        lineNumber++;
        
        // 跳过空行和注释行
        if (line.empty() || line[0] == ';') {
            continue;
        }
        
        // 解析指令行
        std::istringstream iss(line);
        std::string opStr;
        uint32_t dst, src;
        
        if (!(iss >> opStr >> dst >> src)) {
            // 移除日志打印
            continue;
        }
        
        // 转换操作码
        uint32_t opCode;
        if (opStr == "A") {
            opCode = static_cast<uint32_t>(Op::A);
        } else if (opStr == "CA") {
            opCode = static_cast<uint32_t>(Op::CA);
        } else if (opStr == "IA") {
            opCode = static_cast<uint32_t>(Op::IA);
        } else if (opStr == "I") {
            opCode = static_cast<uint32_t>(Op::I);
        } else if (opStr == "O") {
            opCode = static_cast<uint32_t>(Op::O);
        } else {
            // 移除日志打印
            continue;
        }
        
        // 添加到程序中
        program.push_back({opCode, dst, src});
    }
    
    file.close();
    return true;
}