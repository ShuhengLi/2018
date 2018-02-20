//
// Created by Shuheng Li on 2/20/18.
//

#ifndef LAB7_MYQUEUE_H
#define LAB7_MYQUEUE_H

#include <memory>
#include "Node.h"

class MyQueue {
private:
    std::shared_ptr<Node> head;
public:
    MyQueue();
    ~MyQueue();

    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();
};



#endif //LAB7_MYQUEUE_H
