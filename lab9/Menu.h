//
// Created by Shuheng Li on 3/6/18.
//

#ifndef LAB9_MENU_H
#define LAB9_MENU_H

#include <queue>

class Menu {
private:
    std::queue<int> queue;
    int rounds;
    int pushProbability;
    int popProbability;
    int currentRound;
    float lastAveLength;
    int generateRandom();
    void displayQueue();
    void calculateAveLength();
    bool pushQueue();
    bool popQueue();
public:
    Menu();
    void initQueue();
    void simulated();
};


#endif //LAB9_MENU_H
