# project information
project(TxParser
        VERSION 1.0
        DESCRIPTION "Transaction parser of Boilerplate app"
        LANGUAGES C)

# specify C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS_DEBUG
    "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -Wno-unused-function -DFUZZ -pedantic -g -O0"
)

add_library(txparser
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/parser.c
)

set_target_properties(txparser PROPERTIES SOVERSION 1)

target_include_directories(txparser PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)
