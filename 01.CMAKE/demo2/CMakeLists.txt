# 指定使用的cmake最低版本
cmake_minimum_required(VERSION 3.5.0)
# 指定项目名称
project(calc VERSION 0.1.0 LANGUAGES C)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)

# 指定编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

# 头文件搜索路径
message(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

# 源文件搜索路径
# file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/*.c)
file(GLOB SRC_LIST1 ${PROJECT_SOURCE_DIR}/src/*.c)

message(${SRC_LIST})
message(${SRC_LIST1})

# test list append/remove
list(APPEND SRC_LIST ${SRC_LIST1})
message(${SRC_LIST})

# 删除某个源文件
list(REMOVE_ITEM SRC_LIST ${PROJECT_SOURCE_DIR}/main.c)
message(${SRC_LIST})

# 指定库的输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 编译静态库
add_library(calc_static STATIC ${SRC_LIST})
# 指定静态库的输出名称
set_target_properties(calc_static PROPERTIES OUTPUT_NAME "calc")
# 编译动态库
add_library(calc SHARED ${SRC_LIST})

link_directories(${PROJECT_SOURCE_DIR}/lib)

# 链接静态库
# link_libraries(calc_static)

# 指定输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 指定可执行文件的源文件
add_executable(app main.c)

# 链接动态库
target_link_libraries(app calc)


