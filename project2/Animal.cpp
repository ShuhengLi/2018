//
// Created by Shuheng Li on 1/29/18.
//

#include "Animal.h"

Animal::Animal():baseFoodCost(10) {
}

void Animal::growUp() {
    age++;
}

int Animal::getAge() {
    return age;
}

AnimalType Animal::getType(){
    return ANIMAL;
}

Animal& Animal::operator=(Animal A){
    this->age = A.age;
    this->cost = A.cost;
    this->numberOfBabies = A.numberOfBabies;
    this->baseFoodCost = A.baseFoodCost;
    this->payoff = A.payoff;
}

float Animal::getCost() {
    return cost;
}

int Animal::getNumberOfBabies() {
    return numberOfBabies;
}

float Animal::getBaseFoodCost() {
    return baseFoodCost;
}

float Animal::getPayOff() {
    return payoff;
}

