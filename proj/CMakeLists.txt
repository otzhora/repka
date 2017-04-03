cmake_minimum_required(VERSION 3.6)
project(proj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes.h classes.cpp func.h func.cpp)
add_executable(proj ${SOURCE_FILES})