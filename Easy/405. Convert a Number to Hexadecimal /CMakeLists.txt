cmake_minimum_required(VERSION 3.5)
project(Convert_a_Number_to_Hexadecimal_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Convert_a_Number_to_Hexadecimal_ ${SOURCE_FILES})