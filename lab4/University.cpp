//
// Created by Shuheng Li on 1/31/18.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "University.h"
#include "Student.h"
#include "Instructor.h"

University::University(const std::string &name) : name(name) {
    std::shared_ptr<Buildings> buildingTemp = std::make_shared<Buildings>("AB 6 Small Shed-Berry Creek", 1018, "27280 TAMPICO RD CORVALLIS, OR 97330");
    this->building.push_back(buildingTemp);
    buildingTemp = std::make_shared<Buildings>("AB Adair Hay Store-Loaf S", 6930, "27280 TAMPICO RD CORVALLIS, OR 97330");
    this->building.push_back(buildingTemp);

}

void University::printBuildings() {
    std::cout << "All Building Information Are Below" << std::endl;
    std::cout << "*********************************" << std::endl << std::endl << std::endl;
    for(auto &t : this->building){
        t->getInformation();
    }
}

void University::printPeople() {
    std::cout << "All People Information Are Below" << std::endl;
    std::cout << "*********************************" << std::endl << std::endl << std::endl;
    for(auto &p : this->people){
        p->getInformation();
    }
}

void University::addNewPeopel(const std::shared_ptr<People> & people) {
    this->people.push_back(people);
    std::cout <<"People add succeed"<<  std::endl;
}

void University::addNewBuilding(const std::shared_ptr<Buildings> &building) {
    this->building.push_back(building);
}

void University::printPeopleName() {
    std::cout <<"Please Enter number for People" << std::endl;

    for(int i = 0; i < people.size(); i++){
        std::cout << i << ". " << people[i]->getName()<< std::endl;
    }
}

void University::doWork(int index) {
    people[index]->doWork();
}

void University::saveToFile() {
    std::string fileName = "buildings.txt";
    std::ofstream file(fileName.c_str());
    if(file.fail()){
        std::cerr << " Can not create a file Program exit." << std::endl;
        exit(2);
    }
    for(auto &b : this->building) {
        std::string s = b->toString();
        file << s;
    }
    file.close();
    std::cout <<"Building information saved to "<< fileName << std::endl;

    fileName = "people.txt";
    file.open(fileName);
    if(file.fail()){
        std::cerr << " Can not create a file Program exit." << std::endl;
        exit(2);
    }

    for(auto &p : this->people) {
        std::string s = p->toString();
        file << s;
    }
    file.close();
    std::cout <<"Peopel information saved to "<< fileName << std::endl;
}

void University::loadFromFile() {
    this->building.clear();
    this->people.clear();
    this->parseBuilding();
    this->parsePeople();
    std::cout <<"Load file succeed"<<  std::endl;
}

bool University::checkFileExist(const std::string & fileName) {
    bool res = true;
    std::ifstream infile(fileName.c_str());
    if(infile.fail()){
        std::cerr << "Can not found your "<< fileName << std::endl;
        res = false;
    }
    infile.close();
    return res;
}

void University::parseBuilding() {
    std::string fileName ="buildings.txt";
    if(!checkFileExist(fileName)){
        exit(-1);
    }
    std::ifstream infile(fileName.c_str());
    std::string name, sizeString, address;
    float size;
    while(!infile.eof()){
        getline(infile, name);
        getline(infile, sizeString);
        getline(infile, address);
        size = std::stof(sizeString);
        std::shared_ptr<Buildings> b = std::make_shared<Buildings>(name, size, address);
        building.push_back(b);
    }
}

void University::parsePeople() {
    std::string fileName ="people.txt";
    if(!checkFileExist(fileName)){
        exit(-1);
    }
    std::ifstream infile(fileName.c_str());
    std::string type, pname, ageS, otherS;
    int age = 0;
    float other = 0;
    while(!infile.eof()){
        getline(infile, type);
        getline(infile, pname);
        getline(infile, ageS);
        getline(infile, otherS);
        age = std::stoi(ageS);
        other= std::stof(otherS);

        std::shared_ptr<People> temp;
        if(type == "Student"){
            temp = std::make_shared<Student>(pname, age, other);
        } else if(type == "Instructor"){
            temp = std::make_shared<Instructor>(pname, age, other);
        }
        people.push_back(temp);
    }

}

void University::split(const std::string& s, char c, std::vector<std::string>& v) {
    std::string::size_type i = 0;
    std::string::size_type j = s.find(c);

    while (j != std::string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);

        if (j == std::string::npos)
            v.push_back(s.substr(i, s.length()));
    }
}

const std::vector<std::shared_ptr<People>> &University::getPeople() const {
    return people;
}
