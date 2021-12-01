//
// Created by rbozhko on 11/9/2021.
//

#ifndef LAB2_DOUBLYLINKEDLIST_H
#define LAB2_DOUBLYLINKEDLIST_H

#include "SinglyLinkedList.h"

namespace DoublyLinkedList {
    class Node : public SinglyLinkedList::Node {
    public:
        Node();
        explicit Node(int);
        Node(int c, Node *prev);
        void  erase(Node**, int);
        void  deleteList(Node**);
        Node *getPrev() const;
        void setPrev(Node *prev);

    private:
        Node* prev;
    };
}



#endif //LAB2_DOUBLYLINKEDLIST_H
