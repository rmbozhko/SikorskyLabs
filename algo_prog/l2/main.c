#include "list.h"

int 	menu(char** men, size_t len) {
	int 	menu_id; // зберігає ввід користувача з консолі
	for (int i = 0; i < len; ++i) {
		printf("%s\n", men[i]);
	}
	printf("Введіть, будь ласка, число:\n");
	scanf("%d", &menu_id);
  // Перевіряємо отриманий індекс на правильність
	if (menu_id >= 1 && menu_id <= len) {
		return (menu_id);
	} else {
		return (-1);
	}
}

int		show_menu() {
	// містить лістинг меню
	char**	men = {"1. New", "2. Find", "3. To Head", "4. To Tail", "5. Next", "6. Previous",
					"7. Show", "8. List", "9. Insert", "10. Delete", "11. Count", "12. Exit"};

	bool 				exit_selected = false; // флажок для перевірки вводу Exit
	t_personal_data*	elem = NULL;
	while (true) {
    int 	menu_id = menu(men, 12); // містить обраний номер меню
	  // У випадку, якщо переданий індекс не відповідає меню, завершимо програму з кодом помилки
    if (menu_id == -1) {
		  return (-1);
	  }
		switch (menu_id) {
			case 1:
				ft_lst_append(elem, ft_lst_elem_new());
				break;
			case 2:
				elem = ft_find_elem(elem);
				break;
			case 3:
				elem = ft_lst_to_head(elem);
				break;
			case 4:
				elem = ft_lst_to_tail(elem);
				break;
			case 5:
				elem = ft_lstnext(elem);
				break;
			case 6:
				elem = ft_lstprev(elem);
				break;
			case 7:
				ft_lst_print(elem, 1);
				break;
			case 8:
				ft_lst_print(elem, ft_lstlen(elem));
				break;
			case 9:
				ft_insert_element(elem);
				break;
			case 10:
				ft_lst_delete(elem);
				break;
			case 11:
				printf("Довжина списку: %d\n", ft_lstlen(elem));
				break;
			case 12:
				exit_selected = true;
				break;
			default:
				printf("No element selected\n");
		}
		if (exit_selected) {
			break ;
	  }
  }
  return (0);
}

int main(int argc, char const *argv[])
{
	return (show_menu());
}