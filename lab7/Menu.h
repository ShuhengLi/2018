//
// Created by Shuheng Li on 2/20/18.
//

#ifndef LAB7_MENU_H
#define LAB7_MENU_H

#include "MyQueue.h"
#include <memory>

class Menu {
    std::shared_ptr<MyQueue> queue;
    int choice;
    void addTail();
    void showHead();
    void deleteHead();
    void showInfo();
public:
    Menu();
    void action();
    bool keepPlaying();
};


#endif //LAB7_MENU_H
