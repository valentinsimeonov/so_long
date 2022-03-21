/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:17:13 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 14:52:42 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Iterates the list ’lst’ and applies the function ’f’ to the content of each
**	element. Creates a new list resulting of the successive applications of
**	the function ’f’. The ’del’ function is used to delete the content of an
**	element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp_list;

	if (lst == 0 || f == 0)
		return (0);
	while (lst != 0)
	{
		temp_list = ft_lstnew(f(lst->line));
		if (temp_list == 0)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, temp_list);
	}
	return (new_list);
}
/*
**	#1. The adress of a pointer to an element.
**	#2. The adress of the function used to iterate on
**	#3. The adress of the function used to delete the content of an element
**	if needed.
**
**	1) We are starting with the 2 list pointers and the paremeter checks.
**	If lst or f are NULL we return NULL;
**
**	2) Itteration is performed as long as we did not come to the last element
**	in the linked lists. During that itteration we create new list using
**	ft_lstnew function which creates new list and applis F function on the
**	content of that list.
**
**	3) In case that list creation has failed we delete that list using
**	ft_lstclear function and apply del function to it. and we return NULL in
**	in this case.
**
**	4) In case that everything went successfully we add the new list to the end
**	of created list with the ft_lstadd_back. And we loop through it until we
**	come to the end of the linked list.
**
**	5) In the end we just return "new_list" which contains all the newly created
**	lists that we have created.
**
*/