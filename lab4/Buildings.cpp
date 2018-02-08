//
// Created by Shuheng Li on 1/31/18.
//

#include "Buildings.h"
#include <iostream>


Buildings::Buildings() {

}

Buildings::Buildings(const std::string &name, float size, const std::string &address) : name(name), size(size),
                                                                                        address(address) {}

void Buildings::getInformation() {
    std::cout << "=================================" << std::endl;
    std::cout << name << std::endl;
    std::cout << "address : " << address<< std::endl;
    std::cout << "size : " << size << std::endl;

}

void Buildings::setName(const std::string &name) {
    Buildings::name = name;
}

void Buildings::setSize(float size) {
    Buildings::size = size;
}

void Buildings::setAddress(const std::string &address) {
    Buildings::address = address;
}

std::string Buildings::toString() {
    std::string res;
    res = name + "\n" + std::to_string(size) + "\n" + address + "\n";
    return res;
}


