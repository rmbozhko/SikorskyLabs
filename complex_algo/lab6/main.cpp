#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <functional>
#include "Node.hpp"

#define MATRIX_SIZE 10


int** readData(const char* filename) {
  std::ifstream infile(filename);
  std::string line;
  std::string delimiter = "\t";
  size_t pos = 0;
  std::string token;
  int i;
  int j;

  int** arr = new int*[MATRIX_SIZE];
  i = 0;
  while (std::getline(infile, line)) {
    j = 0;
    arr[i] = new int[MATRIX_SIZE];
    while ((pos = line.find(delimiter)) != std::string::npos) {
      token = line.substr(0, pos);
      arr[i][j] = stoi(token);
      line.erase(0, pos + delimiter.length());
      j++;
    }
    arr[i][j] = stoi(line);
    i++;
  }
  return arr;
}

void    print(int** arr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "{ ";
    for (int j = 0; j < size; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "}" << std::endl;
  }
}

void  print(Node** lists_arr, int size) {
  Node*   temp;

  for (int i = 0; i < size; i++) {
    std::cout << "{ ";
    temp = lists_arr[i];
    while (temp != NULL) {
      std::cout << temp->getValue() << " ";
      temp = temp->getNext();
    }
    std::cout << "}" << std::endl;
  }
}

Node*   nodeInit(int* arr, int j, int size, Node* prev_node) {
  if (j == size - 1) {
    return (arr[j] != 0) ? new Node(arr[j], j) : NULL;
  }
  return (arr[j] != 0) ? new Node(arr[j], j, nodeInit(arr, j + 1, size, prev_node)) : nodeInit(arr, j + 1, size, prev_node);
}

Node**  arrToList(int** arr, int size) {
  Node**  lists_arr;

  lists_arr = new Node*[size];
  for (int i = 0; i < size; i++) {
    lists_arr[i] = nodeInit(arr[i], 0, size, NULL);
  }
  return lists_arr;
}

void  swap(Node* a, Node* b) {
  int   temp;

  temp = a->getValue();
  a->setValue(b->getValue());
  b->setValue(temp);
}

void  selectionSort(Node* head)  {
  Node* min; 
  
  for (Node* i = head; i != NULL; i = i->getNext()) { 
    min = i;
    for (Node* j = i->getNext(); j != NULL; j = j->getNext()) {
      if (j->getValue() < min->getValue()) {
          min = j;
      }
    }
    swap(min, i); 
  }
}

void    sort(Node** arr, int size, std::function<void (Node* arr)> f) {
  for (int i = 0; i < size; i++) {
    f(arr[i]);
  }
}

int**   listToArr(Node** lists_arr, int size) {
  int**   arr;
  Node*   temp;

  arr = new int*[size];
  for (int i = 0; i < size; i++) {
    temp = lists_arr[i];
    arr[i] = new int[size];
    for (int j = 0; j < size; j++) {
      if (temp != NULL && temp->getPosition() == j) {
        arr[i][j] = temp->getValue();
        temp = temp->getNext();
      } else {
        arr[i][j] = 0;
      }
    }
  }
  return arr;
}

void    deleteArr(int** arr, int size) {
  for (int i = 0; i < size; i++) {
    delete arr[i];
  }
  delete arr;
}

int main() {
  const char* filename = "data.txt";
  int**       arr;
  Node**      lists_arr;
  
  arr = readData(filename);
  std::cout << std::endl << "Initial Array\n" << std::endl;
  print(arr, MATRIX_SIZE);
  
  std::cout << std::endl << "Initial List\n" << std::endl;
  lists_arr = arrToList(arr, MATRIX_SIZE);
  print(lists_arr, MATRIX_SIZE);
  
  std::cout << std::endl << "Sorted List\n" << std::endl;
  sort(lists_arr, MATRIX_SIZE, selectionSort);
  print(lists_arr, MATRIX_SIZE);

  deleteArr(arr, MATRIX_SIZE);
  std::cout << std::endl << "Sorted Array\n" << std::endl;
  arr = listToArr(lists_arr, MATRIX_SIZE);
  print(arr, MATRIX_SIZE);
  return (0);
}