#include <iostream>
#include <memory>
#include "Menu.h"

int main() {
    std::shared_ptr<Menu> menu = std::make_shared<Menu>();
    menu->initQueue();
    menu->simulated();
    return 0;
}