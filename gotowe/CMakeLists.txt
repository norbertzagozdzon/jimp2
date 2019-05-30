cmake_minimum_required(VERSION 3.13)
project(gotowe)

set(CMAKE_CXX_STANDARD 14)

add_executable(gotowe main.cpp Vector.h Vector.cpp Animal.h InvalidIndexExpception.h InvalidIndexException.cpp Tax36.h Tax36.cpp Tax37.h Tax37.cpp TaxReturn.h)