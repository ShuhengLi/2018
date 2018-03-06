//
// Created by Shuheng Li on 2/6/18.
//

#include "BlueMen.h"
#include "Helper.h"
#include <iostream>

BlueMen::BlueMen() {
    type = BLUEMEN;
    _attackRange = 10;
    _attackRolls = 2;
    _defenseRange = 6;
    _defenseRolls = 3;
    _armor = 3;
    _strength = 12;

}

void BlueMen::defense(int damage) {
    if( ability()){
        std::cout << "Blue Men ability Mob triggered, roll 2 dice only for defense" << std::endl;
        _defenseRolls -= 1;
        Character::defense(damage);
        _defenseRolls += 1;
        return;
    }
    Character::defense(damage);
}

bool BlueMen::ability() {
    return _strength % 4 == 0;
}

std::string BlueMen::characterstis() {
    std::string res = "They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.";
    return res;
}
