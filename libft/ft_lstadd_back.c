/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:21:56 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 11:22:13 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adds the element ’new’ at the end of the list.
**	#1. The address of a pointer to the first link of a list.
**	#2. The address of a pointer to the element to be added to the list.
*/

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

/*
**	1) This function is used to add the list at the last element of a linked
**	list. This is acomplished by itterating through the list and find last node
**	whicht he "next" value is null and then we just do the address assignment.
**
**	2) In case that list is null parameter the "new" pointer address is assigned
**	to that list.
*/