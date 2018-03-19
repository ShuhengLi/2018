#include "Meng.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

void Meng::event() {
    if(geek->hasItem(GUITAR)){
        std::cout << "\"Hi, my name is Meng Yan. How are you doing today!\"" << std::endl;
        std::cout << "\"You guitar is beautiful, you must be a musician!\"" << std::endl;
        std::cout << "\"WHAT!? You are in a wrong classroom?\"" << std::endl;
        std::cout << "\"Let me hlep you get out this class. There is another door behind my seat, you could you that one.\"" << std::endl;
        flags[DOWN] = true;
    } else{
        std::cout << "You try to talk to this gorgeous Chinese girl" << std::endl;
        std::cout << "\"Please don't disturb me while I'm studying CS-162.\" Meng said." << std::endl;
    }
}

Meng::Meng() : Space(){
    spaceName = "Meng";
    flags[DOWN] = false;
}

