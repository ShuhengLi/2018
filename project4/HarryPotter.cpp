//
// Created by Shuheng Li on 2/6/18.
//

#include "HarryPotter.h"
#include "Helper.h"

HarryPotter::HarryPotter() {
    type = HARRYPOTTER;
    _attackRange = 6;
    _attackRolls = 2;
    _defenseRange = 6;
    _defenseRolls = 2;
    _armor = 0;
    _strength = 10;
    hogwarts = false;
}

void HarryPotter::defense(int damage) {
    Character::defense(damage);
    if (ability()){
        std::cout << "Harry Potter ability Hogwarts triggered, reborn! " << std::endl;
        _strength = 20;
    }
}

bool HarryPotter::ability() {
    bool res =_strength <= 0 && !hogwarts;
    if(res){
        hogwarts = true;
    }
    return res;
}

std::string HarryPotter::characterstis() {
    std::string res = "Harry Potter is a wizard.";
    return res;
}
