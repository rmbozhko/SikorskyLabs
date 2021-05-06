#include <chrono>
#include <iostream>
#include <fstream>

/* O(nlogn)
def     div_conq(arr, row_num, start, end):
        half = end / 2;
        if start != half:
                div_conq(arr, row_num, start, half)
                div_conq(arr, row_num, half, end)
        else:
                swap(arr[row_num][end], arr[row_num + 1][start])

for (int i = 0; i < arr_size - 1; i++) {
        div_conq(arr, 0, arr_size);
}
*/

void            swap_vars(int* a, int* b) {
        int             temp;

        temp = *a;
        *a = *b;
        *b = temp;
}

size_t          swap_function(int **arr, size_t arr_size) {
        size_t          iteration_num;

        iteration_num = 0;
        for (int i = 0; i < arr_size - 1; i++) {
                for (int j = 0; j < arr_size - 1; j++) {
                        swap_vars(&arr[i][j], &arr[i + 1][j + 1]);
                        iteration_num++;
                }
        }
        return iteration_num;
}

int**           init_arr(size_t arr_size) {
        int             **arr;

        arr = new int*[arr_size];
        for (int i = 0; i < arr_size; i++) {
                arr[i] = new int[arr_size];
                for (int j = 0; j < arr_size; j++) {
                        arr[i][j] = rand() % 50;
                }
        }

        return (arr);

}

void            print_arr(int** arr, size_t arr_size) {
        std::cout << "{";
        for (size_t i = 0; i < arr_size; i++) {
                std::cout << "{ ";
                for (size_t j = 0; j < arr_size; j++) {
                        std::cout << arr[i][j] << " ";
                }
                std::cout << "}" << std::endl;
        }
        std::cout << "}" << std::endl;
}

void            print_arr(int* arr, size_t arr_size) {
        std::cout << "{ ";
        for (size_t i = 0; i < arr_size; i++) {
                std::cout << arr[i] << " ";
        }
        std::cout << "}" << std::endl;
}

int             main(const int argc, const char* argv[]) {
        int**           arr;
        size_t          arr_size;
        size_t          iteration_num;
        std::ofstream   data_file;

        data_file.open("data_file.txt", std::ios_base::app);
        std::cout << ("Enter array size(10, 50, 100, 500): ");
        std::cin >> arr_size;
        arr = init_arr(arr_size);
        std::cout << "Initial array: " << std::endl;
        print_arr(arr, arr_size);
        auto t1 = std::chrono::high_resolution_clock::now();
        iteration_num = swap_function(arr, arr_size);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        std::cout << "Modified array: " << std::endl;
        print_arr(arr, arr_size);
        data_file << arr_size << "," << duration << "," << iteration_num << "\n";
        data_file.close();
        return (0);
}
