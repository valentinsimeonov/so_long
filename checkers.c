/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:44:38 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/17 15:58:07 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

		 
/* Checking if P, E, C is in Map */
int	check_P_E_C_in_map(t_long *arch, t_list	**lines)
{
	t_list	*temp;
	int		i;
	int		len_line;
	int		flag[255];
	
	temp = *lines;
	len_line = ft_strlen_line(lines);
	i = 0;
	while (i > 255)
	{
		flag[i] = 0;
		i++;
	}
	while (temp->next != NULL)
	{
		if (ft_strchr(temp->line, 'P'))
		{	
			flag[80] = 1;
			arch->player++;
		}
		if (ft_strchr(temp->line, 'E'))
		{	
			flag[69] = 1;
			arch->exit++;
		}
		if (ft_strchr(temp->line, 'C'))
		{
			flag[67] = 1;
			arch->collect++;
			printf("%d\n", arch->collect);
			printf("%d\n", arch->collect);
			printf("%d\n", arch->collected);
		}
		temp = temp->next;
	}
	if (flag[80] != 1 || flag[69] != 1 || flag[67] != 1)
		return (0);
	return (1);
}

/* Check that there are not any other Characters except P,C,E, 1 and 0 */
int	is_only__P_C_E_1_0_in_map(t_list **lines)
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
			if (temp->line[i] != '0' && temp->line[i] != '1' && temp->line[i] != 'P' && temp->line[i] != 'E' && temp->line[i] != 'C' && temp->line[i] != '\n')
				return (0);
			i++;
		}
		temp = temp->next;
	}
	return (1);
}

/* Checking the Length of the Lines are the Same */
int	is_length_of_lines_the_same(t_list **lines)
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
int	is_first_and_last_line_is_one(t_list **lines)
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
int	is_first_char_and_last_char_one(t_list **lines)
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