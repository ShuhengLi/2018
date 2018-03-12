#include "Raymond.h"
#include <iomanip>
#include <algorithm>
#include <iostream>
Raymond::Raymond() : Space(){
    spaceName = "Roymond Liu";
    flags[DOWN] = false;
}

void Raymond::event() {
    if(flags[DOWN]){
        std::cout << "\"You did great job, you got my pass\"" << std::endl;
    }
    std::cout << "\"My name is Roymond! I'm the TA for CS-162!\"" << std::endl;
    if(!geek->hasItem(MACBOOK)){
        std::cout << "\" You don't even have a computer! Go back to your seat!\"" << std::endl;
        return;
    }

    std::cout << "\"You got your Macbook, that's good, please answer my question:"
            " What language we learnt in CS-162\" " << std::endl;
    if(!geek->hasItem(CPLUSPLUS)){
        std::cout << "\"You don't know the answer? Go back to your seat!\" " << std::endl;
        return;
    }
    std::cout << "You said: \"CPLUSPLUS\"" << std::endl;
    std::cout << "\"Well done!Next question: What's algorithm?\"" << std::endl;
    if(!geek->hasItem(CPLUSPLUSBRAIN)){
        std::cout << "\"You don't know the answer? Go back to your seat!\" " << std::endl;
        return;
    }
    //cites wiki
    std::cout << "You said: \"Algorithm is a process or set of rules to be followed in calculations or other problem-solving operations, especially by a computer. \"" << std::endl;
    std::cout << "\"Bravo! \"" << std::endl;
    flags[DOWN] = true;
}

