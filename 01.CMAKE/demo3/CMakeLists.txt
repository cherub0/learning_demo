cmake_minimum_required(VERSION 3.5.0)

PROJECT(app)

file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.c)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加DEBUG宏
add_definitions(-DDEBUG)
# 添加编译选项
add_compile_options(-Wall -g)

ADD_EXECUTABLE(app ${SRC_LIST})