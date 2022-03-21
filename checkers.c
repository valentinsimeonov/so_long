/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:44:38 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 18:50:47 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checking if P, E, C is in Map */
int	check_p_e_c_in_map(t_long *arch, t_list	**lines)
{
	t_list	*temp;
	int		i;

	temp = *lines;
	while (temp->next != NULL)
	{
		i = 0;
		while (temp->line[i] && temp->line[i] != '\n')
		{
			if (temp->line[i] == 'P')
				arch->player++;
			else if (temp->line[i] == 'E')
				arch->exit++;
			else if (temp->line[i] == 'C')
				arch->collect++;
			i++;
		}
		temp = temp->next;
	}
	if (arch->player == 0 || arch->exit == 0 || arch->collect == 0)
		return (0);
	return (1);
}

/* Check that there are not any other Characters except P,C,E, 1 and 0 */
int	is_p_c_e_1_0(t_list **lines)
{
	t_list	*temp;
	int		i;
	int		len_line;

	temp = (*lines);
	len_line = ft_strlen_line(lines);
	while (temp->next != NULL)
	{
		i = 0;
		while (i < len_line)
		{
			if (temp->line[i] != '0' && temp->line[i] != '1' && \
			temp->line[i] != 'P' && temp->line[i] != 'E' && \
			temp->line[i] != 'C' && temp->line[i] != '\n')
				return (0);
			i++;
		}
		temp = temp->next;
	}
	return (1);
}

/* Checking the Length of the Lines are the Same */
int	is_length(t_list **lines)
{
	t_list	*temp;
	int		len_line;

	temp = (*lines);
	len_line = ft_strlen_line(lines);
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (len_line != ft_strlen_line_1(temp->line))
			return (0);
	}
	return (1);
}

/* Checking if first Line and Last Line is Made from 1s */
int	is_first_last_line(t_list **lines)
{
	t_list	*temp;

	temp = (*lines);
	if (!ft_strchr_first_line(temp->line, '1'))
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	if (!ft_strchr_second_line(temp->line, '1'))
		return (0);
	return (1);
}

/* Check if First Char and Last Char is 1 */
int	is_first_last_char(t_list **lines)
{
	t_list	*temp;
	int		len_line;
	int		j;

	temp = (*lines);
	len_line = ft_strlen_line(lines);
	while (temp->next != NULL)
	{
		j = 0;
		if (temp->line[j] != 49)
			return (0);
		j = len_line - 1;
		if (temp->line[j] != 49)
			return (0);
		temp = temp->next;
	}
	return (1);
}
