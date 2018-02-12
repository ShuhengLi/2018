#include <iostream>
#include <memory>
#include "Menu.h"
int main() {
    std::shared_ptr<Menu> menu= std::make_shared<Menu>();
    while(menu->keepPlaying()){
        menu->action();
    }
    return 0;
}