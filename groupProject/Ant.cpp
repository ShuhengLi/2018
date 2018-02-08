//
// Created by Shuheng Li on 2/5/18.
//

#include <iostream>
#include "Ant.h"
#include "Helper.h"
#include "Grid.h"

Ant::Ant() {
    step = 0;
    type = ANT;
    breedThreshod = 3;
    moved = false;
    initDirections();
}

Ant::Ant(int x, int y) : Ant() {
    position.x = x;
    position.y = y;
}

Ant::Ant(Position p) : Ant() {
    position = p;
}

Status Ant::move(std::shared_ptr<Grid> grid) {
    step += 1;
    moved = true;
    std::vector<int> moves = potentialMoves(grid);
    if (!moves.empty()){
        int move = random(moves.size());
        position = position + directions[moves[move]];
        grid->addNew(position, shared_from_this());
        grid->killCritter(position - directions[moves[move]]);
        return MOVED;
    }
    return STAY;
}

bool Ant::breed(std::shared_ptr<Grid> grid) {
    if(step < breedThreshod){
        return false;
    }
    step = 0;
    std::vector<int> moves = potentialMoves(grid);
    if (!moves.empty()){
        int move = random(moves.size());
        Position newP = directions[moves[move]] + position;
        std::shared_ptr<Critter> res = std::make_shared<Ant>(newP);
        res->setMoved(true);
        grid->addNew(newP, res);
        return true;
    }
    return false;
}
