//
// Created by Shuheng Li on 1/29/18.
//

#ifndef PROJECT2_PENGUIN_H
#define PROJECT2_PENGUIN_H

#include "Animal.h"
class Penguin: public Animal{
public:
    Penguin();

    Penguin(int age);
    float getCost() override;
    int getNumberOfBabies() override;
    float getBaseFoodCost() override;
    float getPayOff() override;
    AnimalType getType() override;
};


#endif //PROJECT2_PENGUIN_H
