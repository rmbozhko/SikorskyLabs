#include <iostream>
#include <random>

#define expect_true(arg) \
        do { \
            if(!(arg)) { \
            	std::cout << "Unexpected false at " \
            	          << __FILE__ << ", " << __LINE__ << ", " << __func__ << ": " << #arg \
            	          << std::endl; } else { std::cout << "Successful test" << std::endl; } \
        } while(false);

void randomly_init(int *array, int size);

bool check_if_n_elements_sorted(const int *array, int size, int n);

void print_array(int *array, int size);

int main(const int argc, const char** argv) {
    int size;
    int *array;
    bool result;
    int n_sorted = 5;
    int proc_status = 0;

#ifdef DEBUG
    auto test_array_size = 10;
    auto test_array = new int []{1, 2, 3, 4, 0, 2, 3, 4, 5, 10};
    expect_true(check_if_n_elements_sorted(test_array, test_array_size, n_sorted) == 1);
    delete[] test_array;
    test_array = new int []{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    expect_true(check_if_n_elements_sorted(test_array, test_array_size, n_sorted) == 0);
    delete[] test_array;
#else
    std::cout << "Input array length: ";
    std::cin >> size;
    if (size > 0) {
        array = new int[size];
        randomly_init(array, size);
        print_array(array, size);
        try {
            result = check_if_n_elements_sorted(array, size, n_sorted);
        } catch (char *err) {
            std::cerr << err << std::endl;
            return 1;
        }
        std::cout << "Randomly initialized array does" << ((result) ? " " : " not ")
                  << "contain " << n_sorted << " sorted elements." << std::endl;
    } else {
        std::cerr << "Wrong array length" << std::endl;
        proc_status = 1;
    }
    delete[] array;
#endif
    return proc_status;
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

bool check_if_n_elements_sorted(const int *array, int size, int n) {
    if (n > size || n < 0) {
        throw "Invalid value for number of sorted elements";
    }
    int temp = n;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] < array[i + 1]) {
            temp--;
            if (temp == 0) return true;
        } else {
            temp = n;
        }
    }
    return false;
}

void randomly_init(int *array, int size) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rand(1, 10);
    for (int i = 0; i < size; i++) {
        array[i] = (int) rand(rng);
    }
}
