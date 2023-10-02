cmake_minimum_required(VERSION 3.16)
project(Ternary)

set(CMAKE_CXX_STANDARD 20)


add_library(Ternary STATIC source/Ternary.cpp)

target_include_directories(Ternary PUBLIC include)