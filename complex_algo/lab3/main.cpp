#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <functional>
#include <chrono>

#define MATRIX_SIZE 10
#define SUBARR_SIZE MATRIX_SIZE / 2

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

void  sort(int*** arr, std::function<void (int** arr, int size)> f) {
  for (int i = 0; i < SUBARR_SIZE; i++) {
    f(arr[i], MATRIX_SIZE - 2 * i);
  }
}

int*** subArray(int** matrix) {
  int***  arr;
  int   k;
  int   l;
  int   index;

  arr = new int**[SUBARR_SIZE];
  k = 0;
  for (int i = 0; i <= SUBARR_SIZE; i++, k++) {
    arr[k] = new int*[MATRIX_SIZE - k * 2];
    l = 0;
    index = i;
    for (int j = MATRIX_SIZE - 1 - i; index < MATRIX_SIZE - k; l++, index++) {
      arr[k][l] = &matrix[index][j];
    }
  }

  return (arr);
}

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
void selectionSort(int** arr, int size) 
{
  int min; 
  
  for (int i = 0; i < size - 1; i++) { 
    min = i; 
    for (int j = i + 1; j < size; j++) {
      if (*arr[j] < *arr[min]) {
          min = j;
      }
    }
    swap(arr[min], arr[i]); 
  } 
}

int partition(int** arr, int low, int high) {
  int   pivot;
  int   i;
  
  pivot = *arr[high];
  i = low - 1;
  for (int j = low; j <= high - 1; j++) {
      if (*arr[j] < pivot) {
          i++;
          swap(arr[i], arr[j]);
      }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quickSorting(int** arr, int low, int high) {
  int   pivot;

  if (low < high) {
    pivot = partition(arr, low, high);

    quickSorting(arr, low, pivot - 1);
    quickSorting(arr, pivot + 1, high);
  }
}

void    quickSort(int** arr, int n) {
  quickSorting(arr, 0, n - 1);
}

int main() {
  const char* filename = "data.txt";
  int**       arr;
  int***      temp;
  
  arr = readData(filename);
  std::cout << std::endl << "Initial Array\n" << std::endl;
  print(arr, MATRIX_SIZE);
  temp = subArray(arr);
  
  // SelectionSort block
  auto t1 = std::chrono::high_resolution_clock::now();
  sort(temp, selectionSort);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  std::cout << std::endl << "Sorted with Selection Sort\n" << std::endl;
  print(arr, MATRIX_SIZE);
  std::cout << "Duration: " << duration << " microseconds" << std::endl;

  // Resetting data to initial
  arr = readData(filename);
  temp = subArray(arr);
  // QuickSort block
  t1 = std::chrono::high_resolution_clock::now();
  sort(temp, quickSort);
  t2 = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  std::cout << std::endl << "Sorted with Quick Sort\n" << std::endl;
  print(arr, MATRIX_SIZE);
  std::cout << "Duration: " << duration << " microseconds" << std::endl;

  return (0);
}