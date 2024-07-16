cmake_minimum_required(VERSION 3.5.0)

project(app)

# 定义变量
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 引入CheckFunctionExists宏
include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(pow HAVE_POW)

# 设置版本号
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in" 
    "${HEAD_PATH}/config.h"
    )

if (NOT HAVE_POW)
    include_directories("${HEAD_PATH}")
    set(MATH_LIB math)
    add_subdirectory(math)
endif(NOT HAVE_POW)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

include_directories(${HEAD_PATH})

if (HAVE_POW)
    message(test zhaoyang)
endif(HAVE_POW)

set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})

add_executable(app ${SRC_LIST})
# 链接库
if (NOT HAVE_POW)
    link_libraries(${LIB_PATH})
    target_link_libraries(app ${MATH_LIB})
else()
    target_link_libraries(app m)
endif(NOT HAVE_POW)

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


# 引入CPack打包，构建一个安装包
# 安装必需的系统库
include(InstallRequiredSystemLibraries)

# 定义CPACK license
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")

# 定义CPACK VENDOR、MAJOR、MINOR，可参考CPackConfig.cmake
set(CPACK_PACKAGE_VENDOR "Cherub")
set(CPACK_PACKAGE_VERSION_MAJOR "${APP_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${APP_VERSION_MINOR}")

include(CPack)
