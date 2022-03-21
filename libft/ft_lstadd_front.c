/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:20:42 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 11:20:44 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Adds the element ’new’ at the beginning of the list.
**	#1. The address of a pointer to the first link of a list.
**	#2. The address of a pointer to the element to be added to the list.
**
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != 0 && new != 0)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
**	1) Input check is done if the both values are not NULL.
**	If the values are not null we set our links element next to the first link
**	that is pointed by lst in our parameters. We then set the pointer of lst to
**	"new" as our new "head"(starting node) of our linked list.
*/