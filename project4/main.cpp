#include <iostream>
#include <memory>
#include "Menu.h"
#include <cstdlib>
#include <time.h>
int main() {
    srand(time(0));
    std::shared_ptr<Menu> menu = std::make_shared<Menu>();
    while(menu->keepPlaying()){
        menu->init();
        menu->action();
        std::cout << std::endl << std::endl;
    }
    return 0;
}