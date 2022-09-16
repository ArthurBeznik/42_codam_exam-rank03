/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/16 12:05:20 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/16 12:11:01 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

/*
	compare first char of data to first char of data_ref
	(just for testing)
*/
int	cmp(void *data, void *data_ref)
{
	if (*(char *)data == *(char *)data_ref)
		return (0);
	return (1);
}

/*
	add new node to the end of the list, with data as content
*/
void	add_to_list_end(t_list **head, void *data)
{
	t_list	*ptr = *head;
	t_list	*current;
	current = (t_list *)malloc(sizeof(t_list));
	current->data = data;
	while (ptr->next != 0)
		ptr = ptr->next;
	ptr->next = current;
	current->next = NULL;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current, *temp, *old;

	current = *begin_list;
	old = NULL;
	while (current)
	{
		if (!(cmp(data_ref, current->data)))
		{
			temp = current;
			if (!old)
				*begin_list = (*begin_list)->next;
			else
				old->next = current->next;
			current = current->next;
			free(temp);
		}
		else
		{
			old = current;
			current = current->next;
		}
	}
}

int	main(void)
{
	t_list	*head = (t_list *)malloc(sizeof(t_list));

	head->data = "XXX";
	head->next = NULL;
	add_to_list_end(&head, "tweede");
	add_to_list_end(&head, "XXX");
	add_to_list_end(&head, "derde");
	add_to_list_end(&head, "vierde");
	add_to_list_end(&head, "XXX");
	add_to_list_end(&head, "vijfde");
	add_to_list_end(&head, "XXX");
	add_to_list_end(&head, "XXX");
	add_to_list_end(&head, "XXX");
	ft_list_remove_if(&head, "tweede", cmp);
	ft_list_remove_if(&head, "XXX", cmp);
	ft_list_remove_if(&head, "vijfde", cmp);
	t_list	*ptr = head;
	while (ptr)
	{
		printf("%s\n", ptr->data);
		ptr = ptr->next;
	}
}
