//
// Created by Shuheng Li on 2/1/18.
//

#include "Menu.h"
#include <iostream>
#include "inputValidation.h"

Menu::Menu() {
    std::cout << "Welcome to Oregon State University" << std::endl;
}

int Menu::getChoose() const {
    return choose;
}

void Menu::displayMenu() {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1.Prints information about all the buildings "<< std::endl;
    std::cout << "2.Prints information of everybody at the university"<< std::endl;
    std::cout << "3.Choose a person to do work "<< std::endl;
    std::cout << "4.Exit the program "<< std::endl;
    std::cout << "5.Save information to file"<< std::endl;
    std::cout << "6.Load information to file"<< std::endl;
    std::cout << "7.Add a new peopel"<< std::endl;
    int low = 1, high = 7;
    this->choose = checkInput(low, high);
    std::cout <<"you choose "<< this->choose<< std::endl;
    /*
    if(!checkRange(choose, low, high)){
        std::cout << "Please enter number between 1 to 7"<< std::endl;
        displayMenu();
    }

    */
}
