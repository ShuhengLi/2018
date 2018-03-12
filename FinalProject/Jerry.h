#ifndef FINALPROJECT_JERRY_H
#define FINALPROJECT_JERRY_H

#include "Space.h"

class Jerry : public Space{
public:
    void event() override;

    Jerry();
};


#endif //FINALPROJECT_JERRY_H
