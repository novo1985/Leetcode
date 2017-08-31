cmake_minimum_required(VERSION 3.5)
project(Roman_to_Integer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Roman_to_Integer ${SOURCE_FILES})