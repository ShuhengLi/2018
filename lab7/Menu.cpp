//
// Created by Shuheng Li on 2/20/18.
//

#include "Menu.h"
#include "Helper.h"
#include <iostream>
Menu::Menu() {
    queue = std::make_shared<MyQueue>();
    choice = 0;
}

void Menu::action() {
    switch (choice){
        case 1: addTail();
            break;
        case 2: showHead();
            break;
        case 3: deleteHead();
            break;
        case 4: showInfo();
            break;
        default:
            break;
    }
}

bool Menu::keepPlaying() {
    std::cout << "*****************************************" << std::endl;
    std::cout << "1.Enter a value to be added to the back of queue\n"
            "2.Display first node (front) value\n"
            "3.Remove first node (front) value\n"
            "4.Display the queue contents\n"
            "5.Exit."<< std::endl;
    choice = checkInput(1, 5);

    return choice != 5;
}

void Menu::addTail() {
    std::cout << "input value" << std::endl;
    int value = checkInputInt();
    queue->addBack(value);
    showInfo();
}

void Menu::deleteHead() {
    queue->removeFront();
    showInfo();
}

void Menu::showInfo() {
    queue->printQueue();
}

void Menu::showHead() {
    if(queue->isEmpty()){
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Front Node value is " << queue->getFront() << std::endl;
    }
}
