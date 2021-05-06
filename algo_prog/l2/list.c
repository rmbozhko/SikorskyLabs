#include "list.h"

t_personal_data*		ft_lstnext(t_personal_data* lst) {
	if (!lst)
		return (NULL);
	return (lst->next);
}

t_personal_data*		ft_lstprev(t_personal_data* lst) {
	if (!lst)
		return (NULL);
	return (lst->prev);
}

t_personal_data*		ft_lst_to_head(t_personal_data* lst) {
	if (!lst)
		return (NULL);
	while (lst->prev) {
		lst = lst->prev;
	}
	return (lst);
}

t_personal_data*		ft_lst_to_tail(t_personal_data* lst) {
	if (!lst)
		return (NULL);
	while (lst->next) {
		lst = lst->next;
	}
	return (lst);
}

int			ft_lstlen(t_personal_data* lst) {
	t_personal_data*	head;
	int 				lst_len;

	if (!lst)
		return (-1);

	lst_len = 1;
	head = ft_lst_to_head(lst);
  
  while (head->next) {
		lst_len++;
		head = head->next;
	}
	return (lst_len);
}

void		ft_lst_print(t_personal_data* elem, int len) {
	printf("%10s|%10s|%15s|%15s|%20s|%10s|%10s|%10s|%6s\n",
			"Призвіще", "Ім'я", "По-батькові", "Місто", "Вулиця", "Номер будинку", "Номер квартири", "Номер телефону", "Курсор");
	t_personal_data* temp = elem;
	elem = ft_lst_to_head(elem);
	elem = (len == 1) ? temp : elem; //Повертаємося на переданий елемент списку, якщо хочемо вивести тільки його
	while (len > 0) {
		printf("%10s|%10s|%15s|%15s|%20s|%3ld|%3ld|%10s|%6s\n", 
			elem->surname, elem->name, elem->father_name, elem->city_name, elem->street_name,
			elem->house_number, elem->appartment_number, elem->phone_number, (temp == elem) ? "<<--" : "");
		elem = elem->next;
		len--;
	}
}

void		ft_lst_delete(t_personal_data* elem) {
	t_personal_data*	prev;
	t_personal_data*	next;

	prev = NULL;
	next = NULL;
	if (elem->prev)
		prev = elem->prev;
	if (elem->next)
		next = elem->next;
	prev->next = next;
	next->prev = prev;

	free(elem->surname);
	free(elem->name);
	free(elem->father_name);
	free(elem->city_name);
	free(elem->street_name);
	free(elem->phone_number);
	free(elem);
  printf("Елемент списку видалено успішно");
}

t_personal_data*		ft_lst_elem_new() {
	t_personal_data*	elem = NULL;
	char				temp[50];

	elem = (t_personal_data*)malloc(sizeof(t_personal_data*));
	printf("Введіть ім'я: ");
	scanf("%s", temp);
  elem->name = (char*)malloc(sizeof(char) * 50);
  bzero(elem->name, 50);
	memcpy(elem->name, temp, strlen(temp));
	printf("Введіть призвіще: ");
	scanf("%s", temp);
  elem->surname = (char*)malloc(sizeof(char) * 50);
	memcpy(elem->surname, temp, strlen(temp));
	printf("Введіть по-батькові: ");
	scanf("%s", temp);
  elem->father_name = (char*)malloc(sizeof(char) * 50);
	memcpy(elem->father_name, temp, strlen(temp));
	printf("Введіть назву міста: ");
	scanf("%s", temp);
  elem->city_name = (char*)malloc(sizeof(char) * 50);
	memcpy(elem->city_name, temp, strlen(temp));
	printf("Введіть назву вулиці: ");
	scanf("%s", temp);
  elem->street_name = (char*)malloc(sizeof(char) * 50);
	memcpy(elem->street_name, temp, strlen(temp));
	printf("Введіть номер будинку: ");
	scanf("%ld", &elem->house_number);
	printf("Введіть номер квартири: ");
	scanf("%ld", &elem->appartment_number);
	printf("Введіть номер телефону: ");
	scanf("%s", temp);
  elem->phone_number = (char*)malloc(sizeof(char) * 50);
	memcpy(elem->phone_number, temp, strlen(temp));
  elem->next = NULL;
  elem->prev = NULL;
  
	return (elem);
}

t_personal_data*		ft_lst_insert(t_personal_data* head, t_personal_data* new_elem) {
	t_personal_data*		temp;

	temp = head->next;

	head->next = new_elem;
	new_elem->prev = head;
	new_elem->next = temp;
	temp->prev = new_elem;

	return new_elem;
}

t_personal_data*		ft_insert_element(t_personal_data* lst) {
	t_personal_data*		new_elem;
	int 					menu_id;
  
	new_elem = ft_lst_elem_new();
	char* men[] = {"1. Вставити новий елемент до поточного", "2. Вставити елемент після поточного"};
	menu_id = menu(men, 2);
	if (menu_id != -1 && new_elem) {
		if (menu_id == 2) {
			ft_lst_insert(lst, new_elem);
		} else {
			lst = lst->prev;
			if (lst)
				ft_lst_insert(lst, new_elem);
		}
	}
	return NULL;
}

t_personal_data*		ft_lst_append(t_personal_data* elem, t_personal_data* new_elem) {
	elem = ft_lst_to_tail(elem);
  if (elem) {
    elem->next = new_elem;
    elem = elem->next;
  } else {
    elem = new_elem;
  }
  return elem;
}

t_personal_data*    ft_cmp_name(t_personal_data* elem, char* val) {
  t_personal_data*  temp;

  temp = elem;
  while (temp) {
    if (!strcmp(temp->name, val))
      return (temp);
    temp = temp->next;
  }
  return (NULL);  
}

t_personal_data*    ft_cmp_house_number(t_personal_data* elem, size_t val) {
  t_personal_data*  temp;

  temp = elem;
  while (temp) {
    if (temp->house_number == val)
      return (temp);
    temp = temp->next;
  }
  return (NULL);  
}

t_personal_data*	ft_find_elem(t_personal_data* elem) {
	int       menu_id;
  char      temp[50];
  size_t    input_var;
  
  elem = ft_lst_to_head(elem);
  menu_id = menu({"1. Пошук по імені", "2. Пошук по призвіщу", "3. Пошук по по-батькові", "4. Пошук по назві міста", "5. Пошук по назві вулиці", "6. Пошук по номеру телефону", "7. Пошук по номеру будинку", "8. Пошук по номеру квартири"}, 8);

  if (menu_id != -1 && elem) {
    printf("Введіть значення для пошуку: ");
    if (menu_id >= 1 && menu_id <= 6) {
      scanf("%s", temp);
      elem = ft_str_cmp_funcs[menu_id](elem, temp);
    } else {
      menu_id -= 7;
      scanf("%ld", input_var);
      elem = ft_int_cmp_funcs[menu_id](elem, input_var);
    }
    if (elem) {
      printf("Пошук завершився успішно\n");
      return elem;
    }
  }
  printf("Пошук завершився безрезультатно\n");
  return (NULL);
}