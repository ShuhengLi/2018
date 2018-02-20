#ifndef GROUPPROJECT_HELPER_H
#define GROUPPROJECT_HELPER_H


int random(int range);
int checkInputPositive();

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

#endif //GROUPPROJECT_HELPER_H
