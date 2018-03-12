#include "Steve.h"
#include <iostream>
#include "Helper.h"

Steve::Steve() : Space() {
    spaceName = "Steve Jobs";
}

void Steve::event() {
    if(geek->hasItem(MACBOOK)){
        std::cout << "\"Enjoying your Macbook!\"" << std::endl;
    }
    std::cout << "\"My name is Steve, have you heard about macbook?\"" << std::endl;
    if(geek->hasItem(MONEY)){
        std::cout << "\"You must buy this production!\"" << std::endl;
        std::cout << "Do you want to buy this computer?" << std::endl;
        std::cout << "1. Yes          2. No" << std::endl;
        int choice = checkInput(1, 2);
        if(choice == 1){
            std::cout << "You bought a macbook from Steve Jobs" << std::endl;
            geek->getItem(MACBOOK);
        } else{
            std::cout << "\"You would regret your decision!\"" << std::endl;
        }
    } else{
        std::cout << "\"You don't have money? I suggest you go make some meney.\"" << std::endl;
    }
}
