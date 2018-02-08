//
// Created by Shuheng Li on 1/29/18.
//

#ifndef PROJECT2_TURTLES_H
#define PROJECT2_TURTLES_H

#include "Animal.h"

class Turtle: public Animal{
public:
    Turtle();

    Turtle(int age);
    float getCost() override;
    int getNumberOfBabies() override;
    float getBaseFoodCost() override;
    float getPayOff() override;
    AnimalType getType() override;
};


#endif //PROJECT2_TURTLES_H
