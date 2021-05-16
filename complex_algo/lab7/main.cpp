#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> readData(const char* filename, const char delim, int& value) {
  std::fstream      newfile;
  std::string       temp;
  int               coins_num;
  std::vector<int>  coins_values;

  newfile.open(filename,std::ios::in);
  if (newfile.is_open()) {
    getline(newfile, temp);
    coins_num = stoi(temp);
    getline(newfile, temp);
    
    std::stringstream ss(temp);
    std::string s;
    while (std::getline(ss, s, delim)) {
      coins_values.push_back(stoi(s));
    }
    getline(newfile, temp);
    value = stoi(temp);

    newfile.close();
  }
  return coins_values;
}

int main(const int argc, const char* argv[]) {
  int value;

  value = 0;
  if (argc > 1) {
    readData(argv[1], ' ', value);
    std::cout << value << std::endl;
  } else {
    std::cerr << "No file provided" << std::endl;
  }
  
}