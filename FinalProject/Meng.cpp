#include "Meng.h"
#include <iostream>

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
