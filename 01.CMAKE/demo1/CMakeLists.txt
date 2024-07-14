# 指定使用的cmake最低版本
cmake_minimum_required(VERSION 3.5.0)
# 指定项目名称
project(calc VERSION 0.1.0 LANGUAGES C)

# 定义变量存储源文件
# set(SRC_LIST add.c div.c mul.c sub.c main.c)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)

# 指定编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

# 打印顶层目录路径，指定输出路径
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 搜索源文件
# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
# message(${SRC_LIST})

# file搜索
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
# file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# 指定头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 定义可执行文件
add_executable(app ${SRC_LIST})
