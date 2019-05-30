cmake_minimum_required(VERSION 3.13)
project(vektor)

set(CMAKE_CXX_STANDARD 14)
add_executable(vektor main.cpp InvalidIndexExpception.h InvalidIndexException.cpp)