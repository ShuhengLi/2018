#include <iostream>
#include <iomanip>
#include <memory>
#include "Game.h"

int main() {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    game->action();
    return 0;
}