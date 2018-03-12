#include "Steve.h"
#include <iostream>

Steve::Steve() {
    spaceName = "Steve Jobs";
}

void Steve::event() {
    std::cout << "\"My name is Steve, have you heard about macbook?\"" << std::endl;
    if(geek->hasItem(MONEY)){
        std::cout << "\"You must buy this production!\"" << std::endl;
        std::cout << "You bought a macbook from Steve Jobs" << std::endl;
        geek->getItem(MACBOOK);
    } else{
        std::cout << "\"You don't have money? I suggest you go make some meney.\"" << std::endl;
    }
}
