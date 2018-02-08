//
// Created by Shuheng Li on 1/29/18.
//

#include "Penguin.h"

Penguin::Penguin(int age){
    this->age = age;
    cost = 1000;
    numberOfBabies = 5;
    payoff = cost * 0.1;
}

float Penguin::getCost() {
    return cost;
}

int Penguin::getNumberOfBabies() {
    return numberOfBabies;
}

float Penguin::getBaseFoodCost() {
    return baseFoodCost;
}
float Penguin::getPayOff() {
    return payoff;
}

AnimalType Penguin::getType() {
    return PENGUIN;
}

Penguin::Penguin() {

}
