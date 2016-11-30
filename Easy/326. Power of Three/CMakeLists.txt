cmake_minimum_required(VERSION 3.5)
project(Power_of_Three)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Power_of_Three ${SOURCE_FILES})