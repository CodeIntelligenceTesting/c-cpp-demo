cmake_minimum_required(VERSION 3.16)
project(c_cpp_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(cifuzz)
enable_fuzz_testing()

add_library(base64 lib/base64.cpp)

add_library(heap_buffer_overflow src/heap_buffer_overflow.cpp)
target_include_directories(heap_buffer_overflow PRIVATE lib)
target_link_libraries(heap_buffer_overflow PUBLIC base64)

add_fuzz_test(heap_buffer_overflow_test src/heap_buffer_overflow_test.cpp)
target_link_libraries(heap_buffer_overflow_test PRIVATE heap_buffer_overflow)

add_library(stack_buffer_overflow src/stack_buffer_overflow.cpp)
target_sources(stack_buffer_overflow PUBLIC src/stack_buffer_overflow.h)

add_fuzz_test(stack_buffer_overflow_test src/stack_buffer_overflow_test.cpp)
target_link_libraries(stack_buffer_overflow_test PRIVATE stack_buffer_overflow)