//
// Created by Shuheng Li on 1/31/18.
//

#ifndef LAB4_STUDENT_H
#define LAB4_STUDENT_H


#include "People.h"
#include <string>

class Student : public People {
private:
    float gpa;

public:
    Student();
    Student(const std::string& );
    Student(const std::string&, int, float);
    void doWork() override;
    void getInformation() override;
    std::string toString() override;
};


#endif //LAB4_STUDENT_H
