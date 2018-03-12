#ifndef FINALPROJECT_DIRECTION_H
#define FINALPROJECT_DIRECTION_H

#include <map>
#include <string>

enum Direction{
    UP,
    LEFT,
    DOWN,
    RIGHT
};

static std::map<Direction, std::string> direction2String = {
        {UP, "UP"},
        {LEFT, "LEFT"},
        {DOWN, "DOWN"},
        {RIGHT, "RIGHT"}
};

#endif //FINALPROJECT_DIRECTION_H
