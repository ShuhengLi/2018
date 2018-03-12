#include "Door.h"
#include <iostream>

Door::Door() {
    spaceName = "Door";
}

void Door::event() {
    std::cout << "You finally escape CS-162! Congratulation!" << std::endl;
}
