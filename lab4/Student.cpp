//
// Created by Shuheng Li on 1/31/18.
//

#include <iostream>
#include <sstream>
#include <string>
#include "Student.h"
#include "RandomNum.h"
Student::Student(){
}

Student::Student(const std::string &name){
    this->name = name;
    this->age = randomNum(18, 30);
    int decimal = randomNum(41);
    this->gpa = float(decimal) / float(10.0);
}

Student::Student(const std::string &name, int age, float gpa){
    this->name = name;
    this->age = age;
    this->gpa = gpa;
}

void Student::doWork() {
    int range = 9;
    int hours = randomNum(range);
    std::cout << name << " did " << hours << " hours of homework" << std::endl;
}

void Student::getInformation() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Name : " << this->name << std::endl;
    std::cout << "Age : " << this->age << std::endl;
    std::cout << "GPA: " << this->gpa << std::endl;
}

std::string Student::toString() {
    std::string res;
    res = "Student\n";
    res += name + "\n" + std::to_string(age)+ "\n" + std::to_string(gpa) + "\n";
    return res;
}

