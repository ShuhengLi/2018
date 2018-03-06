//
// Created by Shuheng Li on 3/6/18.
//
#include <iostream>
#include "Menu.h"
#include "Helper.h"

Menu::Menu() {
    lastAveLength = 0;
    currentRound = 0;
    std::cout << "1. Test Buffer    2. Create A Palindrome " << std::endl;
    int input = checkInput(1, 2);
    if(input == 1){
        initQueue();
        simulated();
    } else{
        initStack();
        std::string res = convert2Palindrome();
        std::cout << res << std::endl;
    }

}

void Menu::initQueue() {
    int lowBound = 1;
    int highBound = 1000;
    std::cout << "How many rounds to play?" << std::endl;
    rounds =  checkInput(lowBound, highBound);

    highBound = 100;
    std::cout << "What's the percentage to push the value to the queue?" << std::endl;
    pushProbability =  checkInput(lowBound, highBound);
    std::cout << "What's the percentage to pop the value from the queue?" << std::endl;
    popProbability =  checkInput(lowBound, highBound);
}

void Menu::simulated() {
    for(int i = 0 ; i < rounds; i++){
        std::cout << "============= This is " << i  + 1<< " round. =============" << std::endl;
        currentRound++;
        int value = generateRandom();
        if(pushQueue()){
            std::cout << "Push " << value << " to the queue."<< std::endl;
            queue.push(value);
        }
        if(popQueue()){
            std::cout << "Pop" << queue.front() << " from the queue."<< std::endl;
            queue.pop();
        }
        displayQueue();
        calculateAveLength();
    }
}


int Menu::generateRandom() {
    int highBound = 1000;
    return randomOneBase(highBound);
}

bool Menu::pushQueue() {
    int highBound = 100;
    int value = randomOneBase(highBound);
    return value <= pushProbability;
}

bool Menu::popQueue() {
    if(queue.empty()){
        return false;
    }
    int highBound = 100;
    int value = randomOneBase(highBound);
    return value <= popProbability;
}

void Menu::displayQueue() {
    std::queue<int> temp(queue);
    std::cout << "The queue values are :" << std::endl;
    while (!temp.empty()){
        std::cout << temp.front() << " " << std::endl;
        temp.pop();
    }
    std::cout << std::endl << "The Queue length is :" << queue.size() << std::endl;
}

void Menu::calculateAveLength() {
    lastAveLength = (lastAveLength * (currentRound - 1) + queue.size()) / currentRound;
    std::cout << "The average length is " << lastAveLength << std::endl;
    return ;
}


void Menu::initStack() {
    std::cout << "Please input a string: " << std::endl;
    std::getline(std::cin, firstPart);
    for(char c : firstPart){
        stack.push(c);
    }
}

std::string Menu::convert2Palindrome() {
    std::string res = firstPart;
    while(!stack.empty()){
        res.push_back(stack.top());
        stack.pop();
    }
    return res;
}

