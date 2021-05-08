#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <functional>

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

int main() {
  const char* filename = "data.txt";
  int**       arr;
  
  arr = readData(filename);
  std::cout << std::endl << "Initial Array\n" << std::endl;
  print(arr, MATRIX_SIZE);

  return (0);
}