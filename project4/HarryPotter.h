//
// Created by Shuheng Li on 2/6/18.
//

#ifndef PROJECT3_HARRYPOTTER_H
#define PROJECT3_HARRYPOTTER_H

#include "Character.h"

class HarryPotter : public Character{
private:
    bool hogwarts;
public:
    HarryPotter();
    void defense(int) override;
    bool ability() override;
    std::string characterstis() override;
};


#endif //PROJECT3_HARRYPOTTER_H
