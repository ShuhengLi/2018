//
// Created by Shuheng Li on 2/6/18.
//

#include "Vampire.h"
#include "Helper.h"
#include <iostream>

Vampire::Vampire() {
    type = VAMPIRE;
    _attackRange = 12;
    _attackRolls = 1;
    _defenseRange = 6;
    _defenseRolls = 1;
    _armor = 1;
    _strength = 18;
}

void Vampire::defense(int damage) {
    if( ability()){
        std::cout << "Vampire ability Charm triggered, all damage to 0" << std::endl;
        return;
    }
    Character::defense(damage);

}

bool Vampire::ability() {
    return random(2);
}

std::string Vampire::characterstis() {
    std::string res = "Suave, debonair, but vicious and surprisingly resilient.";
    return res;
}
