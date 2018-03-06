//
// Created by Shuheng Li on 2/20/18.
//

#ifndef PROJECT4_TEST_H
#define PROJECT4_TEST_H

#include <memory>

template<class T>
class MyQueue {
private:
    struct Node{
        T data;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
        Node(T val){
            data = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    std::shared_ptr<Node> head;
public:
    MyQueue();

    bool isEmpty();
    void addBack(T val);
    T getFront();
    void removeFront();
    void printQueue();
};


template<class T>
MyQueue<T>::MyQueue() {
}

template<class T>
bool MyQueue<T>::isEmpty() {
    return head == nullptr;
}

template<class T>
void MyQueue<T>::addBack(T val) {
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
template<class T>
T MyQueue<T>::getFront() {
    return head->data;
}

template<class T>
void MyQueue<T>::removeFront() {
    if(head == nullptr || head->next == head){
        head = nullptr;
    } else{
        std::shared_ptr<Node> temp = head->prev;
        head = head->next;
        head->prev = temp;
        temp->next = head;
    }
}

template<class T>
void MyQueue<T>::printQueue() {
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


#endif //LAB7_MYQUEUE_H
