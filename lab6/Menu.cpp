//
// Created by Shuheng Li on 2/12/18.
//

#include "Menu.h"
#include "Helper.h"
#include <iostream>
Menu::Menu() {
    list = std::make_shared<DoubleLinkedList>();
    choice = 0;
}

void Menu::action() {
    switch (choice){
        case 1: addHead();
            break;
        case 2: addTail();
            break;
        case 3: deleteHead();
            break;
        case 4: deleteTail();
            break;
        case 5: listBackward();
            break;
        default:
            break;
    }
}

bool Menu::keepPlaying() {
    std::cout << "*****************************************" << std::endl;
    std::cout << "1. Add a new node to the head;\n"
            "2. Add a new node to the tail;\n"
            "3. Delete from head;\n"
            "4. Delete from tail;\n"
            "5. Traverse the list reversely;\n"
            "6. Exit."<< std::endl;
    choice = checkInput(1, 6);

    return choice != 6;
}

void Menu::addHead() {
    std::cout << "input value" << std::endl;
    int value = checkInputInt();
    std::shared_ptr<Node> temp= std::make_shared<Node>(value);
    list->addHead(temp);
    showInfo();
}

void Menu::addTail() {
    std::cout << "input value" << std::endl;
    int value = checkInputInt();
    std::shared_ptr<Node> temp= std::make_shared<Node>(value);
    list->addTail(temp);
    showInfo();
}

void Menu::deleteHead() {
    list->deleteHead();
    showInfo();
}

void Menu::deleteTail() {
    list->deleteTail();
    showInfo();
}

void Menu::listBackward() {
    list->listBackward();
}

void Menu::showInfo() {
    std::cout<< "Your linked list is: ";
    list->listForward();
    std::cout<< "Head is " << list->currentHead() << std::endl;
    std::cout<< "Tail is " << list->currentTail() << std::endl;

}
