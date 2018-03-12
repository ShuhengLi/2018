#include "Jerry.h"
#include <iomanip>
#include <algorithm>
#include <iostream>

Jerry::Jerry() : Space(){
    spaceName = "Jerry Peng";
    flags[DOWN] = false;
}

void Jerry::event() {
    std::cout << "I am Professor Jerry! Answer my question then you could leave this class!" << std::endl;
    std::cout << "What's the secert of programming?" << std::endl;
    if(!geek->hasItem(CTRL_V)){
        std::cout << "\"You don't know the answer? Go back to your seat!\" " << std::endl;
        return;
    }
    std::cout << "You said: \"COPY&PASTE\"" << std::endl;
    std::cout << "\"You are a MASTER now, nothing I could teach you anymore!\"" << std::endl;
    flags[DOWN] = true;
}

