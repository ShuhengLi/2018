//
// Created by Shuheng Li on 2/6/18.
//

#ifndef PROJECT3_BARBARIAN_H
#define PROJECT3_BARBARIAN_H

#include "Character.h"

class Barbarian : public  Character{
public:
    Barbarian();
    bool ability() override;
    std::string characterstis() override;
};


#endif //PROJECT3_BARBARIAN_H
