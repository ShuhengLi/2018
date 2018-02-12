//
// Created by Shuheng Li on 2/12/18.
//

#ifndef LAB6_NODE_H
#define LAB6_NODE_H
#include <memory>

class Node {
public:
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;
    int val;

    Node(int val);

};


#endif //LAB6_NODE_H
