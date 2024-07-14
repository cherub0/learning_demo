cmake_minimum_required(VERSION 3.5.0)

project(demo4)

set(CMAKE_CXX_STANDARD 11)

# 定义变量
# 静态库生成的路径
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
# 可执行程序路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 头文件路径
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 动态库名字
set(CALC_LIB calc)
set(SORT_LIB sort)

# 可执行程序名字 
set(CALC_EXEC app_calc)
set(SORT_EXEC app_sort)

add_subdirectory(calc)
add_subdirectory(sort)
add_subdirectory(src)
add_subdirectory(test)
