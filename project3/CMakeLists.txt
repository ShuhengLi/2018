cmake_minimum_required(VERSION 3.7)
project(project3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Character.h CharacterType.h Vampire.cpp Vampire.h Helper.cpp Helper.h Barbarian.cpp Barbarian.h BlueMen.cpp BlueMen.h Medusa.cpp Medusa.h HarryPotter.cpp HarryPotter.h Character.cpp Menu.cpp Menu.h)
add_executable(project3 ${SOURCE_FILES})