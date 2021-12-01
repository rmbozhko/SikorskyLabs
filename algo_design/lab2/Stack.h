//
// Created by rbozhko on 11/9/2021.
//

#ifndef LAB2_STACK_H
#define LAB2_STACK_H

#include <iostream>
#include <utility>
#include "DoublyLinkedList.h"

class Stack {
public:
    Stack() = default;
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    ~Stack();

    void push(int value);
    void pop();
    void print() const;
    bool empty() const { return top == nullptr; }

    DoublyLinkedList::Node *getTop() const;

private:
    DoublyLinkedList::Node* top = nullptr;
};

#endif //LAB2_STACK_H
