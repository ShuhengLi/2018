#ifndef FINALPROJECT_SPACE_H
#define FINALPROJECT_SPACE_H

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "Geek.h"
#include "Items.h"
#include "Direction.h"

class Space {
protected:
    std::string spaceName;
    std::shared_ptr<Geek> geek;
    std::vector<Direction> potentialMoves;
    std::map<Direction, bool> flags;
public:
    Space();

    const std::string &getSpaceName() const;
    void moveToHere(std::shared_ptr<Geek> geek);
    void showInfo();
    const std::vector<Direction> &getPotentialMoves() const;
    virtual void event() = 0;

    std::shared_ptr<Space> up;
    std::shared_ptr<Space> down;
    std::shared_ptr<Space> left;
    std::shared_ptr<Space> right;
};


#endif //FINALPROJECT_SPACE_H
