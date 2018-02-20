#include <iostream>
#include <memory>
#include <time.h>
#include "Helper.h"
#include "Grid.h"

std::shared_ptr<Grid> initGrid();
int main() {
    srand(time(0));
    std::shared_ptr<Grid> grid = initGrid();
    int chioce = 0;
    do{
        std::cout << "How many steps your want to move?" << std::endl;
        int steps = checkInputPositive();
        for(int i = 0; i < steps; i++){
            std::cout << "After " << i + 1 << " step " << std::endl;
            grid->move();
            grid->displayGrid();
            std::cout << std::endl<< std::endl;
        }
        std::cout << "1.Keep Moving     2.Exit" << std::endl;
        chioce = checkInput(1,2);
    } while(chioce != 2);
    return 0;
}

std::shared_ptr<Grid> initGrid(){
    std::cout << "I DID EXTRA EXTRA CREDIT !" << std::endl << std::endl;
    std::cout << "1.Default Grid   2.Customized Grid" << std::endl;
    std::shared_ptr<Grid> res = std::make_shared<Grid>();
    int choice = checkInput(1, 2);
    if(choice == 2){
        std::cout << "Input Row Number" << std::endl;
        int row = checkInputPositive();
        std::cout << "Input Column Number" << std::endl;
        int column = checkInputPositive();
        int highLimit = row * column;
        std::cout << "Input DoodleBug Number(Range from 0 to " << highLimit << ")" << std::endl;
        int doodleBugNum = checkInput(0, highLimit);
        std::cout << "Input Ant Number(Range from 0 to " << highLimit - doodleBugNum << ")" << std::endl;
        int antNum = checkInput(0, highLimit - doodleBugNum);
        res = std::make_shared<Grid>(row, column, antNum, doodleBugNum);
    }
    res->displayGrid();
    return res;
}
