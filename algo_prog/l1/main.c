#include <stdio.h>
#include <stdlib.h>

int 	menu(char** men) {
	int 	id;

	for (int i = 0; men[i] != "\0"; ++i) {
		printf("%s\n", men[i]);
	}
	printf("Введіть, будь ласка, число:\n");
	scanf(&i, id);
	if (id >= 1 && id <= 5) {
		return (id);
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
	char**	men = ["1. Insert", "2. Find", "3. Delete", "4. Edit", "5. Exit"];
	bool 	exit_flag = false;
	int 	id = menu(men);
	if (id == -1) {
		 return (-1);
	}
	while (true) {
		switch (id) {
			case 1:
				insertFun(id);
				break;
			case 2:
				findFun(id);
				break;
			case 3:
				deleteFun(id);
				break;
			case 4:
				editFun(id);
				break;
			case 5:
				exitFun(id);
				exit_flag = true;
				break;
			default:
				printf("No element selected\n");
		}
		if (exit_flag) {
			break ;
		}
	}
	return 0;
}