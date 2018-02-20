#ifndef GROUPPROJECT_DOODLBUGS_H
#define GROUPPROJECT_DOODLBUGS_H

#include <memory>
#include <vector>
#include "Critter.h"
#include "CritterType.h"
#include "Position.h"
class Grid;
class Doodlebugs : public Critter, public std::enable_shared_from_this<Doodlebugs>{
private:
    int starveStep;
    int starveThreshold;
public:
    Doodlebugs();
    Doodlebugs(int x, int y);
    Doodlebugs(Position p);
    std::vector<int> getAnt();
    Status move(std::shared_ptr<Grid>) override;
    bool breed(std::shared_ptr<Grid>) override;
    std::vector<int> getAnt(std::shared_ptr<Grid>);

};


#endif //GROUPPROJECT_DOODLBUGS_H
