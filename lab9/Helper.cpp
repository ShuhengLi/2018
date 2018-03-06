//
// Created by Shuheng Li on 3/6/18.
//

#include "Helper.h"
#include <cstdlib>

int random(int range) {
    int res = std::rand() % range;
    return res;
}

int randomOneBase(int range) {
    int res = (std::rand() % range) + 1;
    return res;
}

int checkInputInt(){
    int res;
    std::cin >> res;
    if(std::cin.fail() || std::cin.get()!='\n') {
        std::cout << "Error!! Input was not a INT. Please Input Again." << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        return checkInputInt();
    }
    return res;
}