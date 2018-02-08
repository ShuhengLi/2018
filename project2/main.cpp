#include <iostream>
#include "zoo.h"
#include <ctime>
#include <cstdlib>

Zoo initial();
int main() {
    srand(time(0));
    int age = 3;
    Zoo zoo = initial();
    while(true){
        Zoo::money -= zoo.feedCost();
        zoo.randomEvent();
        Zoo::money += zoo.profit();
        zoo.buyAnimals(3);
        std::cout << " remaining $"<< Zoo::money << std::endl;
        zoo.newDay();
    }
    return 0;
}

Zoo initial(){
    float money = 0, tigerS = 0, penguinS = 0, turtleS = 0;
    std::cout << "Welcome to Zoo tycoon game!" << std::endl;
    std::cout << "Please input your initialized money!" << std::endl;
    std::cin >> money;
    Zoo zoo(money);
    return zoo;
}
