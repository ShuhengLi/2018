//
// Created by Shuheng Li on 2/20/18.
//

#ifndef LAB7_NODE_H
#define LAB7_NODE_H

#include <memory>

class Node {
public:
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;
    int val;

    Node(int val);

};


#endif //LAB7_NODE_H
