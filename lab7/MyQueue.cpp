//
// Created by Shuheng Li on 2/20/18.
//

#include <iostream>
#include "MyQueue.h"

MyQueue::MyQueue() {}

MyQueue::~MyQueue() {

}

bool MyQueue::isEmpty() {
    return head == nullptr;
}

void MyQueue::addBack(int val) {
    std::shared_ptr<Node> temp = std::make_shared<Node>(val);
    if(isEmpty()){
        head = temp;
        head->next = head;
        head->prev = head;
    } else{
        std::shared_ptr<Node> last = head->prev;
        last->next = temp;
        temp->prev = last;
        temp->next = head;
        head->prev = temp;

    }
}

int MyQueue::getFront() {
    return head->val;
}

void MyQueue::removeFront() {
    if(head == nullptr || head->next == head){
        head = nullptr;
    } else{
        std::shared_ptr<Node> temp = head->prev;
        head = head->next;
        head->prev = temp;
        temp->next = head;
    }
}

void MyQueue::printQueue() {
    std::shared_ptr<Node> temp = head;
    if(temp == nullptr){
        std::cout << "Queue is empty " << std::endl;
        return;
    }

    do{
        std::cout << temp->val << " ";
        temp = temp->next;
    }while(temp != head);

    std::cout << std::endl;
}
