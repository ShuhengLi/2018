
#include "Omniscience.h"
#include <iostream>

void Omniscience::event() {
    std::cout << "\"I am omniscient! I know everything in this planet\"" << std::endl;
    if(!geek->hasItem(MACBOOK)){
        std::cout << "\"I can't help you if you don't have a laptop, "
                "what kind of student woudl take computer science class without a COMPUTER?\"" << std::endl;
        return;
    }
    if(!geek->hasItem(CPLUSPLUS)){
        std::cout << "\"My child, this time to teach you CPLUSPLUS!!!!!!\" " << std::endl;
        geek->getItem(CPLUSPLUS);
        return;
    }
    if(!geek->hasItem(CPLUSPLUSBRAIN)){
        std::cout << "\"My child, CPLUSPLUS is not enough for escaping CS-162, "
                "let me show your my power CPLUSPLUSBRAIN!!!!!!!!!\" " << std::endl;
        geek->getItem(CPLUSPLUSBRAIN);
        return;
    }
    if(!geek->hasItem(CTRL_V)){
        std::cout << "\"WHAT!!!!!! CPLUSPLUS and CPLUSPLUSBRAIN are not enough!?"
                " You give me no choice, let me teach you the final ultimate true: CTRL_V!!!!!!!!!!!!!!!!!\" " << std::endl;
        geek->getItem(CTRL_V);
        return;
    }
}

Omniscience::Omniscience() {
    spaceName = "Omniscience";
}
