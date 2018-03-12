#ifndef FINALPROJECT_DOOR_H
#define FINALPROJECT_DOOR_H

#include "Space.h"

class Door : public Space{
public:
    void event() override;

    Door();
};


#endif //FINALPROJECT_DOOR_H
