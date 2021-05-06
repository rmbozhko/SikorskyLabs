#include <iostream>

using namespace std;

void  print_arr(int* arr, int size, ostream& os);

int*    init_arr(int size) {
  int*    arr;

  arr = new int[size];
  for(int i = 0; i < size; i++) {
    arr[i] = (rand() % 100) + 1;
  }

  return (arr);
}

void	copy(int* target, int* source, int& i, int size) {
	for (int j = 0; j < size; ++j, ++i) {
		target[i] = source[j];
	}
}

int*	append(int* arr, int index, int elem) {
	int*	temp;
	int 	i;

	temp = new int[index + 1];
	for (i = 0; i < index; ++i) {
		temp[i] = arr[i];
	}
	temp[i] = elem;

	return (temp);
}

int*	erase(int* arr, int& size, int index) {
	int*	strg;
	int 	i;

	i = 0;
	strg = new int[size - 1];
	copy(strg, arr, i, index);
	copy(strg, arr + index + 1, i, size - index - 1);
	size--;
	delete[] arr;

	return (strg);
}

int*	insert(int* arr, int& size, int index, int elem) {
	int* 	temp = append(arr, index, elem);
	int*	strg;
	int 	i;

	i = 0;
	strg = new int[size + 1];
	copy(strg, temp, i, index + 1);
	copy(strg, arr + index, i, size - index);
	size++;
	delete[] arr;
	delete[] temp;

	return (strg);
}

int	*removeEven(int* arr, int& size) {
	for (int i = 0; i < size; ) {
		if (arr[i] % 2 == 0) {
			arr = erase(arr, size, i);
		} else { ++i; }
	}
  
  return arr;
}

int *removeDuplicates(int* arr, int& size) {
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] == arr[i]) {
				arr = erase(arr, size, j);
			}
		}
	}
  return arr;
}
/*
void	swap(int* a, int* b) {
	int 	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	reverse(int* arr, int size, int shift) {
	if (shift > 0) {
		while (shift != 0) {
			for (int i = 0; i < size - 1; ++i) {

			}
			shift--;
		}
	} else if (shift < 0) {
		while (shift != 0) {
			for (int i = 0; i < size - 1; ++i) {
		
			}
			shift++;
		}
	} else {
		std::cerr << "Invalid shift value" << std::endl; 
	}
}
*/

void  print_arr(int* arr, int size, ostream& os) {
  os << "{ ";
  for(int i = 0; i < size; i++) {
    os << arr[i] << " ";
  }
  os << "}" << endl;
}

int main(int argc, char const *argv[])
{
	int*  arr;
  int   size;

  size = 10;
  arr = init_arr(size);
  //print_arr(arr, size, cout);
  arr = insert(arr, size, 3, 22);
  print_arr(arr, size, cout);
  //arr = removeEven(arr, size);
  //arr = erase(arr, size, 3);
  //arr = removeDuplicates(arr, size);
  print_arr(arr, size, cout);
	return 0;
}