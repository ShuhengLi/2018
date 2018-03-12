#include <iostream>
#include <string>
#include "Geek.h"
#include "Space.h"

Geek::Geek(const std::string &name) : name(name) {}

void Geek::getItem(const Item item) {
    if(hasItem(item)){
        std::cout << "Already has this item" << std::endl;
        return;
    }
    std::cout << "You got "<< item2String[item] << std::endl;
    items.insert(item);
}

bool Geek::hasItem(const Item item) {
    return  items.find(item) != items.end() ? true : false;
}

void Geek::removeItem(const Item item) {
    if(!hasItem(item)){
        std::cout << "You don't have this item, can not remove it" << std::endl;
    } else{
        auto it = items.find(item);
        items.erase(it);
    }
}

const std::string &Geek::getName() const {
    return name;
}

void Geek::setCurrentSpace(const std::shared_ptr<Space> &currentSpace) {
    Geek::currentSpace = currentSpace;
}

const std::shared_ptr<Space> &Geek::getCurrentSpace() const {
    return currentSpace;
}

void Geek::listItems() {
    for(auto it = items.begin(); it != items.end(); it++){
        std::cout << item2String[*it]<< std::endl;
    }

}
