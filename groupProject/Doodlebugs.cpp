//
// Created by Shuheng Li on 2/5/18.
//

#include <memory>
#include <iostream>
#include "Doodlebugs.h"
#include "Helper.h"
#include "Grid.h"

Doodlebugs::Doodlebugs() {
    step = 0;
    type = DOOLEBUGS;
    breedThreshod = 8;
    starveStep = 0;
    starveThreshold = 3;
    moved = false;
    initDirections();
}

Doodlebugs::Doodlebugs(int x, int y) : Doodlebugs() {
    position.x = x;
    position.y = y;
}

Doodlebugs::Doodlebugs(Position p) : Doodlebugs(){
    position = p;
}

std::vector<int> Doodlebugs::getAnt() {
    return std::vector<int>();
}


Status Doodlebugs::move(std::shared_ptr<Grid> grid) {
    step += 1;
    moved = true;
    std::vector<int> antMoves = getAnt(grid);
    if(!antMoves.empty()){
        starveStep = 0;
        position = position + directions[antMoves[0]];
        grid->killCritter(position);
        grid->addNew(position, shared_from_this());
        grid->killCritter(position - directions[antMoves[0]]);
        return KILLING;
    }

    std::vector<int> moves = potentialMoves(grid);
    if (!moves.empty()){
        starveStep += 1;
        if(starveStep >= starveThreshold){
            grid->killCritter(position);
            return DIED;
        }
        int move = random(moves.size());
        position = position + directions[moves[move]];
        grid->addNew(position, shared_from_this());
        grid->killCritter(position - directions[moves[move]] );
        return MOVED;
    }

    return STAY;
}

bool Doodlebugs::breed(std::shared_ptr<Grid> grid) {
    if(step < breedThreshod){
        return false;
    }
    step = 0;
    std::vector<int> moves = potentialMoves(grid);
    if (!moves.empty()){
        int move = random(moves.size());
        Position newP = directions[moves[move]] + position;
        std::shared_ptr<Critter> res = std::make_shared<Doodlebugs>(newP);
        res->setMoved(true);
        grid->addNew(newP, res);
        return true;
    }
    return false;
}

std::vector<int> Doodlebugs::getAnt(std::shared_ptr<Grid> grid) {
    std::vector<int> res;
    for(int i = 0; i < direstionNumbers; i++){
        Position newP = directions[i] + position;
        if(grid->checkAnt(newP)){
            res.push_back(i);
        }
    }
    return res;
}

