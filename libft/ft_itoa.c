/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:14:17 by vsimeono          #+#    #+#             */
/*   Updated: 2021/10/02 20:37:13 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_int_lenght(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*temp;
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count_int_lenght(n);
	temp = ft_calloc(sizeof(char), (len + 1));
	if (!temp)
		return (NULL);
	str = temp;
	if (n < 0)
	{
		*temp = '-';
		n *= -1;
	}
	temp += len;
	while (n >= 10)
	{
		temp--;
		*temp = ((n % 10) + '0');
		n /= 10;
	}
	*(--temp) = (n % 10) + '0';
	return (str);
}
