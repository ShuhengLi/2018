#ifndef FINALPROJECT_MENG_H
#define FINALPROJECT_MENG_H

#include "Space.h"

class Meng : public Space {
private:
    bool flag;
public:
    void event() override;
    void showInfo() override ;

    Meng();
};


#endif //FINALPROJECT_MENG_H
