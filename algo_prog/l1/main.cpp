/*
  Лабораторна робота №1
  В завданні необхідно виводити меню і отримувати дані від користувача до тих пір, поки він не надішле 5.
  Якщо він надіслав 5, то необхідно успішно завершити програму.

  g++ main.cpp -o main

*/

#include <iostream>

int 	menu(char** men) {
	int 	menu_id; // зберігає ввід користувача з консолі
	for (int i = 0; i < 5; ++i) {
		std::cout << men[i] << std::endl;
	}
	std::cout << "Введіть, будь ласка, число:" << std::endl;
	std::cin >> menu_id;
  // Перевіряємо отриманий індекс на правильність
	if (menu_id >= 1 && menu_id <= 5) {
		return (menu_id);
	} else {
		return (-1);
	}
}

void	insertFun(int i) {
	printf("Key %d pressed, function INSERT selected\n", i);
}

void	findFun(int i) {
	printf("Key %d pressed, function FIND selected\n", i);
}

void	deleteFun(int i) {
	printf("Key %d pressed, function DELETE selected\n", i);
}

void	editFun(int i) {
	printf("Key %d pressed, function EDIT selected\n", i);
}

void 	exitFun(int i) {
	printf("Key %d pressed, function EXIT selected\n", i);
}

bool	exitVerified() {
	printf("Ви впевнені, що хочете покинути програму?\n");
	char	men[][] = {"1. Yes", "2. No"};
	int 	menu_id = menu(men);

	return ((menu_id == 1) ? true : false);
}

int main(int argc, char const *argv[]) {
	char	men[][] = {"1. Insert", "2. Find", "3. Delete", "4. Edit", "5. Exit"}; // містить лістинг меню
  	// Записуємо назви варіантів до меню в купу
  	
  	//bool 	exit_selected = false; // флажок для перевірки вводу 5
	
	while (true) {
    	int 	menu_id = menu(men); // містить обраний номер меню
	  	// У випадку, якщо переданий індекс не відповідає меню, завершимо програму з кодом помилки
    	if (menu_id == -1) {
			return (-1);
	  	}
		switch (menu_id) {
			case 1:
				insertFun(menu_id);
				break;
			case 2:
				findFun(menu_id);
				break;
			case 3:
				deleteFun(menu_id);
				break;
			case 4:
				editFun(menu_id);
				break;
			case 5:
				exitFun(menu_id);
				if (exitVerified()) {
					return (0);
					/*exit_selected = true;
					break;	*/
				}
			default:
				std::cout << "No element selected" << std::endl;
		}
		/*if (exit_selected) {
			break ;*/
	}
	return (0);
}