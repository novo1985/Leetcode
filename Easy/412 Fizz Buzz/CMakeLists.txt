cmake_minimum_required(VERSION 3.5)
project(412_Fizz_Buzz)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(412_Fizz_Buzz ${SOURCE_FILES})