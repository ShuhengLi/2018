//
// Created by Shuheng Li on 2/6/18.
//

#include "Barbarian.h"
#include "Helper.h"

Barbarian::Barbarian() {
    type = BARBARIAN;
    _attackRange = 6;
    _attackRolls = 2;
    _defenseRange = 6;
    _defenseRolls = 2;
    _armor = 0;
    _strength = 12;

}

bool Barbarian::ability() {
    return false;
}

std::string Barbarian::characterstis() {
    std::string res = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
    return res;
}
