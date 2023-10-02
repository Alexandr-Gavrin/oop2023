cmake_minimum_required(VERSION 3.16)
project(TernaryArray)

set(CMAKE_CXX_STANDARD 20)


add_library(TernaryArray STATIC source/TernaryArray.cpp)

target_include_directories(TernaryArray PUBLIC include)
target_link_libraries(TernaryArray Ternary LibUtils)