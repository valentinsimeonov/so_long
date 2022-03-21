/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:45:59 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 15:23:54 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Counting the Lines (Elements) in Map (Linked List) */
int	list_element_count(t_list **lines)
{
	int		lines_count;
	t_list	*temp;

	temp = *lines;
	lines_count = 1;
	while (temp->next != NULL)
	{
		lines_count++;
		temp = temp->next;
	}
	return (lines_count);
}

/* Creating the Linked List, each Element has One Line from the Map */
t_list	*list_init(int fd_map)
{
	char	*temp_line;
	int		list_count;
	t_list	*lines;

	list_count = 0;
	temp_line = get_next_line(fd_map);
	while (temp_line)
	{
		ft_lstadd_back(&lines, create_element(temp_line));
		temp_line = get_next_line(fd_map);
		list_count++;
	}
	return (lines);
}

/* Adding an Element to the Linked List */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}

/* Creating the Element for the Linked List */
t_list	*create_element(char *character)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->line = character;
	element->next = NULL;
	return (element);
}

/* Freeing the Allocated Memory for Linked List */
void	free_list(t_list **lines)
{
	t_list		*tmp1;
	t_list		*tmp2;

	tmp1 = *lines;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
