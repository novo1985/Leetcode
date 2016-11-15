cmake_minimum_required(VERSION 3.5)
project(Contains_Duplicate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Contains_Duplicate ${SOURCE_FILES})