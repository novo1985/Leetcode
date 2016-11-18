cmake_minimum_required(VERSION 3.5)
project(Add_Strings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Add_Strings ${SOURCE_FILES})