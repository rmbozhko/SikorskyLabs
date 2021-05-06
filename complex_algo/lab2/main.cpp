#include <iostream>
#include <fstream>
#include <chrono>

int max(int* arr, int size) {
    int max_elem;
    
    if (size < 0)
        return (-1);
    max_elem = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_elem) {
            max_elem = arr[i];
        }
    }
    return (max_elem);
}

int iter_sum(int* arr, int size, int max_elem, int& iter_counter) {
    int result;
    
    result = 0;
    for (int i = 0; i < size; i++) {
        iter_counter++;
        if (arr[i] != max_elem) {
            result += arr[i];
        } else {
            break;
        }
    }
    return (result);
}

int recur_sum(int* begin, int* end, int max_elem, int& iter_counter) {
    iter_counter++;
    if (begin == end || *begin == max_elem)
        return (0);
    return *begin + recur_sum((int*)begin + 1, end, max_elem, iter_counter);
}

int*  init_arr(int arr_size) {
    int*       arr;
    
    arr = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 100;
    }
    arr[arr_size - 1] = 101;
    return (arr);
}

int main() {
    int             *arr;
    int             arr_size;
    int             iteration_num;
    std::ofstream   data_file;
    int             max_elem;

    // Initialization
    data_file.open("data_file.txt", std::ios_base::app);
    arr_size = 500;
    iteration_num = 0;
    arr = init_arr(arr_size);
    max_elem = max(arr, arr_size);

    // Iterative part
    auto t1 = std::chrono::high_resolution_clock::now();
    iter_sum(arr, arr_size, max_elem, iteration_num);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    data_file << arr_size << "," << duration << "," << iteration_num << "\n";

    // Recursive part
    iteration_num = 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    recur_sum(arr, arr + arr_size, max_elem, iteration_num);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    data_file << arr_size << "," << duration << "," << iteration_num << "\n";

    // Returning resources
    data_file.close();
    delete arr;

    return (0);
}
