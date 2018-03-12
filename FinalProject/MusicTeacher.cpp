#include "MusicTeacher.h"
#include "Helper.h"
#include <iostream>

void MusicTeacher::event() {
    if(!geek){
        std::cerr << "Geek is nullptr in musicTeacher space";
        return;
    }
    if(geek->hasItem(GUITAR)){
        std::cout << "\"I'm a guitar musician.\"" << std::endl;
        std::cout << "\"You have a beautiful guitar! Do you want to sell it to me?\"" << std::endl;
        std::cout << "1.Yes  2.No" << std::endl;
        int choose = checkInput(1, 2);
        if(choose == 1){
            geek->removeItem(GUITAR);
            geek->getItem(MONEY);
        } else{
            std::cout << "\"I'm here waiting for you until you change your mind.\"" << std::endl;
        }
    } else{
        std::cout << "\"I love your guitar\"." << std::endl;
    }
}

MusicTeacher::MusicTeacher() : Space(){
    spaceName = "MusicTeacher";
}
