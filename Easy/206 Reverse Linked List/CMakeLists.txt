cmake_minimum_required(VERSION 3.5)
project(Reverse_Linked_List)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Reverse_Linked_List ${SOURCE_FILES})