#ifndef FINALPROJECT_JERRY_H
#define FINALPROJECT_JERRY_H

#include "Space.h"

class Jerry : public Space{
private:
    bool flag;
public:
    void event() override;
    void showInfo() override;

    Jerry();
};


#endif //FINALPROJECT_JERRY_H
