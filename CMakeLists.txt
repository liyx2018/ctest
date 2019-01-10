# cmake_minimum_required(VERSION <specify CMake version here>)
project(ctest C)

set(CMAKE_C_STANDARD 99)

add_executable(ctest structdemo.c test.h)