//
// Created by Shuheng Li on 1/31/18.
//

#ifndef LAB4_BUILDINGS_H
#define LAB4_BUILDINGS_H

#include <string>

class Buildings {
private:
    std::string name;
    float size;
    std::string address;
public:
    Buildings();
    Buildings(const std::string &name, float size, const std::string &address);

    void getInformation();
    void setName(const std::string &name);
    void setSize(float size);
    void setAddress(const std::string &address);
    std::string toString();
};


#endif //LAB4_BUILDINGS_H
