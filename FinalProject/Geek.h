#ifndef FINALPROJECT_GEEK_H
#define FINALPROJECT_GEEK_H

#include <memory>
#include <set>
#include <string>
#include "Items.h"

class Space;
class Geek {
private:
    std::shared_ptr<Space> currentSpace;
    std::set<Item> items;
    std::string name;

public:
    Geek(const std::string &name);

    const std::string &getName() const;
    void setCurrentSpace(const std::shared_ptr<Space> &currentSpace);

    void listItems();
    const std::shared_ptr<Space> &getCurrentSpace() const;
    void removeItem(const Item);
    void getItem(const Item);
    bool hasItem(const Item);
};


#endif //FINALPROJECT_GEEK_H
