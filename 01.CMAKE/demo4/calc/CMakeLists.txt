cmake_minimum_required(VERSION 3.5.0)

project(calc)

aux_source_directory(./ SRC_LIST)

include_directories(${HEAD_PATH})

set(LIBRARY_OUTPUT_PATH ${LIB_PATH})

add_library(${CALC_LIB} SHARED ${SRC_LIST})