cmake_minimum_required(VERSION 3.7)
project(lab7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.cpp Node.h MyQueue.cpp MyQueue.h Menu.cpp Menu.h Helper.cpp Helper.h)
add_executable(lab7 ${SOURCE_FILES})