#include "Helper.h"

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