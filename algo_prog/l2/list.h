#ifndef L2_LIST_H
#define L2_LIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef	struct 			s_personal_data
{
	char*				surname;
	char*				name;
	char*				father_name;
	char*				city_name;
	char*				street_name;
	size_t				house_number;
	size_t				appartment_number;
	char*				phone_number;	
	struct s_personal_data*	next;
	struct s_personal_data*	prev;
} 						t_personal_data;

int 					menu(char* men[], size_t len);
t_personal_data*		ft_lstnext(t_personal_data* lst);
t_personal_data*		ft_lstprev(t_personal_data* lst);
t_personal_data*		ft_lst_to_head(t_personal_data* lst);
t_personal_data*		ft_lst_to_tail(t_personal_data* lst);
int						ft_lstlen(t_personal_data* lst);
void					ft_lst_print(t_personal_data* elem, int len);
void					ft_lst_delete(t_personal_data* elem);
t_personal_data*			ft_lst_elem_new();
t_personal_data*		ft_lst_insert(t_personal_data* head, t_personal_data* new_elem);
t_personal_data*		ft_insert_element(t_personal_data* lst);
void					ft_lst_append(t_personal_data* elem, t_personal_data* new_elem);
t_personal_data*		ft_find_elem(t_personal_data* elem);

#endif