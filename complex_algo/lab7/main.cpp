#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

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
    std::string       s;
    int               elem;
    while (std::getline(ss, s, delim)) {
      elem = stoi(s);
      if (elem > 0 && elem < 1000000) {
        coins_values.push_back(stoi(s));
      } else {
        return {};
      }
    }
    getline(newfile, temp);
    value = stoi(temp);
    newfile.close();
    
    if ((coins_num > 0 && coins_num <= 100 && coins_num == coins_values.size()) &&
      (value > 0 && value < 5000000)) {
        return coins_values;
      }
  }
  return {};
}

int main(const int argc, const char* argv[]) {
  int               value;
  std::vector<int>  coins;

  value = 0;
  if (argc > 1) {
    coins = readData(argv[1], ' ', value);
    if (coins.empty()) {
      std::cerr << "Invalid data passed" << std::endl;
      return (-1);
    }
    std::cout << "Task: represent " << value << " with minimal number of elements from { ";
    std::copy(coins.begin(), coins.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << "}" << std::endl;
  } else {
    std::cerr << "No file provided" << std::endl;
    return (-1);
  }
  return (0);
}