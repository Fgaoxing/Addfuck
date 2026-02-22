cmake_minimum_required(VERSION 3.8)
project(addfuck LANGUAGES CXX)

# 设置C++标准为17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 添加优化选项以减小可执行文件大小
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -s -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")

# 添加可执行文件
add_executable(addfuck 
    main.cpp
    vm.cpp
    reader.cpp
)

# 包含头文件目录
target_include_directories(addfuck PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})