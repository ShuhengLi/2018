#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "OriginalSeat.h"
#include "MusicTeacher.h"
#include "Steve.h"
#include "Omniscience.h"
#include "Raymond.h"
#include "Meng.h"
#include "Door.h"
#include "Jerry.h"
#include "Helper.h"

Game::Game() {
    steps = 0;
    std::cout << "Welcome to ESCAPE CS-162!!!!!" << std::endl;
    initMap();
    initGeek();
    instruction();
}

void Game::initGeek() {
    std::cout << "What's your name?"<< std::endl;
    std::string name;
    std::getline(std::cin, name);
    player = std::make_shared<Geek>(name);
    player->setCurrentSpace(startPoint);
    player->getItem(GUITAR);

}

void Game::instruction() {
    std::cout << "Hi " << player->getName() << "! You entered a class and found a sit in the middle of class."
            " You thought this is a music classroom, that's why you bring your guitar to this class"<< std::endl << std::endl;
    std::cout << "HOWEVER when the professor do the instruction of this class, you found out this is CS-162!!!!!!!!!" << std::endl << std::endl;
    std::cout << "You seat is in the center of the classroom, You have to find a way to get out of this class! "<< std::endl << std::endl;
    std::cout << "Each move would cost 2 mins, you got 50 mins to escape this classroom, GOOD LUCK!"<< std::endl << std::endl;

}

void Game::initMap() {
    startPoint = std::make_shared<OriginalSeat>();
    auto musicTeacher = std::make_shared<MusicTeacher>();
    auto meng = std::make_shared<Meng>();
    auto steve = std::make_shared<Steve>();
    auto omniscience = std::make_shared<Omniscience>();
    auto raymond = std::make_shared<Raymond>();
    auto jerry = std::make_shared<Jerry>();
    auto door = std::make_shared<Door>();

    startPoint->up = omniscience;
    startPoint->down = raymond;
    startPoint->left = musicTeacher;
    startPoint->right = steve;
    musicTeacher->left = meng;
    musicTeacher->right = startPoint;
    omniscience->down = startPoint;
    steve->left = startPoint;
    raymond->up = startPoint;
    raymond->down = jerry;
    jerry->down = door;
    jerry->up = raymond;
    meng->right = musicTeacher;
    meng->down = door;
    /*debug
    startPoint->showInfo();
    musicTeacher->showInfo();
    omniscience->showInfo();
    steve->showInfo();
    raymond->showInfo();
    jerry->showInfo();
    meng->showInfo();
    */
}

void Game::action() {
    int limit = 25;
    while(steps < limit){
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Remining " <<50 - steps * 2 << " minutes" << std::endl;
   //     listItems();
        auto current = player->getCurrentSpace();
        current->event();
        showMapAndMove();
        if(player->getCurrentSpace()->getSpaceName() == "Door")break;
        steps++;
        std::cout << std::endl;
    }
    if(player->getCurrentSpace()->getSpaceName() == "Door"){
        std::cout << "You WIN!!!" << std::endl;
    } else{
        std::cout << "You LOSE!!!" << std::endl;
    }

}

void Game::showMapAndMove() {
    auto current = player->getCurrentSpace();
    current->showInfo();
    std::cout << "Where you want to go?" << std::endl;
    auto moves = player->getCurrentSpace()->getPotentialMoves();
    for(int i = 0; i < moves.size();i++){
        std::cout << i + 1<< ".  " << direction2String[moves[i]] << std::endl;
    }
    int highLimit = moves.size();
    int choice = checkInput(1, highLimit);
    std::shared_ptr<Space> destination;
    switch(moves[choice - 1]){
        case UP:destination = current->up;
            break;
        case LEFT:destination = current->left;
            break;
        case DOWN:destination = current->down;
            break;
        case RIGHT:destination = current->right;
            break;
    }
    player->setCurrentSpace(destination);
    destination->moveToHere(player);
}

void Game::listItems() {
    std::cout << "Do you want to see your items?" << std::endl;
    std::cout << "1.Yes,   2. No." << std::endl;
    int choice = checkInput(1, 2);
    if(choice == 1){
        player->listItems();
    }

}
