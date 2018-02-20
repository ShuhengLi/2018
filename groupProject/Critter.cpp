#include "Critter.h"
#include "Grid.h"

Critter::Critter(){
    moved = false;
    step = 0;
    direstionNumbers = 4;
}

Critter::Critter(const Position &position) : position(position) {
    moved = false;
    type = EMPTY;
}

Critter::Critter(const int x, const int y) {
    moved = false;
    type = EMPTY;
    position.x = x;
    position.y = y;
}

void Critter::initDirections() {
    Position up{-1, 0};
    Position down{1, 0};
    Position left{0, -1};
    Position right{0, 1};
    directions[0] = up;
    directions[1] = down;
    directions[2] = left;
    directions[3] = right;

}

std::vector<int> Critter::potentialMoves(std::shared_ptr<Grid> grid) {
    std::vector<int> res;
    for(int i = 0; i < direstionNumbers; i++){
        Position newP = directions[i] + position;
        if(grid->checkEmpty(newP)){
            res.push_back(i);
        }
    }
    return res;
}

bool Critter::breed(std::shared_ptr<Grid>) {
    return false;
}

Status Critter::move(std::shared_ptr<Grid>) {
    return STAY;
}

const Position Critter::getPosition() const {
    return position;
}

CritterType Critter::getType() const {
    return type;
}

const int Critter::getX() const {
    return position.x;
}

const int Critter::getY() const {
    return position.y;
}

bool Critter::isMoved() const {
    return moved;
}

void Critter::setMoved(bool moved) {
    Critter::moved = moved;
}

