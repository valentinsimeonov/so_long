/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:50:16 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 15:35:50 by vsimeono         ###   ########.fr       */
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
		if ((i == len - 1) && str[i] != '\n')
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
