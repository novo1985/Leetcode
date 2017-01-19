cmake_minimum_required(VERSION 3.5)
project(Symmetric_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Symmetric_Tree ${SOURCE_FILES})