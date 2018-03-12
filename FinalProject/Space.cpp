#include "Space.h"
#include "Helper.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
Space::Space() {}

void Space::showInfo() {
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
    if(down){
        std::cout << std::right << std::setw(40) << down->getSpaceName() << std::endl << std::endl;
        potentialMoves.push_back(DOWN);
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
