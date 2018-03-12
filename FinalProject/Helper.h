//
// Created by Shuheng Li on 3/12/18.
//

#ifndef FINALPROJECT_HELPER_H
#define FINALPROJECT_HELPER_H

#include <iostream>

int checkInputInt();

template <class T>
bool checkRange(T target, T low, T high) {
    if(target < low || target > high){
        return false;
    }
    return true;
};


template <class T>
T checkInput(T low, T high){
    T res;
    std::cin >> res;
    if(!checkRange(res, low, high)) {
        std::cout << "Error!! Input was in invalid range. Please Input Again." << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        return checkInput(low, high);
    }
    if(std::cin.fail() || std::cin.get()!='\n') {
        std::cout << "Error!! Input was not a INT. Please Input Again." << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        return checkInput(low, high);
    }
    return res;
}


#endif //FINALPROJECT_HELPER_H
