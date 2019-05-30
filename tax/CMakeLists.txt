cmake_minimum_required(VERSION 3.13)
project(tax)

set(CMAKE_CXX_STANDARD 14)

add_executable(tax main.cpp TaxReturn.h Tax36.h Tax36.cpp Tax37.h Tax37.cpp)