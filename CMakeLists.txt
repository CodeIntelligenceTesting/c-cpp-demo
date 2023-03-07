cmake_minimum_required(VERSION 3.16)
project(c_cpp_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(cifuzz)
enable_fuzz_testing()

add_library(heap_buffer_overflow src/heap_buffer_overflow.cpp)

add_fuzz_test(heap_buffer_overflow_test src/heap_buffer_overflow_test.cpp)
target_link_libraries(heap_buffer_overflow_test PRIVATE heap_buffer_overflow)

add_library(use_after_free src/use_after_free.cpp)
target_sources(use_after_free PUBLIC src/use_after_free.h)

add_fuzz_test(use_after_free_test src/use_after_free_test.cpp)
target_link_libraries(use_after_free_test PRIVATE use_after_free)