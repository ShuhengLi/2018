//
// Created by Shuheng Li on 2/6/18.
//

#ifndef PROJECT3_VAMPIRE_H
#define PROJECT3_VAMPIRE_H

#include "Character.h"

class Vampire : public Character{

public:
    Vampire();
    void defense(int) override;
    bool ability() override;
    std::string characterstis() override;
};


#endif //PROJECT3_VAMPIRE_H
