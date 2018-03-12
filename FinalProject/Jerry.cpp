#include "Jerry.h"
#include <iomanip>
#include <algorithm>
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
    std::cout << "Current location in " << spaceName << std::endl;
    if(up){
        std::cout << std::right << std::setw(40) << up->getSpaceName() << std::endl << std::endl;
        potentialMoves.push_back(UP);
    }
    int shift = 40;
    if(left){
        shift = 40 - left->getSpaceName().size();
        std::cout << left->getSpaceName();
        potentialMoves.push_back(LEFT);
    }
    std::cout << std::right << std::setw(shift) << spaceName;
    if(right){
        std::cout << std::right << std::setw(40) << right->getSpaceName();
        potentialMoves.push_back(RIGHT);
    }

    std::cout << std::endl << std::endl;
    if(down && flag){
        std::cout << std::right << std::setw(40) << down->getSpaceName() << std::endl << std::endl;
        potentialMoves.push_back(DOWN);
    }
    std::sort( potentialMoves.begin(), potentialMoves.end() );
    potentialMoves.erase( unique( potentialMoves.begin(), potentialMoves.end() ), potentialMoves.end() );
}
