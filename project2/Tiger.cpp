//
// Created by Shuheng Li on 1/29/18.
//

#include "Tiger.h"

Tiger::Tiger(int age){
    this->age = age;
    cost = 10000;
    numberOfBabies = 1;
    payoff = cost * 0.2;
}

float Tiger::getCost() {
    return cost;
}

int Tiger::getNumberOfBabies() {
    return numberOfBabies;
}

float Tiger::getBaseFoodCost() {
    return baseFoodCost * 5;
}
float Tiger::getPayOff() {
    return payoff;
}

AnimalType Tiger::getType() {
    return TIGER;
}

Tiger::Tiger() {

}
