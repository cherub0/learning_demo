cmake_minimum_required(VERSION 3.5.0)
project(calctest)

aux_source_directory(./ SRC_LIST)
include_directories(${HEAD_PATH})

link_directories(${LIB_PATH})

set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})

add_executable(${CALC_EXEC} ${SRC_LIST})

target_link_libraries(${CALC_EXEC} ${CALC_LIB})