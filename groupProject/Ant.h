//
// Created by Shuheng Li on 2/5/18.
//

#ifndef GROUPPROJECT_ANT_H
#define GROUPPROJECT_ANT_H

#include "Critter.h"
#include "CritterType.h"
#include "Position.h"
class Grid;

class Ant : public Critter, public std::enable_shared_from_this<Ant>{
public:
    Ant();
    Ant(int x, int y);
    Ant(Position p);

    Status move(std::shared_ptr<Grid>) override;
    bool breed(std::shared_ptr<Grid>) override;
};


#endif //GROUPPROJECT_ANT_H
