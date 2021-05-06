#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#define ARR_SIZE 10
#define PHI 1.6180339887498948482045868

int** readData(const char* filename) {
  std::ifstream infile(filename);
  std::string line;
  std::string delimiter = "\t";
  size_t pos = 0;
  std::string token;
  int i;
  int j;

  int** arr = new int*[ARR_SIZE];
  i = 0;
  while (std::getline(infile, line)) {
    j = 0;
    arr[i] = new int[ARR_SIZE];
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

void    print(int* arr, int size) {
  
  std::cout << "{ ";
  for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
  }
  std::cout << "}" << std::endl;
}

int compare(const void* x1, const void* x2) {
  return (*(int*)x1 - *(int*)x2);
}

int linearSearchWithBarrier(int* x, int size, int val, int& steps) {
  int i;
  int temp;

  i = 0;
  temp = x[size - 1];
  x[size - 1] = val;
  while (x[i] != val) {
    i++;
    steps++;
  }
  x[size - 1] = temp;
  return (((i < size - 1) || val == temp) ? i : -1);
}

int goldenSectionSearch(int* x, int val, int low, int high, int& steps) {
  int x1;
  int x2;

  x1 = high - (high - low) / PHI;
  x2 = low + (high - low) / PHI;
  if (x1 < x2) {
    if (x[x1] == val)
      return x1;
    if (x[x2] == val)
      return x2;
    steps++;  
    if (x[x1] > val)
      return goldenSectionSearch(x, val, low, x1, steps);
    if (x[x2] < val)
      return goldenSectionSearch(x, val, x2, high, steps);
    if (x[x1] < val && x[x2] > val)
      return goldenSectionSearch(x, val, x1, x2, steps);
  }
  return -1;
}

int   main() {
  const char* filename = "data.txt";
  int   steps;
  int   val;
  int*  arr;
  
  arr = readData(filename)[0];
  steps = 0;
  val = 9; // val to find
  print(arr, ARR_SIZE);

  std::cout << "Result of search with barrier: ";
  std::cout << linearSearchWithBarrier(arr, ARR_SIZE, val, steps) << std::endl;
  std::cout << "Steps: " << steps << std::endl;
  qsort(arr, ARR_SIZE, sizeof(int), compare);
  print(arr, ARR_SIZE);
  steps = 0;
  std::cout << "Result of golden-section search: ";
  std::cout << goldenSectionSearch(arr, val, 0, ARR_SIZE, steps) << std::endl;
  std::cout << "Steps: " << steps << std::endl;
}