/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:18:34 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 14:53:08 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	#1. The adress of a pointer to an element.
**	#2. The adress of the function used to iterate on the list. Iterates the
**	list ’lst’ and applies the function ’f’ to the content of each element.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst != NULL)
		{
			(f)(lst->line);
			lst = lst->next;
		}
	}
}

/*
**	1) Check performerd if the passed parameters are not NULL.
**	If the given parameters are not NULL, we perform iteration on the list.
**
**	2) Iteration on the list is performed by check the "next" link, while it's
**	not null we itterate through the list and apply the function F to the
**	content of the list.
*/