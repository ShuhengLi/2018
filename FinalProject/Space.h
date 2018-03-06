//
// Created by Shuheng Li on 3/5/18.
//

#ifndef FINALPROJECT_SPACE_H
#define FINALPROJECT_SPACE_H

#include <memory>
#include <string>


class Space {
public:
    Space();
    void showInfo();
    void hint();
    virtual void event() = 0;

private:
    std::shared_ptr<Space> up;
    std::shared_ptr<Space> down;
    std::shared_ptr<Space> left;
    std::shared_ptr<Space> right;
    int spaceId;
    std::string spaceName;
};


#endif //FINALPROJECT_SPACE_H
