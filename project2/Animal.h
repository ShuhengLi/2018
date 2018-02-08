//
// Created by Shuheng Li on 1/29/18.
//

#ifndef PROJECT2_ANIMAL_H
#define PROJECT2_ANIMAL_H

#include "AnimalType.h"

class Animal {
protected:
    int age;
    float cost;
    int numberOfBabies;
    float baseFoodCost;
    float payoff;
public:
    Animal();
    Animal& operator=(const Animal A) ;
    void growUp();
    int getAge();
    virtual float getCost();
    virtual int getNumberOfBabies();
    virtual float getBaseFoodCost();
    virtual float getPayOff();
    virtual AnimalType getType();
};


#endif //PROJECT2_ANIMAL_H
