#ifndef NODE_HPP
#define NODE_HPP

class Node
{
  private:
    int   value;
    Node* next;

  public:
    Node(int);
    Node(int, Node*);
    ~Node();
    int   getValue();
    Node* getNext();
};

#ifndef