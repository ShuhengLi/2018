//
// Created by Shuheng Li on 1/29/18.
//

#ifndef PROJECT2_ZOO_H
#define PROJECT2_ZOO_H

#include "AnimalType.h"
#include "AnimalArray.h"
#include "Animal.h"
#include "Tiger.h"
#include "Penguin.h"
#include "Turtle.h"

class Zoo {
private:
    float bonus;
    AnimalArray tigerArray;
    AnimalArray penguinArray;
    AnimalArray turtleArray;

    void sickness();
    void boom();
    void babyBorn();
    void removeElemnt(AnimalType);
    bool hasAdult(AnimalType);
    AnimalType randomType();
    int getChildNum(AnimalType);
public:
    static float money;
    Zoo(float money);
    float feedCost();
    void randomEvent();
    float profit();
    void addAnimal(AnimalType, int);
    void newDay();
    void buyAnimals(int age);

};


#endif //PROJECT2_ZOO_H
