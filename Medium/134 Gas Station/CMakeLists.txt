cmake_minimum_required(VERSION 3.5)
project(Gas_Station)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Gas_Station ${SOURCE_FILES})