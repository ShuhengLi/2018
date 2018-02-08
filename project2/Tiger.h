//
// Created by Shuheng Li on 1/29/18.
//
#ifndef PROJECT2_TIGER_H
#define PROJECT2_TIGER_H

#include "Animal.h"

class Tiger: public Animal{
public:
    Tiger();

    Tiger(int age);
    float getCost() override;
    int getNumberOfBabies() override;
    float getBaseFoodCost() override;
    float getPayOff() override;
    AnimalType getType() override;
};


#endif //PROJECT2_TIGER_H
