#include "OriginalSeat.h"
#include <iostream>
void OriginalSeat::event() {
    std::cout << "This is my original seat, nothing special" << std::endl;
}

OriginalSeat::OriginalSeat() {
    spaceName = "OrignalSeat";
}
