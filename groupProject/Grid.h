#ifndef GROUPPROJECT_GRID_H
#define GROUPPROJECT_GRID_H

#include <vector>
#include <memory>
#include "Critter.h"
class Grid : public std::enable_shared_from_this<Grid>{
private:
    int row;
    int column;
    int antNum;
    int doodlebugsNum;

    Critter*** grid;
    std::map<Status, int> reportAnt;
    std::map<Status, int> reportDoodlebugs;

    void initCritter();
    void initAnt();
    void initDoodlebugs();
    Position emptyRandomPosition();
    bool checkValid(int x, int y);
    bool checkValid(Position p);
public:
    Grid();
    Grid(int, int, int, int);
    bool checkEmpty(int x, int y);
    bool checkEmpty(Position p);
    bool checkAnt(int x, int y);
    bool checkAnt(Position p);
    void killCritter(int x, int y);

    virtual ~Grid();

    void killCritter(Position p);
    void move();
    void antMove();
    void doodlebugsMove();
    void breed();
    void antBreed();
    void doodlebugsBreed();
    void resetMovedFlag();
    void resetReports();
    void showReports();
    void addNew(Position, Critter*);
    void displayGrid();
    void displayAnt();
};


#endif //GROUPPROJECT_GRID_H
