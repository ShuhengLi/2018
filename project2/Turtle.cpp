//
// Created by Shuheng Li on 1/29/18.
//

#include "Turtle.h"

Turtle::Turtle(int age){
    this->age = age;
    cost = 100;
    numberOfBabies = 10;
    payoff = cost * 0.05;
}

float Turtle::getCost() {
    return cost;
}

int Turtle::getNumberOfBabies() {
    return numberOfBabies;
}

float Turtle::getBaseFoodCost() {
    return baseFoodCost * 0.5;
}

float Turtle::getPayOff() {
    return payoff;
}

AnimalType Turtle::getType() {
    return TURTLE;
}

Turtle::Turtle() {

}
