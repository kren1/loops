cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 11)

find_package(LLVM REQUIRED CONFIG HINTS /data/dependencies/llvm-6.0/build)

message(STATUS "LLVM_CONFIG_BINARY: ${LLVM_CONFIG_BINARY}")

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

add_subdirectory(LoopFind)
