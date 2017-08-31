cmake_minimum_required(VERSION 3.5)
project(longest_common_prefix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(longest_common_prefix ${SOURCE_FILES})