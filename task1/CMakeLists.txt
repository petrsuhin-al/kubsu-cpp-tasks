cmake_minimum_required(VERSION 3.19)
project(task1)

set(CMAKE_CXX_STANDARD 14)

add_library(task1_static STATIC library.cpp library.h classic.cpp classic.h)
add_library(task1_shared SHARED library.cpp library.h classic.cpp classic.h)