//
// Created by Shuheng Li on 3/6/18.
//

#ifndef LAB9_MENU_H
#define LAB9_MENU_H

#include <queue>
#include <stack>
#include <string>

class Menu {
//-------------------------------Queue-------------------------------
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

//-------------------------------Stack-------------------------------
private:
    std::stack<char> stack;
    std::string firstPart;
public:
    void initStack();
    std::string convert2Palindrome();
};


#endif //LAB9_MENU_H
