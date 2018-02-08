//
// Created by Shuheng Li on 1/29/18.
//

#include <cstdlib>
#include <iostream>
#include "Zoo.h"

float Zoo::money = money;

Zoo::Zoo(float m) {
    money = m;
    tigerArray =AnimalArray(TIGER, 0, 10);
    penguinArray = AnimalArray(PENGUIN, 0, 10);
    turtleArray = AnimalArray(TURTLE, 0, 10);
    int age = 1;
    buyAnimals(age);

}

void Zoo::randomEvent() {
    bonus = 0;
    int probability = 10;
    int random = (std::rand() % probability);
    switch(random){
        case 0: std::cout << "Sick Event!" << std::endl;
            sickness();
            break;
        case 1: std::cout << "Boom Event!" << std::endl;
            boom();
            break;
        case 2: std::cout << "Baby Event!" << std::endl;
            babyBorn();
            break;
        default:
            std::cout << "Nothing happened" << std::endl;
            break;
    }
}

float Zoo::profit() {
    float res = 0;
    float factor = 0;
    if(tigerArray.getSize() > 0){
        factor = 0.2;
        res += tigerArray.getSize() * tigerArray.at(0).getCost() * factor;
    }
    if(penguinArray.getSize() > 0){
        factor = 0.1;
        res += penguinArray.getSize() * penguinArray.at(0).getCost() * factor;
    }
    if(turtleArray.getSize() > 0){
        factor = 0.05;
        res += turtleArray.getSize() * turtleArray.at(0).getBaseFoodCost() * factor;
    }
    res += bonus;
    std::cout << "You make $" << res <<" today!" << std::endl;
    return res;
}

void Zoo::addAnimal(AnimalType animalType, int age) {
    switch (animalType){
        case TIGER: {
            Tiger temp(age);
            tigerArray.add(temp);
            break;
        }

        case PENGUIN: {
            Penguin temp(age);
            penguinArray.add(temp);
            break;

        }
        case TURTLE: {
            Turtle temp(age);
            turtleArray.add(temp);
            break;
        }
        default:
            std::cerr << "wrong type for add function"<< std::endl;
    }

}

void Zoo::sickness() {
    AnimalType animalType = randomType();
    removeElemnt(animalType);

}

void Zoo::boom() {
    float base = 250;
    int probability = 11;
    int random = (std::rand() % probability);
    float multiple = float(random) / 10 + float(1);
    bonus = base * multiple * tigerArray.getSize();
}

void Zoo::babyBorn() {
    AnimalType animalType = randomType();
    int age = 0;
    if(hasAdult(animalType)){
        std:: cout <<"Your" << animalType <<"has baby! Congraduation!"<< std::endl;
        for(int i = 0; i < getChildNum(animalType); i++){
           addAnimal(animalType, age);
        }
        return;
    }
    if(!hasAdult(TIGER) && !hasAdult(PENGUIN) && !hasAdult(TURTLE)){
        std::cout << "No Adult Animal, can not have baby" << std::endl;
        return;
    }
    babyBorn();
}

void Zoo::removeElemnt(AnimalType animalType) {
    switch (animalType){
        case TIGER: {
            std::cout<<"tiger";
            tigerArray.removeRandomElement();
            break;
            }
        case PENGUIN: {
            std::cout<<"penguin";
            penguinArray.removeRandomElement();
            break;
            }
        case TURTLE: {
            std::cout<<"turtle";
            turtleArray.removeRandomElement();
            break;
        }
        default:
            std::cerr << "wrong type for removeRandomElement function"<< std::endl;
    }

}

bool Zoo::hasAdult(AnimalType animalType) {
    switch (animalType){
        case TIGER: {
            return tigerArray.hasAdult();
        }
        case PENGUIN: {
            return penguinArray.hasAdult();
        }
        case TURTLE: {
            return turtleArray.hasAdult();
        }
        default:
            std::cerr << "wrong type for hasAdult function"<< std::endl;
    }
    return false;
}

AnimalType Zoo::randomType() {
    int range = 3;
    int random = (std::rand() % range) + 1;
    switch (random){
        case 1 : return TIGER;
        case 2 : return PENGUIN;
        case 3 : return TURTLE;
        default: return ANIMAL;

    }
}

int Zoo::getChildNum(AnimalType animalType) {
    switch (animalType){
        case TIGER: {
            return (tigerArray.getSize() > 0)? tigerArray.at(0).getNumberOfBabies() : 0;
        }
        case PENGUIN: {
            return (penguinArray.getSize() > 0)? penguinArray.at(0).getNumberOfBabies() : 0;
        }
        case TURTLE: {
            return (turtleArray.getSize() > 0)? turtleArray.at(0).getNumberOfBabies() : 0;
        }
        default:
            std::cerr << "wrong type for hasAdult function"<< std::endl;
    }
    return 0;
}

float Zoo::feedCost() {
    float res = 0;
    if(tigerArray.getSize() > 0){
        auto t = tigerArray.getArray();
        auto test = t[0].getBaseFoodCost();
       res += tigerArray.getSize() * tigerArray.at(0).getBaseFoodCost();
    }
    if(penguinArray.getSize() > 0){
        res += penguinArray.getSize() * penguinArray.at(0).getBaseFoodCost();
    }
    if(turtleArray.getSize() > 0){
        res += turtleArray.getSize() * turtleArray.at(0).getBaseFoodCost();
    }
    return res;
}

void Zoo::newDay() {
    if(tigerArray.getSize() > 0){
        for(int i = 0; i < tigerArray.getSize(); i++){
            tigerArray.at(i).growUp();
        }
    }
    if(penguinArray.getSize() > 0){
        for(int i = 0; i < penguinArray.getSize(); i++){
            penguinArray.at(i).growUp();
        }
    }
    if(turtleArray.getSize() > 0){
        for(int i = 0; i < turtleArray.getSize(); i++){
            turtleArray.at(i).growUp();
        }
    }
}

void Zoo::buyAnimals(int age) {
    int tigerSize = 0, penguinSize = 0, turtleSize = 0;
    std::cout << "Each tiger would cost your $10,000, how many tiger do you want to buy"<<std::endl;
    std::cin >> tigerSize;
    std::cout << "Each penguin would cost your $1,000, how many penguin do you want to buy"<<std::endl;
    std::cin >> penguinSize;
    std::cout << "Each turtle would cost your $100, how many turtle do you want to buy"<<std::endl;
    std::cin >> turtleSize;

    for(int i = 0; i < tigerSize; i++){
        Tiger *temp = new Tiger(i);
        tigerArray.add(*temp);
        money -= temp->getCost();
    }
    for(int i = 0; i < penguinSize; i++){
        /*
        Penguin temp(age);
        penguinArray.add(temp);
        money -= temp.getCost();
         */
        Penguin *temp = new Penguin(age);
        penguinArray.add(*temp);
        money -= temp->getCost();

    }

    for(int i = 0; i < turtleSize; i++){
        /*
        Turtle temp(age);
        turtleArray.add(temp);
        money -= temp.getCost();
         */
        Turtle *temp = new Turtle(age);
        turtleArray.add(*temp);
        money -= temp->getCost();
    }
}
