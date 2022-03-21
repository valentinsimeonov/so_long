/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:15:04 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 11:15:11 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	#1. The beginning of the list.
**	Length of the list.
**	Counts the number of elements in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	if (lst)
	{
		while (lst != NULL)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

/*
**	1) Performing check if the list exists before itterating through it.
**
**	2) Perform itteration by going to next linked list if its not null, if the
**	list is NULL while loop will break and we return the length of the list.
*/