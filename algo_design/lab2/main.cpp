#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "main.h"
#include "Stack.h"

using namespace DoublyLinkedList;

int  get_random_int() {
    return rand() % 9;
}

/*
  Створює двузв'язний список.
*/
Node*   CreateDLList(int size) {
    Node* head;
    Node* temp;
    Node* prev;

    head = new Node();
    temp = head;
    for (int i = 0; i < size; i++) {
        prev = temp;
        temp->setNext(new Node());
        temp = (Node*)temp->getNext();
        temp->setPrev(prev);
    }

    return head;
}

/*
  Створює стек.
*/
Stack*  CreateStack(int size) {
    auto* stack = new Stack();

    while (size-- > 0) {
        stack->push(get_random_int());
    }

    return stack;
}

void    PrintStackMinAndMaxValues(Stack* stack) {
    DoublyLinkedList::Node* temp;
    int minValue;
    int maxValue;
    int index = 0;
    int minIndex;
    int maxIndex;

    temp = stack->getTop();
    minValue = temp->getValue();
    maxValue = temp->getValue();
    while (temp != nullptr) {
        if (temp->getValue() > maxValue) {
            maxValue = temp->getValue();
            maxIndex = index;
        }
        if (temp->getValue() < minValue) {
            minValue = temp->getValue();
            minIndex = index;
        }
        temp = temp->getPrev();
        index++;
    }
    std::cout << "Значення максимального елементу: " << maxValue << " та його індекс: " << maxIndex << std::endl;
    std::cout << "Значення мінімального елементу: " << minValue << " та його індекс: " << minIndex << std::endl;
}

int main() {
    int size = 10;
    srand (time(nullptr));
    Node* dllHead;
    Stack* stack;

    // creating the list
    std::cout << "Вивід списку значень\n";
    dllHead = CreateDLList(size);
    dllHead->printList();

    std::cout << "Видалили елемент з значенням 0\n";
    dllHead->erase(&dllHead, 0);
    dllHead->printList();

    std::cout << "Вивід значень стеку\n";
    stack = CreateStack(size);
    stack->print();

    PrintStackMinAndMaxValues(stack);

    // deleting the list
    dllHead->deleteList(&dllHead);
}