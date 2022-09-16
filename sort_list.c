/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 17:18:52 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/16 12:02:42 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * Sort the list given as param using the function pointer cmp to select 
 * 	the order to apply.
 * Returns a pointer to the first element of the sorted list.
 * 
 * t_list *sort_list(t_list *lst, int (*cmp)(int, int))
 * 
 * cmp: always returns a value != 0 if a and b are in the right order, 
 * 	= 0 otherwise.
 */

int	cmp(int a, int b)
{
	return (a <= b);
}

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int	is_sorted(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		if (cmp(tmp->data, tmp->next->data) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp;
	int		tmp_data;

	while (is_sorted(lst, cmp) == 1)
	{
		tmp = lst;
		while (tmp->next != NULL)
		{
			if (cmp(tmp->data, tmp->next->data) == 0)
			{
				tmp_data = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = tmp_data;
			}
			tmp = tmp->next;
		}
	}
	return (lst);
}

void add_to_list_end(t_list **head, int data)
{
	t_list *ptr = *head;
	t_list *current;
	
	current = (t_list *)malloc(sizeof(t_list));
	current->data = data;
	while (ptr->next != 0) // get last element
		ptr = ptr->next;
	ptr->next = current;
	current->next = NULL;
}

int main(void)
{
	t_list *lst;
	t_list *head = (t_list *)malloc(sizeof(t_list));

	head->data = 1;
	head->next = NULL;

	add_to_list_end(&head, 2);
	add_to_list_end(&head, -1);
	add_to_list_end(&head, 4);
	add_to_list_end(&head, 3);

	t_list *ptr_head = head;

	printf("Initial list:\n");
	while (ptr_head->next) // loop through all elements
	{
		printf("%d\n", ptr_head->data);
		ptr_head = ptr_head->next;
	}

	lst = sort_list(head, cmp);

	t_list *ptr = lst;

	printf("\nSorted list:\n");
	while (ptr->next) // loop through all elements
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}
