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

	if (lst)
		return (-1);

	lst_len = 0;
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
}

t_personal_data*		ft_lst_elem_new() {
	t_personal_data*	elem;
	char*				temp;

	elem = (t_personal_data*)malloc(sizeof(t_personal_data*));
	printf("Введіть ім'я: ");
	scanf("%s", temp);
	memcpy(elem->name, temp, strlen(temp));
	printf("Введіть призвіще: ");
	scanf("%s", temp);
	memcpy(elem->surname, temp, strlen(temp));
	printf("Введіть по-батькові: ");
	scanf("%s", temp);
	memcpy(elem->father_name, temp, strlen(temp));
	printf("Введіть назву міста: ");
	scanf("%s", temp);
	memcpy(elem->city_name, temp, strlen(temp));
	printf("Введіть назву вулиці: ");
	scanf("%s", temp);
	memcpy(elem->street_name, temp, strlen(temp));
	printf("Введіть номер будинку: ");
	scanf("%ld", &elem->house_number);
	printf("Введіть номер квартири: ");
	scanf("%ld", &elem->appartment_number);
	printf("Введіть номер телефону: ");
	scanf("%s", temp);
	memcpy(elem->phone_number, temp, strlen(temp));

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

void		ft_lst_append(t_personal_data* elem, t_personal_data* new_elem) {
	elem = ft_lst_to_tail(elem);
	elem->next = new_elem;
	elem = elem->next;
}

t_personal_data*	ft_find_elem(t_personal_data* elem) {
	elem = ft_lst_to_head(elem);

}