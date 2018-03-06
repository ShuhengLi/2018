//
// Created by Shuheng Li on 2/7/18.
//

#ifndef PROJECT3_MENU_H
#define PROJECT3_MENU_H

#include "Character.h"
#include "CharacterType.h"
#include "MyQueue.h"
#include <memory>
#include <string>

class Menu {
private:
    MyQueue<std::shared_ptr<Character>> q1;
    MyQueue<std::shared_ptr<Character>> q2;
    MyQueue<std::shared_ptr<Character>> loseList;

    std::shared_ptr<Character> attcker;
    std::shared_ptr<Character> defender;

    void showCharacters();
    int initPlayers();
    std::string type2String(characterType);
    std::shared_ptr<Character> choseCharacters();
public:
    Menu();
    void init();
    void showAttackerInfo();
    void showDefenderInfo();
    void action();
    void update(int);
    bool keepPlaying();
    void showQ(MyQueue<std::shared_ptr<Character>>, std::string);
    void showLoseList();
};


#endif //PROJECT3_MENU_H
