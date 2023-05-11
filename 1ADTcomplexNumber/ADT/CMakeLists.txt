cmake_minimum_required(VERSION 3.24)
project(ADT)

set(CMAKE_CXX_STANDARD 17)

add_library(ADT SHARED ComplexNum.cpp ComplexNum.h)
install(TARGETS ADT DESTINATION C:/University/datastructure/1ADTcomplexNumber)
