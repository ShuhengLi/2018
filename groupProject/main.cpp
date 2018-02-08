#include <iostream>
#include <memory>
#include "Grid.h"
#include <time.h>
int main() {
    //srand(time(0));
 //   std::shared_ptr<Grid> grid = std::make_shared<Grid>(10, 10, 40, 10);
    std::shared_ptr<Grid> grid = std::make_shared<Grid>();
    for(int i = 0; i < 10; i++){
        std::cout << "After " << i << "steps " << std::endl;
        grid->move();
        grid->displayGrid();
        std::cout << std::endl<< std::endl;

    }
    grid->move();
    grid->displayGrid();
    return 0;
}