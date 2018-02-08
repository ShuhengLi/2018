//
// Created by Shuheng Li on 1/31/18.
//

#include <iostream>
#include <sstream>
#include "Instructor.h"
#include "RandomNum.h"

Instructor::Instructor(const std::string &name){
    this->name = name;
    this->age = randomNum(24, 60);
    int decimal = randomNum(51);
    this->rating= float(decimal) / float(10.0);
}

void Instructor::doWork() {
    int range = 30;
    int hours = randomNum(range);
    std::cout << name << " graded papers for " << hours << " hours." << std::endl;
}

float Instructor::getRating() const {
    return rating;
}

void Instructor::setRating(float rating) {
    Instructor::rating = rating;
}

void Instructor::getInformation() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Name : " << this->name << std::endl;
    std::cout << "Age : " << this->age << std::endl;
    std::cout << "Rating : " << this->rating << std::endl;
}

Instructor::Instructor() {}

Instructor::Instructor(const std::string &name, int age, float rating){
    this->name = name;
    this->age = age;
    this->rating = rating;
}

std::string Instructor::toString() {
    std::string s;
    s = "Instructor\n";
    s += name + "\n" + std::to_string(age) + "\n" + std::to_string(rating) + "\n";
    return s;
}

