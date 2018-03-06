//
// Created by Shuheng Li on 2/6/18.
//
#include "Character.h"
#include "Helper.h"
#include <iostream>

int Character::attack() {
    _attackVal = 0;
    std::cout << "Attacker going to roll " << _attackRolls << " turns. Range from 1 to " << _attackRange << std::endl;
    _attackVal = rollDice(_attackRange, _attackRolls);
    std::cout << "Attacker dealing "<< _attackVal << " damage " << std::endl;
    return getAttackVal();
}

void Character::defense(int damage) {
    _defenseVal = 0;
    std::cout << "Defender going to roll " << _defenseRolls<< " turns. Range from 1 to " << _defenseRange << std::endl;

    _defenseVal = rollDice(_defenseRange, _defenseRolls);
    std::cout << "Defender defense value is  " << _defenseVal << std::endl;

    int totalDamage = damageCalc(damage);
    std::cout << "Defender takes "<< totalDamage << " damges." << std::endl;

    _strength  -= totalDamage;
}

int Character::rollDice(int range, int turns) {
    int res = 0;
    for(int i = 0; i < turns; i++){
        int value = randomOneBase(range);
        res += value;
    }
    return res;
}

characterType Character::getType() const {
    return type;
}

int Character::getArmor() const {
    return _armor;
}

int Character::getStrength() const {
    return _strength;
}

bool Character::isDied() const {
    return _strength <=0 ;
}

int Character::getAttackVal() const {
    return _attackVal;
}

int Character::getDefenseVal() const {
    return _defenseVal;
}

int Character::damageCalc(int attackVal) {
    int res = attackVal - _defenseVal - _armor;
    if(res < 0){
        res = 0;
    }
    return res;
}

void Character::setName(const std::string s){
    _name = s;
}
std::string Character::getName() const{
    return _name;
}

