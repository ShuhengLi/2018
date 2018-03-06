cmake_minimum_required(VERSION 3.7)
project(lab9)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Helper.cpp Helper.h Menu.cpp Menu.h)
add_executable(lab9 ${SOURCE_FILES})