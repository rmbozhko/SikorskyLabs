//
// Created by rbozhko on 11/9/2021.
//

#include <ctime>
#include <iostream>
#include "SinglyLinkedList.h"
#include "main.h"


SinglyLinkedList::Node::Node() {
    this->value = get_random_int();
    this->next = nullptr;
}

SinglyLinkedList::Node::Node(int c) {
    this->value = c;
    this->next = nullptr;
}

/*
Виводимо значення однієї ноди списку.
*/
void  SinglyLinkedList::Node::print() const {
    std::cout << this->value;
}

/*
Виводимо вміст списку.
*/
void  SinglyLinkedList::Node::printList() {
    Node*   temp;

    temp = this;
    while (temp != nullptr) {
        temp->print();
        temp = temp->next;
        if (temp != nullptr)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int SinglyLinkedList::Node::getValue() const {
    return value;
}

void SinglyLinkedList::Node::setValue(int value) {
    Node::value = value;
}

SinglyLinkedList::Node *SinglyLinkedList::Node::getNext() const {
    return next;
}

void SinglyLinkedList::Node::setNext(SinglyLinkedList::Node *next) {
    Node::next = next;
}
