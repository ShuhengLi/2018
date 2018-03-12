
#include "Jerry.h"
#include <iostream>

Jerry::Jerry() {
    spaceName = "Jerry Peng";
    flag = false;
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
    flag = true;
}

void Jerry::showInfo() {
    std::cout << "Current in "<< spaceName << std::endl;
    if(up){
        std::cout << "Up is "<< up->getSpaceName() << std::endl;
        potentialMoves.push_back(UP);
    }
    if(left){
        std::cout << "Left is "<< left->getSpaceName() << std::endl;
        potentialMoves.push_back(LEFT);
    }
    if(down && flag){
        std::cout << "Down is "<< down->getSpaceName() << std::endl;
        potentialMoves.push_back(DOWN);
    }
    if(right){
        std::cout << "Right is "<< right->getSpaceName() << std::endl;
        potentialMoves.push_back(RIGHT);
    }

    std::sort( potentialMoves.begin(), potentialMoves.end() );
    potentialMoves.erase( unique( potentialMoves.begin(), potentialMoves.end() ), potentialMoves.end() );
}
