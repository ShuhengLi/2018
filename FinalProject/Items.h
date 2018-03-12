#ifndef FINALPROJECT_ITEMS_H
#define FINALPROJECT_ITEMS_H

#include <map>
#include <string>

enum Item{
    GUITAR,
    MONEY,
    MACBOOK,
    CPLUSPLUS,
    CPLUSPLUSBRAIN,
    CTRL_V
};

static std::map<Item, std::string> item2String = {
        {GUITAR, "GUITAR"},
        {MONEY, "MONEY"},
        {MACBOOK, "MACBOOK"},
        {CPLUSPLUS, "CPLUSPLUS"},
        {CPLUSPLUSBRAIN, "CPLUSPLUSBRAIN"},
        {CTRL_V, "CTRL_V"}
};
#endif //FINALPROJECT_ITEMS_H
