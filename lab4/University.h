//
// Created by Shuheng Li on 1/31/18.
//

#ifndef LAB4_UNIVERSITY_H
#define LAB4_UNIVERSITY_H

#include <string>
#include <vector>
#include <memory>
#include "Buildings.h"
#include "People.h"

class University {
private:
    std::string name;
    std::vector<std::shared_ptr<Buildings>> building;
    std::vector<std::shared_ptr<People>> people;
    bool checkFileExist(const std::string &);
    void parseBuilding();
    void parsePeople();
    void split(const std::string&, char, std::vector<std::string>& );
public:
    University(const std::string &name);

public:
    void printBuildings();

    const std::vector<std::shared_ptr<People>> &getPeople() const;

    void printPeople();
    void printPeopleName();
    void doWork(int index);
    void addNewPeopel(const std::shared_ptr<People>&);
    void addNewBuilding(const std::shared_ptr<Buildings>&);
    void saveToFile();
    void loadFromFile();

};


#endif //LAB4_UNIVERSITY_H
