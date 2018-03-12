#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H

#include "Space.h"
#include "Geek.h"
#include <memory>

class Game {
private:
    std::shared_ptr<Geek> player;
    void initMap();
    void initGeek();
    std::shared_ptr<Space> startPoint;
    int steps;
public:
    Game();
    void action();
    void showMapAndMove();
    void listItems();
    void instruction();
};


#endif //FINALPROJECT_GAME_H
