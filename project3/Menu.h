//
// Created by Shuheng Li on 2/7/18.
//

#ifndef PROJECT3_MENU_H
#define PROJECT3_MENU_H

#include "Character.h"
#include "CharacterType.h"
#include <memory>
#include <string>

class Menu {
private:
    std::shared_ptr<Character> attcker;
    std::shared_ptr<Character> defender;

    void showCharacters();
    std::string type2String(characterType);
    std::shared_ptr<Character> choseCharacters();
public:
    Menu();
    void init();
    void showAttackerInfo();
    void showDefenderInfo();
    void action();
    bool keepPlaying();
};


#endif //PROJECT3_MENU_H
