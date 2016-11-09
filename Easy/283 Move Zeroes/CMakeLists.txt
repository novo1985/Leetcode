cmake_minimum_required(VERSION 3.5)
project(Move_Zeroes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Move_Zeroes ${SOURCE_FILES})