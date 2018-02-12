//
// Created by Shuheng Li on 2/12/18.
//

#ifndef LAB6_MENU_H
#define LAB6_MENU_H

#include "DoubleLinkedList.h"
#include <memory>

class Menu {
    std::shared_ptr<DoubleLinkedList> list;
    int choice;
    void addHead();
    void addTail();
    void deleteHead();
    void deleteTail();
    void listBackward();
    void showInfo();
public:
    Menu();
    void action();
    bool keepPlaying();
};


#endif //LAB6_MENU_H
