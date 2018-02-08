//
// Created by Shuheng Li on 2/6/18.
//

#ifndef PROJECT3_MEDUSA_H
#define PROJECT3_MEDUSA_H

#include "Character.h"

class Medusa : public Character{
public:
    Medusa();
    int attack() override;
    bool ability() override;
    std::string characterstis() override;

};


#endif //PROJECT3_MEDUSA_H
