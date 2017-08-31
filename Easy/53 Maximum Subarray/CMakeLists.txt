cmake_minimum_required(VERSION 3.5)
project(Maximum_Subarray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Maximum_Subarray ${SOURCE_FILES})