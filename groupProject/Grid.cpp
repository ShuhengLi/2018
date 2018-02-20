#include <iostream>
#include "Grid.h"
#include "Ant.h"
#include "Doodlebugs.h"
#include "Helper.h"

Grid::Grid() {
    row = 20;
    column = 20;
    antNum = 100;
    doodlebugsNum = 5;
    initCritter();
    initAnt();
    initDoodlebugs();
    resetReports();
}

Grid::Grid(int r, int c, int antN, int doodlebugsN): row(r), column(c), antNum(antN), doodlebugsNum(doodlebugsN) {
    initCritter();
    initAnt();
    initDoodlebugs();
    resetReports();
}

void Grid::initCritter() {
    grid = new Critter**[row];
    for(int i = 0; i < row; i++){
        grid[i] = new Critter*[column];
        for(int j = 0; j < column; j++){
            grid[i][j] = new Critter(i, j);
        }
    }
}

void Grid::initAnt() {
    for(int i = 0; i < antNum; i++){
        Position p = emptyRandomPosition();
        auto temp = grid[p.x][p.y];
        grid[p.x][p.y] = new Ant(p);
        delete temp;
    }
}

void Grid::initDoodlebugs() {
    for(int i = 0; i < doodlebugsNum; i++){
        Position p = emptyRandomPosition();
        auto temp = grid[p.x][p.y];
        grid[p.x][p.y] = new Doodlebugs(p);
        delete temp;
    }

}

Position Grid::emptyRandomPosition() {
    Position res;
    res.x = random(row);
    res.y = random(column);
    if(grid[res.x][res.y]->getType() != EMPTY){
        return emptyRandomPosition();
    }
    return res;
}

void Grid::displayGrid() {
    for(int j = 0; j < 2*row + 1; j++){
        std::cout << "-";
    }
    std::cout << "\033[4m" << std::endl;
    for(int i = 0; i < column; i++){
        for(int j = 0; j < row; j++){
            std::cout << "|";
            if(grid[i][j]->getType() == EMPTY){
                std::cout << " ";
            } else if(grid[i][j]->getType() == ANT){
                std::cout << "O";
            } else if(grid[i][j]->getType() == DOOLEBUGS){
                std::cout << "X";
            } else{
                std::cout << "m";
            }
        }
        std::cout << "|" << std::endl;

    }
    std::cout << "\033[0m" << std::endl;

}

void Grid::addNew(Position p, Critter* ptr) {
    auto temp = grid[p.x][p.y];
    grid[p.x][p.y] = ptr;
    delete temp;
}


bool Grid::checkValid(int x, int y) {
    if(x < 0 || x >= row|| y < 0 || y >= column){
        return false;
    }
    return true;
}

bool Grid::checkValid(Position p) {
    if(p.x < 0 || p.x >= row|| p.y < 0 || p.y >= column) {
        return false;
    }
    return true;
}

bool Grid::checkEmpty(int r, int c) {
    if(checkValid(r, c) ){
        if(grid[r][c]->getType() == EMPTY){
            return true;
        }
    }
    return false;
}

bool Grid::checkEmpty(Position p) {
    if(checkValid(p)) {
        if(grid[p.x][p.y]->getType() == EMPTY){
            return true;
        }
    }
    return false;
}


bool Grid::checkAnt(int x, int y) {
    if(checkValid(x, y) ){
        if(grid[x][y]->getType() == ANT){
            return true;
        }
    }
    return false;
}

bool Grid::checkAnt(Position p) {
    if(checkValid(p)) {
        if(grid[p.x][p.y]->getType() == ANT){
            return true;
        }
    }
    return false;
}

void Grid::killCritter(int x, int y) {
    grid[x][y] = new Critter(x, y);
}

void Grid::killCritter(Position p) {
    grid[p.x][p.y] = new Critter(p);
}

void Grid::move() {
    doodlebugsMove();
    antMove();
    breed();
    resetMovedFlag();
    showReports();
    resetReports();
}

void Grid::doodlebugsMove() {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j]->getType() == DOOLEBUGS && !grid[i][j]->isMoved()){
                Status status = grid[i][j]->move(shared_from_this());
                reportDoodlebugs[status] += 1;
            }
        }
    }
}

void Grid::antMove() {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j]->getType() == ANT && !grid[i][j]->isMoved()){
                Status status = grid[i][j]->move(shared_from_this());
                reportAnt[status] += 1;
            }
        }
    }

}

void Grid::resetMovedFlag() {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j]->getType() != EMPTY){
                grid[i][j]->setMoved(false);
            }
        }
    }

}

void Grid::displayAnt() {
    int count = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j]->getType() == ANT){
                count ++;
                std::cout << i << " " << j << std::endl;
            }
        }
    }
    std:: cout << "total ant are " << count<< std::endl;
}

void Grid::breed() {
    antBreed();
    doodlebugsBreed();
}

void Grid::antBreed() {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j]->getType() == ANT){
                if(grid[i][j]->breed(shared_from_this())){
                    reportAnt[BREED] += 1;
                }
            }
        }
    }

}

void Grid::doodlebugsBreed() {
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j]->getType() != EMPTY){
                if(grid[i][j]->breed(shared_from_this())){
                    reportDoodlebugs[BREED] += 1;
                }
            }
        }
    }
}

void Grid::resetReports() {
    reportAnt[STAY] = 0;
    reportAnt[MOVED] = 0;
    reportAnt[BREED] = 0;
    reportDoodlebugs[STAY] = 0;
    reportDoodlebugs[MOVED] = 0;
    reportDoodlebugs[KILLING] = 0;
    reportDoodlebugs[DIED] = 0;
    reportDoodlebugs[BREED] = 0;

}

void Grid::showReports() {
    std::cout << reportDoodlebugs[STAY] << " doodlebugs stay" << std::endl;
    std::cout << reportDoodlebugs[MOVED] << " doodlebugs  moved" << std::endl;
    std::cout << reportDoodlebugs[KILLING] << " doodlebugs  kill ant" << std::endl;
    std::cout << reportDoodlebugs[DIED] << " doodlebugs  died" << std::endl;
    std::cout << reportDoodlebugs[BREED]<< " doodlebugs borned" << std::endl;
    std::cout << reportAnt[STAY] << " Ant stay" << std::endl;
    std::cout << reportAnt[MOVED] << " Ant moved" << std::endl;
    std::cout << reportAnt[BREED]<< " Ant borned" << std::endl;

}

Grid::~Grid() {
    for(int i = 0; i < row; i++){
        delete[] grid[i];
    }
    delete[] grid;

}

