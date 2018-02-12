cmake_minimum_required(VERSION 3.7)
project(lab6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DoubleLinkedList.cpp DoubleLinkedList.h Node.cpp Node.h Menu.cpp Menu.h Helper.cpp Helper.h)
add_executable(lab6 ${SOURCE_FILES})