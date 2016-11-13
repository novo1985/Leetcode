cmake_minimum_required(VERSION 3.5)
project(First_Unique_Character_in_a_String)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(First_Unique_Character_in_a_String ${SOURCE_FILES})