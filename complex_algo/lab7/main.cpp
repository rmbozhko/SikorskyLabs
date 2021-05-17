#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

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

std::vector<int>  findValueRepresentation(std::vector<int> coins, int value) {
  std::vector<int>    repr;
  int                 coin;

  for(std::vector<int>::size_type i = 0; i != coins.size();) {
    coin = coins[i];
    if (value >= coin) {
      value -= coin;
      repr.push_back(coin);
    } else {
      i++;
    }
  }

  return (repr);
}

bool sort_cmp (int i, int j) { return (i > j); }

int main(const int argc, const char* argv[]) {
  int               value;
  std::vector<int>  coins;
  std::vector<int>  value_repr;

  value = 0;
  if (argc > 1) {
    coins = readData(argv[1], ' ', value);
    if (coins.empty()) {
      std::cerr << "Invalid data passed" << std::endl;
      return (-1);
    }
    // Displaying read data
    std::cout << "Task: represent " << value << " with minimal number of elements from { ";
    std::copy(coins.begin(), coins.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << "}" << std::endl;

    // Find representation
    std::sort(coins.begin(), coins.end(), sort_cmp);
    value_repr = findValueRepresentation(coins, value);

    // Displaying the representation result
    std::cout << "Value representation: " << std::endl;
    std::copy(value_repr.begin(), value_repr.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  } else {
    std::cerr << "No file provided" << std::endl;
    return (-1);
  }
  return (0);
}