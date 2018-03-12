#ifndef FINALPROJECT_RAYMOND_H
#define FINALPROJECT_RAYMOND_H

#include "Space.h"

class Raymond : public Space{
private:
    bool flag;
public:
    void event() override;
    void showInfo() override ;

    Raymond();
};


#endif //FINALPROJECT_RAYMOND_H
