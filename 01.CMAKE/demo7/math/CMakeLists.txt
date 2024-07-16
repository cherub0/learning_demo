aux_source_directory(./ SRC_LIST)

set(LIBRARY_OUTPUT_PATH ${LIB_PATH})

add_library(${MATH_LIB} SHARED ${SRC_LIST})

install(TARGETS ${MATH_LIB} DESTINATION bin)