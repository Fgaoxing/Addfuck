#include <iostream>
#include <string>

// 包含头文件
#include "op.h"
#include "vm.h"
#include "reader.h"


int main(int argc, char* argv[]) {
    std::vector<uint32_t> mem(2, 0); // PC=0，CF=0
    std::vector<std::array<uint32_t, 3>> program;

    // 从命令行参数获取文件路径
    if (argc < 2) {
        std::cerr << "用法: " << argv[0] << " <程序文件路径>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];

    if (!readProgramFromFile(filePath, program)) {
        std::cerr << "读取程序文件失败！" << std::endl;
        return 1;
    }

    // 执行程序
    vm(program, mem);

    return 0;
}