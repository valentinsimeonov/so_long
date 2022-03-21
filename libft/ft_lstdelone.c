/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:19:08 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 14:53:45 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Takes as a parameter an element and frees the memory of the element’s
**	content using the function ’del’ given as a parameter and free the element.
**	The memory of ’next’ must not be freed.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->line);
		free(lst);
	}
}

/*	#1. The element to free.
**	#2. The address of the function used to delete the content.
**
**	1) Check if the parameters passed through the functions are NULL.
**	If the parameters are not NULL, function del is called to delete the
**	content of the list.
**	Afterwards free function is used to free the memory that has been allocated
**	to the given list.
*/