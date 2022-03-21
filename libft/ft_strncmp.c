/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:32:46 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/30 18:33:29 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (ps1 == 0 || ps2 == 0)
		return (ps1[i] - ps2[i]);
	while ((i < n) && (ps1[i] != '\0' || ps2[i] != '\0'))
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		if (ps1[i] == ps2[i])
			i++;
	}
	return (0);
}
