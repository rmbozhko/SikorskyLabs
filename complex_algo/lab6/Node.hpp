#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

class Node
{
  private:
    int   value;
    Node* next;

  public:
    Node(int);
    Node(int, Node*);
    int   getValue();
    Node* getNext();
};

#endif