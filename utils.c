/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:50:16 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/14 17:26:12 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_line(t_list **lines)
{
	int		i;

	i = 0;
	while ((*lines)->line[i] != '\0' && (*lines)->line[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen_line_1(char *s)
{
	int		i;

	i = 0;
	while ((s[i] != '\0' && s[i] != '\n'))
		i++;
	return (i);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	*str;
// 	int		len;

// 	i = 0;
// 	str = (char *)s;
// 	len = ft_strlen(s);
// 	while (i <= len)
// 	{
// 		if (*(str + i) == c)
// 			return (str + i);
// 		i++;
// 	}
// 	if (c == 0)
// 		return (str + len + 1);
// 	return (NULL);
// }

int	ft_strchr_first_line(const char *s, char c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	while (i < len)
	{
		if ((i == len - 1)  && str[i] != '\n')
			return (0);
		else if ((i < len -1) && str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strchr_second_line(const char *s, char c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	while (i < len)
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || (*(str + i) == ' '))
	{
		i++;
	}
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((*(str + i) >= 48 && *(str + i) <= 57))
	{
		num = (num * 10) + (*(str + i) - '0');
		i++;
	}
	return (num * sign);
}

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*current;
// 	t_list	*temp;

// 	current = *lst;
// 	while (current != NULL && del)
// 	{
// 		temp = current->next;
// 		del(current->content);
// 		free(current);
// 		current = temp;
// 	}
// 	*lst = NULL;
// }

