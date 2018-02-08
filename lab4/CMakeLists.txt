cmake_minimum_required(VERSION 3.7)
project(lab4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp University.cpp University.h Buildings.cpp Buildings.h People.cpp People.h Instructor.cpp Instructor.h RandomNum.h Menu.cpp Menu.h RandomNum.cpp Student.cpp Student.h inputValidation.h)
add_executable(lab4 ${SOURCE_FILES})