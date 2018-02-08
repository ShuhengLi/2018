//
// Created by Shuheng Li on 2/7/18.
//

#include <iostream>
#include "Helper.h"
#include "Menu.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"

Menu::Menu() {
}


void Menu::init() {
    std::cout << "choose Attacker:"<< std::endl;
    showCharacters();
    attcker = choseCharacters();
    std::cout << "choose Defender:"<< std::endl;
    showCharacters();
    defender = choseCharacters();
}

void Menu::showCharacters() {
    std::cout << "0) Vampire"<< std::endl;
    std::cout << "1) Barbarian"<< std::endl;
    std::cout << "2) Blue Men"<< std::endl;
    std::cout << "3) Medusa"<< std::endl;
    std::cout << "4) Harry Potter"<< std::endl;

}

std::shared_ptr<Character>  Menu::choseCharacters() {
    int choose = checkInput(0, 4);
    std::shared_ptr<Character> res;
    switch(choose){
        case 0: res = std::make_shared<Vampire>();
            break;
        case 1: res = std::make_shared<Barbarian>();
            break;
        case 2: res = std::make_shared<BlueMen>();
            break;
        case 3: res = std::make_shared<Medusa>();
            break;
        case 4: res = std::make_shared<HarryPotter>();
            break;
    }
    return res;
}

void Menu::showAttackerInfo() {
    std::cout << "Attacker type  " << type2String(attcker->getType()) << std::endl;
}

void Menu::showDefenderInfo() {
    std::cout << "Defender type  " << type2String(defender->getType()) << std::endl;
    std::cout << "Defender's armor is  " << defender->getArmor() <<
              " ,Defender's strength point is " << defender->getStrength() << std::endl;

}

std::string Menu::type2String(characterType type) {
    std:: string res;
    switch(type){
        case VAMPIRE: res = "VAMPIRE";
            break;
        case BARBARIAN: res ="BARBARIAN";
            break;
        case BLUEMEN: res = "BLUEMEN";
            break;
        case MEDUSA: res ="MEDUSA";
            break;
        case HARRYPOTTER: res ="HARRYPOTTER";
            break;
    }
    return res;
}

void Menu::action() {
    while(!defender->isDied()){
        std::cout << "===========================New Turn===========================" << std::endl;
        int damage = attcker->attack();
        defender->defense(damage);
        std::cout << "Defender remain " << defender->getStrength() << " strength point" << std::endl;

    }
    std::cout << "Defender died" << std::endl;
    return;
}

bool Menu::keepPlaying() {
    std::cout << "1) Play Game    2) Exit" << std::endl;
    int choose = checkInput(1, 2);

    return choose == 1;
}

