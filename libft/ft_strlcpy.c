/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:16:16 by vsimeono          #+#    #+#             */
/*   Updated: 2021/10/02 20:35:18 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	buffer;

	lensrc = ft_strlen(src);
	if (dstsize != 0)
	{
		if (lensrc >= dstsize)
		{
			buffer = dstsize - 1;
		}
		else
		{
			buffer = lensrc;
		}
		ft_memcpy(dst, src, buffer);
		*(dst + buffer) = '\0';
	}
	return (lensrc);
}
