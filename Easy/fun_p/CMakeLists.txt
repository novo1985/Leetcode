cmake_minimum_required(VERSION 3.5)
project(fun_p)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sol.h sol2.h sol3.h sol4.h)
add_executable(fun_p ${SOURCE_FILES})