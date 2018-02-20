#include <cstdlib>
#include <iostream>

int random(int range) {
    int res = std::rand() % range;
    return res;
}

int checkInputPositive(){
    int res;
    std::cin >> res;
    if(res <= 0) {
        std::cout << "Error!! Input was in invalid range. Please Input Again." << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        return checkInputPositive();
    }
    if(std::cin.fail() || std::cin.get()!='\n') {
        std::cout << "Error!! Input was not a INT. Please Input Again." << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        return checkInputPositive();
    }
    return res;
}
