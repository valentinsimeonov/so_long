/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:03:09 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 15:03:50 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checking if the Map has Extension .ber*/
int	is_map(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 4] == '.' && argv[len - 3] == 'b' && \
	argv[len - 2] == 'e' && argv[len - 1] == 'r')
		return (1);
	return (0);
}
