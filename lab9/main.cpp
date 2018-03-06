#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include "Menu.h"

int main() {
    std::srand(time(0));
    std::shared_ptr<Menu> menu = std::make_shared<Menu>();
    return 0;
}