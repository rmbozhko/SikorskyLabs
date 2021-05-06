#include <iostream>

char  get_random_char() {
  return (rand() % 3 < 1) ? '0' + rand() % 9 : 'a';// + rand() % 26;
}

int		ft_isalpha(int c) {
	return ((((char)c >= 65 && (char)c <= 90)
				|| ((char)c >= 97 && (char)c <= 122))
			&& ((c < 256) && (c > 0)) ? (1) : (0));
}

namespace SinglyLinkedList {
  class Node {   
    public:
      char  val;
      Node* next;

      Node();
      void  print();
      void  printList();
      void  erase(Node**, char);
      void  swapNext();
      void  deleteList(Node**);
  };

  Node::Node() {
    this->val = get_random_char();
    this->next = NULL;
  }

  void  Node::print() {
    std::cout << this->val;
  }

  void  Node::printList() {
    Node*   temp;

    temp = this;
    while (temp != NULL) {
      temp->print();
      temp = temp->next;
      if (temp != NULL)
        std::cout << ", "; 
    }
    std::cout << std::endl;
  }

  void  Node::erase(Node** head, char c) {
    Node*   temp;
    Node*   prev;
    
    temp = *head;

    if (temp != NULL && temp->val == c) {
      *head = temp->next;
      delete temp;
      return;
    }
    
    while (temp != NULL && temp->val != c) {
      prev = temp;
      temp = temp->next; 
    }
    if (temp != NULL) {
      prev->next = temp->next;
      delete temp;
    } else {
      throw "No specified element found\n";
    }
  }

  void  Node::swapNext() {
    char   temp;

    if (this->next != NULL) {
      temp = this->val;
      this->val = this->next->val;
      this->next->val = temp;
    } else { throw "NULLPointerException: next node\n"; }
  }

  void  Node::deleteList(Node** node) {
    Node*   temp;
    Node*   next_node;

    if (node) {
      temp = *node;
      while (temp) {
        next_node = temp->next;
        delete temp;
        temp = next_node;
      }
      *node = NULL;
    }
  }
}

namespace DoublyLinkedList{
  class Node : public SinglyLinkedList::Node {
    public:
      Node* prev;
      Node();
      void  erase(Node**, char);
      void  deleteList(Node**);
  };

  Node::Node() {
    this->prev = NULL;
  }

  void  Node::erase(Node** head, char c) {
    Node*   temp;
    Node*   prev;

    temp = *head;
    if (temp != NULL && temp->val == c) {
      *head = (DoublyLinkedList::Node*)temp->next; 
      delete temp;
      return;
    }

    while (temp != NULL && temp->val != c) {
      prev = temp;
      temp = (DoublyLinkedList::Node*)temp->next;
    }

    if (temp != NULL) {
      prev->next = temp->next;
      ((DoublyLinkedList::Node*)temp->next)->prev = prev;
      delete temp;
    } else {
      throw "No specified element found\n";
    }
  }

  void  Node::deleteList(Node** node) {
    Node*   temp;
    Node*   next_node;

    if (node) {
      temp = *node;
      while (temp) {
        next_node = (DoublyLinkedList::Node*)temp->next;
        temp->prev = NULL;
        delete temp;
        temp = next_node;
      }
      *node = NULL;
    }
  }
}

void  calcDigAndChar(SinglyLinkedList::Node* head) {
  int dig_counter;
  int char_counter;

  dig_counter = 0;
  char_counter = 0;
  while (head) {
    if (ft_isalpha(head->val)) { char_counter++; }
    else { dig_counter++; }
    head = head->next;
  }
  std::cout << "Number of digits in stack: " << dig_counter << std::endl << "Number of chars in stack: " << char_counter << std::endl;
}

DoublyLinkedList::Node*   createDLList(int size) {
  DoublyLinkedList::Node* head;
  DoublyLinkedList::Node* temp;
  DoublyLinkedList::Node* prev;

  head = new DoublyLinkedList::Node();
  temp = head;
  for (int i = 0; i < size; i++) {
    prev = temp;
    temp->next = new DoublyLinkedList::Node();
    temp = (DoublyLinkedList::Node*)temp->next;
    temp->prev = prev;
  }

  return head;
}

SinglyLinkedList::Node*   createSLList(int size) {
  SinglyLinkedList::Node* head;
  SinglyLinkedList::Node* temp;

  head = new SinglyLinkedList::Node();
  temp = head;
  for (int i = 0; i < size; i++) {
    temp->next = new SinglyLinkedList::Node();
    temp = temp->next;
  }

  return head;
}

int main() {
  try {
    int size = 10;
    srand (time(NULL));
    DoublyLinkedList::Node* dllHead;
    SinglyLinkedList::Node* sllHead;
    
    // creating the lists
    std::cout << "DoublyLinkedList\n";
    dllHead = createDLList(size);
    dllHead->printList();
    std::cout << "SinglyLinkedList\n";
    sllHead = createSLList(size);
    sllHead->printList();
    
    std::cout << "Erased!\n";
    sllHead->erase(&sllHead, 'a');
    sllHead->printList();
    std::cout << "Swapped!\n";
    sllHead->swapNext();
    sllHead->printList();

    std::cout << "Erased!\n";
    dllHead->erase(&dllHead, 'a');
    dllHead->printList();

    std::cout << "Calculating num of digits and chars in stack\n";
    std::cout << "SinglyLinkedList\n";
    calcDigAndChar(sllHead);
    std::cout << "DoublyLinkedList\n";
    calcDigAndChar(dllHead);

    // deleting the lists
    sllHead->deleteList(&sllHead);
    dllHead->deleteList(&dllHead);
  } catch (char const* str) { std::cerr << str; }
}