#include "Raymond.h"
#include <iomanip>
#include <iostream>
Raymond::Raymond() {
    spaceName = "Roymond Liu";
    flag = false;
}

void Raymond::event() {
    if(flag){
        std::cout << "\"You did great job, you got my pass\"" << std::endl;
    }
    std::cout << "\"My name is Roymond! I'm the TA for CS-162!\"" << std::endl;
    if(!geek->hasItem(MACBOOK)){
        std::cout << "\" You don't even have a computer! Go back to your seat!\"" << std::endl;
        return;
    }

    std::cout << "\"You got your Macbook, that's good, please answer my question:"
            " What language we learnt in CS-162\" " << std::endl;
    if(!geek->hasItem(CPLUSPLUS)){
        std::cout << "\"You don't know the answer? Go back to your seat!\" " << std::endl;
        return;
    }
    std::cout << "You said: \"CPLUSPLUS\"" << std::endl;
    std::cout << "\"Well done!Next question: What's algorithm?\"" << std::endl;
    if(!geek->hasItem(CPLUSPLUSBRAIN)){
        std::cout << "\"You don't know the answer? Go back to your seat!\" " << std::endl;
        return;
    }
    //cites wiki
    std::cout << "You said: \"Algorithm is a process or set of rules to be followed in calculations or other problem-solving operations, especially by a computer. \"" << std::endl;
    std::cout << "\"Bravo! \"" << std::endl;
    flag = true;
}

void Raymond::showInfo() {
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
        std::cout << right->getSpaceName();
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
