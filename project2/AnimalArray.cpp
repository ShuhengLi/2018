//
// Created by Shuheng Li on 1/29/18.
//

#include <cstdlib>
#include <iostream>
#include "AnimalArray.h"
AnimalArray::AnimalArray(){

}

AnimalArray::AnimalArray(AnimalType t, int s, int c):animalType(t), size(s), capacity(c) {
    array = new Animal*[capacity];
}

void AnimalArray::doubleArraySize() {
    capacity = capacity * 2;
    Animal **newArray = new Animal*[capacity] ;

    for(int i = 0; i < size; i++){
        auto test = array[i];
        newArray[i] = test;
    }
    delete[] array;
    array = newArray;

}

void AnimalArray::removeRandomElement() {
    if(size <= 0){
        std::cerr << "Array size is less or equal to zero"<< std::endl;
        exit(-1);
    }
    int random = (std::rand() % (size + 1));
    removeElement(random);
}

void AnimalArray::removeElement(int index) {
    for(int i = index; i < size; i++){
        array[i] = array[i + 1];
    }
    size--;

}

void AnimalArray::add(Animal animal) {
    if(size >= capacity - 1 ){
        doubleArraySize();
    }
    array[size] = &animal;
    size = size + 1;
    return;

}

bool AnimalArray::hasAdult() {
    for(int i = 0; i < size; i++){
        if(array[i]->getAge() >= 3){
            return true;
        }
    }
    return false;
}

Animal AnimalArray::at(int index) {
    if(index > size || index < 0){
        std::cerr << "At fucntion out of index range"<< std::endl;
        exit(-1);

    }
    std::cout << array[index]<<std::endl;
    return *array[index];
}

int AnimalArray::getSize() {
    return size;
}

int AnimalArray::getCapacity() {
    return capacity;
}

Animal *AnimalArray::getArray() {
    return *array;
}

