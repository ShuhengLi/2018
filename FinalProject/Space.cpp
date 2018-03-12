#include "Space.h"
#include "Helper.h"
#include <iostream>
#include <algorithm>
Space::Space() {}

void Space::showInfo() {
    std::cout << "Current in "<< spaceName << std::endl;
    if(up){
        std::cout << "Up is "<< up->getSpaceName() << std::endl;
        potentialMoves.push_back(UP);
    }
    if(left){
        std::cout << "Left is "<< left->getSpaceName() << std::endl;
        potentialMoves.push_back(LEFT);
    }
    if(down){
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

const std::string &Space::getSpaceName() const {
    return spaceName;
}

void Space::moveToHere(std::shared_ptr<Geek> geek) {
    this->geek = geek;

}

const std::vector<Direction> &Space::getPotentialMoves() const {
    return potentialMoves;
}
