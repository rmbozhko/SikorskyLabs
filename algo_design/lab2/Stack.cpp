//
// Created by rbozhko on 11/9/2021.
//

#include "Stack.h"

Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}

void Stack::push(int value) {
    top = new DoublyLinkedList::Node(value, top);
    auto old = top->getPrev();
    if (old != nullptr) {
        old->setNext(top);
    }
}

void Stack::pop() {
    if (empty()) {
        std::cerr << "No pop operation allowed on empty stack" << std::endl;
    } else {
        delete std::exchange(top, top->getPrev());
    }
}

void Stack::print() const {
    for (auto it = top; it; it = it->getPrev()) {
        std::cout << it->getValue() << ' ';
    }
    std::cout << '\n';
}

DoublyLinkedList::Node *Stack::getTop() const {
    return top;
}