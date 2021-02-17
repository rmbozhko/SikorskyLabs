/*
  Лабораторна робота №1
  В завданні необхідно виводити меню і отримувати дані від користувача до тих пір, поки він не надішле 5. Якщо він надіслав 5, то необхідно успішно завершити програму.

  gcc main.c -o main

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int 	menu(char** men) {
	int 	menu_id; // зберігає ввід користувача з консолі
	for (int i = 0; i < 5; ++i) {
		printf("%s\n", men[i]);
	}
	printf("Введіть, будь ласка, число:\n");
	scanf("%d", &menu_id);
  // Перевіряємо отриманий індекс на правильність
	if (menu_id >= 1 && menu_id <= 5) {
		return (menu_id);
	} else {
		return (-1);
	}
}

void insertFun(int i) {
	printf("Key %d pressed, function INSERT selected\n", i);
}

void findFun(int i) {
	printf("Key %d pressed, function FIND selected\n", i);
}

void deleteFun(int i) {
	printf("Key %d pressed, function DELETE selected\n", i);
}

void editFun(int i) {
	printf("Key %d pressed, function EDIT selected\n", i);
}

void exitFun(int i) {
	printf("Key %d pressed, function EXIT selected\n", i);
}

int main(int argc, char const *argv[])
{
	char**	men = (char**)malloc(sizeof(char) * 10 * 5); // містить лістинг меню
  // Записуємо назви варіантів до меню в купу
  men[0] = "1. Insert";
  men[1] = "2. Find";
  men[2] = "3. Delete";
  men[3] = "4. Edit";
  men[4] = "5. Exit";
	bool 	exit_selected = false; // флажок для перевірки вводу 5
	
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
				exit_selected = true;
				break;
			default:
				printf("No element selected\n");
		}
		if (exit_selected) {
			break ;
	  }
  }
  // Звільюємо пам'ять виділену на початку роботи програми.
  free(men);
  return (0);
}