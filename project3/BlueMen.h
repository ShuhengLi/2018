//
// Created by Shuheng Li on 2/6/18.
//

#ifndef PROJECT3_BLUEMEN_H
#define PROJECT3_BLUEMEN_H

#include "Character.h"

class BlueMen : public Character{
public:
    BlueMen();
    void defense(int) override;
    bool ability() override;
    std::string characterstis() override;
};


#endif //PROJECT3_BLUEMEN_H
