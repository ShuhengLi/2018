cmake_minimum_required(VERSION 3.7)
project(groupProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Critter.cpp Critter.h CritterType.h Ant.cpp Ant.h Position.h Doodlebugs.cpp Doodlebugs.h Grid.cpp Grid.h Helper.h Helper.cpp Status.h)
add_executable(groupProject ${SOURCE_FILES})