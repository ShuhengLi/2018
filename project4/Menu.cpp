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
    int num = initPlayers();
    for(int i = 0; i < num; i++){
        std::cout << "choose Attacker:"<< std::endl;
        showCharacters();
        q1.addBack(choseCharacters());
        std::cout << "choose Defender:"<< std::endl;
        showCharacters();
        q2.addBack(choseCharacters());
    }
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
    std::string name;
    std::cout << "Input the name for this player"<< std::endl;
    std::getline(std::cin, name);
    res->setName(name);
    return res;
}

void Menu::showAttackerInfo() {
    std::cout << "Attacker type  " << type2String(attcker->getType()) << std::endl;
    std::cout << "Attacker name " << attcker->getName() << std::endl;
}

void Menu::showDefenderInfo() {
    std::cout << "Defender type  " << type2String(defender->getType()) << std::endl;
    std::cout << "Defender name " << defender->getName() << std::endl;
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
    showQ(q1, "Team1 info:");
    showQ(q2, "Team2 info:");
    std::cout << "lose list is :" << std::endl;
    showLoseList();
    if(q1.isEmpty()){
        std::cout << "Team2 wins" << std::endl;
        return;
    }
    if(q2.isEmpty()){
        std::cout << "Team1 wins" << std::endl;
        return;
    }


    attcker = q1.getFront();
    defender = q2.getFront();
    int count = 0;
    std::swap(attcker, defender);
    do{
        std::swap(attcker, defender);
        std::cout << "===========================New Turn===========================" << std::endl;
        showAttackerInfo();
        showDefenderInfo();
        int damage = attcker->attack();
        defender->defense(damage);
        std::cout << "Defender remain " << defender->getStrength() << " strength point" << std::endl;
        count++;
    }while(!defender->isDied());
    std::cout << "Defender " << defender->getName() << " died" << std::endl;
    update(count);
    return;
}

bool Menu::keepPlaying() {
    std::cout << "1) Play Game  2)Show lose list  3) Exit" << std::endl;
    int choose = checkInput(1, 3);

    return choose != 3;
}

int Menu::initPlayers() {
    std::cout << "How many characters for each players" << std::endl;
    int numbers= checkInput(1, 10);
    return numbers;

}

void Menu::showQ(MyQueue<std::shared_ptr<Character>> q, std::string info){
    std::cout << info << std::endl;
    while(!q.isEmpty()){
        std::shared_ptr<Character> temp = q.getFront();
        std::cout << temp->getName() << std::endl;
        q.removeFront();
    }
    std::cout << std::endl;
}

void Menu::update(int count){
    if(count % 2){
        loseList.addBack(q2.getFront());
        q2.removeFront();
        auto temp = q1.getFront();
        q1.removeFront();
        q1.addBack(temp);
    } else{
        loseList.addBack(q1.getFront());
        q1.removeFront();
        auto temp = q2.getFront();
        q2.removeFront();
        q2.addBack(temp);
    }
    action();
}

void Menu::showLoseList(){
    if(loseList.isEmpty()){
        return;
    }
    auto temp = loseList.getFront();
    loseList.removeFront();
    showLoseList();
    std::cout << temp->getName() << std::endl;
    return;
}
