//
// Created by rbozhko on 11/9/2021.
//

#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::Node::Node() {
    this->prev = nullptr;
}

DoublyLinkedList::Node::Node(int c) : SinglyLinkedList::Node(c) {
    this->prev = nullptr;
}

DoublyLinkedList::Node::Node(int c, Node* prev) : SinglyLinkedList::Node(c) {
    this->prev = prev;
}
/*
Видаляємо елемент стеку з певним значенням.
*/
void  DoublyLinkedList::Node::erase(DoublyLinkedList::Node** head, int c) {
    Node*   temp;
    Node*   prev;

    temp = *head;
    if (temp != nullptr && temp->getValue() == c) {
        *head = (DoublyLinkedList::Node*)temp->getNext();
        delete temp;
        return;
    }

    while (temp != nullptr && temp->getValue() != c) {
        prev = temp;
        temp = (DoublyLinkedList::Node*)temp->getNext();
    }

    if (temp != nullptr) {
        prev->setNext(temp->getNext());
        ((DoublyLinkedList::Node*)temp->getNext())->prev = prev;
        delete temp;
    } else {
        std::cerr << "No specified element found\n";
    }
}

/*
Видаляємо створений двузв'язний список.
*/
void  DoublyLinkedList::Node::deleteList(DoublyLinkedList::Node** node) {
    Node*   temp;
    Node*   next_node;

    if (node) {
        temp = *node;
        while (temp) {
            next_node = (DoublyLinkedList::Node*)temp->getNext();
            temp->prev = nullptr;
            delete temp;
            temp = next_node;
        }
        *node = nullptr;
    }
}

DoublyLinkedList::Node *DoublyLinkedList::Node::getPrev() const {
    return prev;
}

void DoublyLinkedList::Node::setPrev(DoublyLinkedList::Node *prev) {
    Node::prev = prev;
}
