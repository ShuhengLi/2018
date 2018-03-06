//
// Created by Shuheng Li on 2/6/18.
//

#include "Medusa.h"
#include "Helper.h"

Medusa::Medusa() {
    type = MEDUSA;
    _attackRange = 6;
    _attackRolls = 2;
    _defenseRange = 6;
    _defenseRolls = 1;
    _armor = 3;
    _strength = 8;

}

int Medusa::attack() {
    Character::attack();
    if(ability()){
        std::cout << "Medusa ability Glare triggered, turn defender to stone " << std::endl;
        _attackVal= 99999;
    }
    return _attackVal;
}

bool Medusa::ability() {
    return _attackVal == 12;
}

std::string Medusa::characterstis() {
    std::string res = "Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!";
    return res;
}
