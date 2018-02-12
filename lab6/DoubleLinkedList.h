//
// Created by Shuheng Li on 2/12/18.
//

#ifndef LAB6_DOUBLELINKEDLIST_H
#define LAB6_DOUBLELINKEDLIST_H

#include "Node.h"
#include <memory>
#include <string>

class DoubleLinkedList {
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    int size;
public:
    DoubleLinkedList(std::shared_ptr<Node> node);

    DoubleLinkedList();

    void addHead(std::shared_ptr<Node>);
    void addTail(std::shared_ptr<Node>);
    void deleteHead();
    void deleteTail();
    void listForward();
    void listBackward();
    std::string currentHead();
    std::string currentTail();

};


#endif //LAB6_DOUBLELINKEDLIST_H
