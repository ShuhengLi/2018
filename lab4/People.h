//
// Created by Shuheng Li on 1/31/18.
//

#ifndef LAB4_PEOPLE_H
#define LAB4_PEOPLE_H

#include <string>
#include <string>

class People {
protected:
    std::string name;
    int age;
public:
    const std::string &getName() const;

    virtual void doWork();
    virtual void getInformation();
    virtual std::string toString();
};


#endif //LAB4_PEOPLE_H
