cmake_minimum_required(VERSION 3.5)
project(Reverse_Integer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Reverse_Integer ${SOURCE_FILES})