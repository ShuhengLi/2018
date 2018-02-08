#include <iostream>
#include <cstdlib>
#include <time.h>
#include <memory>
#include <string>
#include "University.h"
#include "People.h"
#include "Student.h"
#include "Instructor.h"
#include "Menu.h"
#include "inputValidation.h"

std::shared_ptr<University> init();
std::shared_ptr<People> createNewPeople();



int main() {

    srand(time(0));
    std::shared_ptr<Menu> menu= std::make_shared<Menu>();
    std::shared_ptr<University> university = init();
    int choose = 0;
    bool flag = false;
    int high = 0;
    while(!flag){
        menu->displayMenu();
        switch(menu->getChoose()){
            case 1: university->printBuildings();
                break;

            case 2: university->printPeople();
                break;
            case 3: university->printPeopleName();
                high = university->getPeople().size();
                choose = checkInput(0, high);
                university->doWork(choose);
                break;
            case 4:
                flag = true;
            case 5: university->saveToFile();
                break;
            case 6: university->loadFromFile();
                break;
            case 7: auto newPeople = createNewPeople();
                university->addNewPeopel(newPeople);
                break;
        }

    }

    return 0;
}

std::shared_ptr<University> init(){
    std::string name = "Oregon State University";

    std::shared_ptr<University> university = std::make_shared<University>(name);
    name = "Peter";
    std::shared_ptr<People> peopel= std::make_shared<Student>(name);
    university->addNewPeopel(peopel);
    name = "John";
    peopel = std::make_shared<Instructor>(name);
    university->addNewPeopel(peopel);
    return university;
}

std::shared_ptr<People> createNewPeople() {
    std::shared_ptr<People> res;
    std::cout << "1. Instructor" << std::endl;
    std::cout << "2. Student" << std::endl;
    int type = checkInput(1, 2);
    std::cout << "Name :" << std::endl;
    std::string name;
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Age:" << std::endl;
    int age = checkInput(18, 60);
    if(type == 1){
        std::cout << "Rating:" << std::endl;
        float rating = checkInput(0.0, 5.0);
        res = std::make_shared<Instructor>(name, age, rating);
    }else{
        std::cout << "GPA:" << std::endl;
        float gpa =  checkInput(0.0, 4.0);
        res = std::make_shared<Student>(name, age, gpa);

    }
    return res;
}
