cmake_minimum_required(VERSION 3.7)
project(FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Space.cpp Space.h Geek.cpp Geek.h Items.h MusicTeacher.cpp MusicTeacher.h Helper.cpp Helper.h Game.cpp Game.h Meng.cpp Meng.h Omniscience.cpp Omniscience.h OriginalSeat.cpp OriginalSeat.h Steve.cpp Steve.h Raymond.cpp Raymond.h Jerry.cpp Jerry.h Door.cpp Door.h Direction.h)
add_executable(FinalProject ${SOURCE_FILES})