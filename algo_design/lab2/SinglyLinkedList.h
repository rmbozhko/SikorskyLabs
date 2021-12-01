//
// Created by rbozhko on 11/9/2021.
//

#ifndef LAB2_SINGLYLINKEDLIST_H
#define LAB2_SINGLYLINKEDLIST_H


namespace SinglyLinkedList {
    class Node {
    public:
        Node();
        explicit Node(int);
        int getValue() const;
        void setValue(int value);
        Node *getNext() const;
        void setNext(Node *next);
        void  print() const;
        void  printList();

    private:
        int  value;
        Node* next;
    };
}


#endif //LAB2_SINGLYLINKEDLIST_H
