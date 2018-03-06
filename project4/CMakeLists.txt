cmake_minimum_required(VERSION 3.7)
project(project4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp  MyQueue.h Character.h CharacterType.h Vampire.cpp Vampire.h Helper.cpp Helper.h Barbarian.cpp Barbarian.h BlueMen.cpp BlueMen.h Medusa.cpp Medusa.h HarryPotter.cpp HarryPotter.h Character.cpp Menu.cpp Menu.h)
add_executable(project4 ${SOURCE_FILES})