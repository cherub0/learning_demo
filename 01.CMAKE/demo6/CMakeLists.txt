cmake_minimum_required(VERSION 3.5.0)

project(app)

# 定义变量
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in" 
    "${HEAD_PATH}/config.h"
    )

# 是否使用自己的 MathFunctions 库
option(USE_MYMATH 
    "Use tutorial provided math implementation" ON)

if (USE_MYMATH)
    include_directories("${HEAD_PATH}")
    set(MATH_LIB math)
    add_subdirectory(math)
endif(USE_MYMATH)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

include_directories(${HEAD_PATH})

message(${USE_MYMATH})

set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})

add_executable(app ${SRC_LIST})
# 链接库
if (USE_MYMATH)
    link_libraries(${LIB_PATH})
    target_link_libraries(app ${MATH_LIB})
else()
    target_link_libraries(app m)
endif(USE_MYMATH)

# 修改安装路径
set(CMAKE_INSTALL_PREFIX /home/zhaoyang/.local/usr/)

message(${CMAKE_INSTALL_PREFIX})

install(TARGETS app DESTINATION bin)
install(FILES ${HEAD_PATH}/config.h DESTINATION include)
install(FILES ${HEAD_PATH}/my_math.h DESTINATION include)


# 启用测试
enable_testing()

# 定义do_test宏
macro(do_test param1 param2 result)
    add_test(test_${param1}_${param2} ${EXEC_PATH}/app ${param1} ${param2})
    set_tests_properties(test_${param1}_${param2} 
        PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test param1 param2 result)


# 测试用例
do_test(2 10 "= 1024")
do_test(3 5 "= 243")
do_test(8 6 "= 262144")
do_test(10 5 "= 100000")

