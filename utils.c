/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:50:16 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/11 19:44:36 by vsimeono         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*(str + i) == c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + len + 1);
	return (NULL);
}

int	ft_strchr_modified(const char *s, int c)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = (char *)s;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}