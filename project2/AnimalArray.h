//
// Created by Shuheng Li on 1/29/18.
//

#ifndef PROJECT2_ANIMALARRAY_H
#define PROJECT2_ANIMALARRAY_H

#include "AnimalType.h"
#include "Animal.h"
#include "Tiger.h"
#include "Penguin.h"
#include "Turtle.h"

class AnimalArray {
private:
    int size;
    int capacity;
    AnimalType animalType;
    Animal **array;
public:
    AnimalArray();
    AnimalArray(AnimalType, int s, int c);
    void doubleArraySize();
    void removeRandomElement();
    void removeElement(int index);
    void add(Animal animal);
    int getSize();
    int getCapacity();
    Animal at(int index);
    Animal* getArray();
    bool hasAdult();

};


#endif //PROJECT2_ANIMALARRAY_H
