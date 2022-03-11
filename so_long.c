/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:25:28 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/11 21:28:25 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	
	int		fd_map;
	// t_long	*arch;
	t_list	*lines;
	// t_data	*img;
	char	*temp_line;
	int		list_count;

	list_count = 0;
	fd_map = open(argv[1], O_RDONLY);
	if (argc != 2 || !is_map(argv[1]) || fd_map <= 0)
		write(1, "Error, either Invalid Argument or Invalid Map", 44);


	temp_line = get_next_line(fd_map);
	while (temp_line)
	{
		ft_lstadd_back(&lines, create_element(temp_line));
		temp_line = get_next_line(fd_map);
		list_count++;
	}


	if (!check_map(&lines))
	{
		write(1, "Error, Map is Wack!", 19);
	}
	
	
	// long.mlx = mlx_init();
	// long.mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	// long.img->img = mlx_new_image(mlx, 1920, 1080);
	// // img = mlx_new_image(mlx, 300, 150);
	// mlx_loop(mlx);
	// long.img->addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
}

int	check_map(t_list **lines)
{
	int		len_line;
	t_list	*temp;
	char	*flag[255];
	int		i;


	temp = (*lines);
	len_line = ft_strlen_line(lines);

	i = 0;
	while (flag[i] != '\0')
	{
		flag[i] = 0;
		i++;
	}
	


	
	while (temp->next != NULL)
	{
		/* Checking if P, E, C is in Map */
		if (flag[ft_atoi('P')] == 1 && ft_strchr(temp->line, 'P'))
		{
			// flag[ft_atoi('P')] == 2;
			return (0);
		}
		if (ft_strchr(temp->line, 'P'))
			flag[ft_atoi('P')] == 1;
		
		if (flag[ft_atoi('E')] == 1 && ft_strchr(temp->line, 'E'))
			// flag[ft_atoi('E')] == 2;
			return (0);
		if (ft_strchr(temp->line, 'E'))
			flag[ft_atoi('E')] == 1;
		
		if (flag[ft_atoi('C')] == 1 && ft_strchr(temp->line, 'C'))
			// flag[ft_atoi('C')] == 2;
			return (0);
		if (ft_strchr(temp->line, 'C'))
			flag[ft_atoi('C')] == 1;
			
		/* Checking the Length of the Lines are the Same */
		if (len_line != ft_strlen_line_1(temp->line))
			return (0);
		temp = temp->next;
	}



	/* Checking if first Line and Last Line is Made from 1s */
	temp = (*lines);
	// if (ft_strchr_modified(temp->line, '1'))
	// 	return (1);
	if (!ft_strchr_modified(temp->line, '1'))
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	// if (!ft_strchr_modified(temp->line, '1'))
	// 	return (1);
	if (!ft_strchr_modified(temp->line, '1'))
		return (0);
	

	
	/* Check if First Char and Last Char is 1 */
	temp = (*lines);
	while (temp->next != NULL)
	{
		j = 0;
		if (temp->line[j] != 1)
			return (0);
		j = len_line;
		if (temp->line[j] != 1)
			return (0);
		temp = temp->next;
	}


	/* Check that there are not any other Characters except P,C,E, 1 and 0 */
		temp = (*lines);
	while (temp->next != NULL)
	{
		if (temp->line != )
		temp = temp->next;
	}
	
	return (1);
}

	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}
	last = temp;
	// printf("%d\n", counter);
	// printf("last: %p\n", temp);
	// printf("last value%d\n", last->value);
	temp = *stack;
	// printf("temp: %p\n", temp);
	// printf("temp value%d\n", temp->value);
	while (j < (counter - 1))
	{
		temp = temp->next;
		j++;
	}








int	is_map(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 4] == '.' && argv[len - 3] == 'b' && \
	argv[len - 2] == 'e' && argv[len - 1] == 'r')
		return (1);
	return (0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else 
		*lst = new;
}

t_list	*create_element(char *character)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->line = character;
	element->next = NULL;
	return (element);
}

void	print_stack(t_list **stack)
{
	t_list *temp_p;
	
	temp_p = *stack;
	if (*stack == NULL)
		printf("List is Empty\n");
	if (*stack != NULL)
	{	
		while (temp_p->next != NULL)
		{
			printf("%s", "In List: ");
			printf("%s\n", temp_p->line);
			temp_p = temp_p->next;
		}
		printf("%s", "In List: ");
		printf("%s\n", temp_p->line);
	}
}
