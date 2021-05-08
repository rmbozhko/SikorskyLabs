#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

class Node
{
  private:
    int   value;
    int   position;
    Node* next;

  public:
    Node(int, int);
    Node(int, int, Node*);
    int   getValue();
    void  setValue(int);
    int   getPosition();
    Node* getNext();
};

#endif