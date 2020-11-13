cmake_minimum_required(VERSION 3.0.0)
project(LeetCode VERSION 0.1.0)

include_directories(src)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
