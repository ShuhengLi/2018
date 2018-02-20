//
// Created by Shuheng Li on 2/12/18.
//

#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() {
    head = tail = nullptr;
}

DoubleLinkedList::DoubleLinkedList(std::shared_ptr<Node> node) {
    head = tail = node;
}

void DoubleLinkedList::addHead(std::shared_ptr<Node> node) {
    if(head == nullptr && tail == nullptr){
        head = tail = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void DoubleLinkedList::addTail(std::shared_ptr<Node> node) {
    if(head == nullptr && tail == nullptr){
        head = tail = node;
        return;
    }
    tail->next = node;
    node->prev = tail;
    tail = node;
}

void DoubleLinkedList::deleteHead() {
    if(head == nullptr){
        std::cout << "No element in list, can not delete" << std::endl;
        return;
    }
    if(head == tail){
        head = tail = nullptr;
        return;
    }
    head = head->next;
    if(head != nullptr){
        head->prev = nullptr;
    }
}

void DoubleLinkedList::deleteTail() {
    if(tail == nullptr){
        std::cout << "No element in list, can not delete" << std::endl;
        return;
    }
    if(head == tail){
        head = tail = nullptr;
        return;
    }
    tail = tail->prev;
    if(tail != nullptr){
        tail->next = nullptr;
    }
}

void DoubleLinkedList::listForward() {
    std::shared_ptr<Node> temp = head;
    if(tail == nullptr){
        std::cout << "double linked list is empty " << std::endl;
        return;
    }
    while(temp != nullptr){
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

}

void DoubleLinkedList::listBackward() {
    std::shared_ptr<Node> temp = tail;
    if(tail == nullptr){
        std::cout << "double linked list is empty " << std::endl;
        return;
    }
    while(temp != nullptr){
        std::cout << temp->val << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}

std::string DoubleLinkedList::currentHead() {
    if(head != nullptr){
        return std::to_string(head->val);
    }
    return "NULL Pointer";
}

std::string DoubleLinkedList::currentTail() {
    if(tail != nullptr){
        return std::to_string(tail->val);
    }
    return "NULL Pointer";
}


