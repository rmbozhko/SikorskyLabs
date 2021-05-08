#include "Node.hpp"

Node::Node(int value_, Node* next_) {
  value = value_;
  next = next_;
}

Node::Node(int val) : Node(val, NULL) {
}

Node* Node::getNext() {
  return next;
}

int   Node::getValue() {
  return value;
}