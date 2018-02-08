//
// Created by Shuheng Li on 1/31/18.
//

#ifndef LAB4_INSTRUCTOR_H
#define LAB4_INSTRUCTOR_H

#include "People.h"
#include <iostream>

class Instructor : public People{
private:
    float rating;
public:
    Instructor(const std::string &);
    Instructor(const std::string&, int, float);

    Instructor();

    void doWork() override;
    void getInformation() override ;
    std::string toString() override ;

    float getRating() const;
    void setRating(float rating);

};


#endif //LAB4_INSTRUCTOR_H
