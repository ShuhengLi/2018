//
// Created by Shuheng Li on 2/6/18.
//

#ifndef PROJECT3_CHARACTER_H
#define PROJECT3_CHARACTER_H

#include "CharacterType.h"
#include <string>

class Character {
private:
    int rollDice(int range, int turns);
protected:
    characterType type;
    int _attackRange;
    int _attackRolls;
    int _attackVal;
    int _defenseRange;
    int _defenseRolls;
    int _defenseVal;
    int _armor;
    int _strength;
    int damageCalc(int);
public:
    virtual int attack();
    virtual void defense(int);

    virtual bool ability() = 0;
    virtual std::string characterstis() = 0;

    characterType getType() const;
    int getArmor() const;
    int getStrength() const;
    int getAttackVal() const;
    int getDefenseVal() const;

    bool isDied() const;
};


#endif //PROJECT3_CHARACTER_H
