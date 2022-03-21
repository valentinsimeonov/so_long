/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:42:11 by vsimeono          #+#    #+#             */
/*   Updated: 2021/10/02 19:57:29 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_string_counter(char *s, char c)
{
	int		counter;

	counter = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			counter++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**array;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	array = ft_calloc(ft_string_counter((char *)s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (s[start])
	{
		while ((s[start] == c) && s[start])
			start++;
		end = start;
		while ((s[end] != c) && s[end])
			end++;
		if (s[start])
			array[i] = ft_substr(s, start, end - start);
		i++;
		start = end;
	}
	return (array);
}
