/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:19:53 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 11:20:05 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Deletes and frees the given element and every successor of that element,
**	using the function ’del’ and free(3). Finally, the pointer to the list must
**	be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	if (list != NULL)
	{
		while (list != NULL)
		{
			temp = list->next;
			ft_lstdelone(list, del);
			list = temp;
		}
	}
	*lst = NULL;
}

/*
**	#1. The adress of a pointer to an element.
**	#2. The adress of the function used to delete the content of the element.
**
**	1) First we declare two link structures, one will be temporary placeholder
**	and the other will hold the link the next link in the list.
**
**	2) We take the current links element next and store it in temp pointer.
**	then we pass our list, and delete function to ft_lstdelone function to
**	delete the content of the current list,
**
**	3) We then set our next variable into list which currently holds the link
**	that should be following the one we just deleted and put it into list, and
**	we start the loop again until we reach NULL.
**
**	4) Once our loop is finished and we have deleted everything we set the list
**	to NULL. Effectivelly deleting paramter passed link and all of those that
**	were following it.
*/
