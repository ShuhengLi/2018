//
// Created by Shuheng Li on 2/5/18.
//

#ifndef GROUPPROJECT_POSITION_H
#define GROUPPROJECT_POSITION_H

struct Position{
    int x;
    int y;

    Position operator +(const Position& p){
        Position res;
        res.x = this->x + p.x;
        res.y = this->y + p.y;
        return res;
    }

    Position operator -(const Position& p){
        Position res;
        res.x = this->x - p.x;
        res.y = this->y - p.y;
        return res;
    }
    Position& operator =(const Position& p){
        x = p.x;
        y = p.y;
        return *this;
    }
    const bool operator ==(const Position& p){
        return (x == p.x && y == p.y);
    }

    Position operator += (const Position& p){
        Position res;
        res.x = this->x + p.x;
        res.y = this->y + p.y;
        return res;
    }
};

#endif //GROUPPROJECT_POSITION_H
