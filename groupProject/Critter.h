#ifndef GROUPPROJECT_CRITTER_H
#define GROUPPROJECT_CRITTER_H

#include <map>
#include <vector>
#include <memory>
#include "CritterType.h"
#include "Position.h"
#include "Status.h"
class Grid;

class Critter {
protected:
    Position position;
    CritterType type;
    int step;
    int direstionNumbers;
    int breedThreshod;
    bool moved;

protected:
    std::map<int, Position> directions;//0 up, 1 down, 2 left, 3 right
    void initDirections();
    std::vector<int> potentialMoves(std::shared_ptr<Grid>);
public:
    Critter();
    Critter(const Position &position);
    Critter(const int, const int);

    virtual Status move(std::shared_ptr<Grid>);
    virtual bool breed(std::shared_ptr<Grid>);
    CritterType getType() const;
    const Position getPosition() const;
    const int getX() const;
    const int getY() const;
    bool isMoved() const;
    void setMoved(bool moved);
};


#endif //GROUPPROJECT_CRITTER_H
