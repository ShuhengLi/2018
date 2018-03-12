#include "Meng.h"
#include <iostream>
#include <iomanip>

void Meng::event() {
    if(geek->hasItem(GUITAR)){
        std::cout << "\"Hi, my name is Meng Yan. How are you doing today!\"" << std::endl;
        std::cout << "\"You guitar is beautiful, you must be a musician!\"" << std::endl;
        std::cout << "\"WHAT!? You are in a wrong classroom?\"" << std::endl;
        std::cout << "\"Let me hlep you get out this class. There is another door behind my seat, you could you that one.\"" << std::endl;
        flag = true;
    } else{
        std::cout << "You try to talk to this gorgeous Chinese girl" << std::endl;
        std::cout << "\"Please don't disturb me while I'm studing CS-162.\" Meng said." << std::endl;
    }
}

Meng::Meng() {
    spaceName = "Meng";
    flag = false;
}

void Meng::showInfo() {
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
    std::cout << std::left<< std::setw(40) << spaceName;
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
