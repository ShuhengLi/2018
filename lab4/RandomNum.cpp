//
// Created by Shuheng Li on 2/1/18.
//
#include "RandomNum.h"

int randomNum(int range) {
    return std::rand()%range;
}

int randomNum(int lowBoundary, int highBoundary) {
    int range = highBoundary - lowBoundary;
    return std::rand()% range + lowBoundary;
}

