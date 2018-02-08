cmake_minimum_required(VERSION 3.7)
project(project2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Turtle.cpp Turtle.h Tiger.cpp Tiger.h Penguin.cpp Penguin.h Zoo.cpp Zoo.h AnimalType.h AnimalArray.cpp AnimalArray.h Animal.cpp Animal.h)
add_executable(project2 ${SOURCE_FILES})