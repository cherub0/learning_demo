cmake_minimum_required(VERSION 3.5.0)
project(sort)

# 查找当前目录下的源文件
aux_source_directory(./ SRC_LIST)

# 设置头文件路径
include_directories(${HEAD_PATH})

# 设置库文件路径
link_directories(${LIB_PATH})

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})

# 编译可执行文件
add_executable(${SORT_EXEC} ${SRC_LIST})

# 链接动态库文件
target_link_libraries(${SORT_EXEC} ${SORT_LIB})