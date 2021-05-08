#include "Node.hpp"

Node::Node(int value_, int position_, Node* next_) {
  value = value_;
  next = next_;
  position = position_;
}

Node::Node(int val, int pos) : Node(val, pos, NULL) {}

Node* Node::getNext() {
  return next;
}

int   Node::getValue() {
  return value;
}

void  Node::setValue(int value_) {
  value = value_;
}

int   Node::getPosition() {
  return position;
}
