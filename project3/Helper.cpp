//
// Created by Shuheng Li on 2/6/18.
//

#include "Helper.h"
#include <cstdlib>

int random(int range) {
    int res = std::rand() % range;
    return res;
}

int randomOneBase(int range) {
    int res = (std::rand() % range) + 1;
    return res;
}