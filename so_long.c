/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:25:28 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/12 19:38:04 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	
	int		fd_map;
	int	lines_count;
	// t_long	*arch;
	t_list	*lines;
	// t_data	*img;

	fd_map = open(argv[1], O_RDONLY);
	if (argc != 2 || !is_map(argv[1]) || fd_map <= 0)
		write(1, "Error, either Invalid Argument or Invalid Map", 44);
		
	lines = list_init(fd_map);
	print_list(&lines);
	lines_count = list_element_count(&lines);
	if (!check_P_E_C_in_map(&lines) || !is_length_of_lines_the_same(&lines) || \
	!is_first_and_last_line_is_one(&lines) || !is_first_char_and_last_char_one(&lines) \
	|| !is_only__P_C_E_1_0_in_map(&lines))
	{
		write(1, "Error, Map is Wack!", 19);
	}
	
	// /* Initialising the MLX Library and Creting the Game Window */
	// long.mlx = mlx_init();
	// long.mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	// long.img->img = mlx_new_image(mlx, 1920, 1080);
	// // img = mlx_new_image(mlx, 300, 150);
	// mlx_loop(mlx);
	// long.img->addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
}








////////////////////////////////       ALL   GOOD    /////////////////////////////////



         //// Checkers   //////
/* Checking if P, E, C is in Map */
int	check_P_E_C_in_map(t_list **lines)
{
	t_list	*temp;
	int		i;
	int		len_line;
	int		flag[255];
	
	temp = (*lines);
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
			flag[80] = 1;
		if (ft_strchr(temp->line, 'E'))
			flag[69] = 1;
		if (ft_strchr(temp->line, 'C'))
			flag[67] = 1;
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


/* Counting the Lines (Elements) in Map (Linked List) */
int	list_element_count(t_list **lines)
{
	int	lines_count;
	t_list	*temp;

	temp = *lines;
	lines_count = 0;
	while (temp->next != NULL)
	{
		lines_count++;
		temp = temp->next;
	}
	return (lines_count);
}


/* Creating the Linked List, each Element has One Line from the Map */
t_list	*list_init(int fd_map)
{
	char	*temp_line;
	int		list_count;
	t_list	*lines;

	list_count = 0;
	temp_line = get_next_line(fd_map);
	while (temp_line)
	{
		ft_lstadd_back(&lines, create_element(temp_line));
		temp_line = get_next_line(fd_map);
		list_count++;
	}
	return (lines);
}
/* Adding an Element to the Linked List */
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
/* Creating the Element for the Linked List */
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


void	print_list(t_list **stack)
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









///////////////////////    TO DELETE     /////////////////////////////////////




	/* Creating the Linked List, each Element has a Line from the Map */
	// char	*temp_line;
	// int		list_count;

	// list_count = 0;
	// temp_line = get_next_line(fd_map);
	// while (temp_line)
	// {
	// 	ft_lstadd_back(&lines, create_element(temp_line));
	// 	temp_line = get_next_line(fd_map);
	// 	list_count++;
	// }


// 	/* Check if Map is a rectangle */
// int	check_if_map_rectangle(t_list **lines, int lines_count)
// {
// 	int		len_line;
	
// 	len_line = ft_strlen_line(lines);
// 	if (len_line == lines_count)
// 		return (0);
// 	return (1);
// }





		// printf("%c\n", temp->line[i]);
		// if (temp->line[i] != '1')
		// 	return (0);
		// else if (temp->line[i] != '0')
		// 	return (0);
		// else if (temp->line[i] != 'C')
		// 	return (0);
		// else if (temp->line[i] != 'E')
		// 	return (0);
		// else if (temp->line[i] != 'P')
		// 	return (0);
		// else if (temp->line[i] != '\n')
		// 	return (0);







// / int	check_map(t_list **lines, int lines_count)
// {
// 	int		len_line;
// 	t_list	*temp;
// 	char	*flag[255];
// 	int		i;

// 	temp = (*lines);
// 	len_line = ft_strlen_line(lines);

// 	// i = 0;
// 	// while (flag[i] != '\0')
// 	// {
// 	// 	flag[i] = 0;
// 	// 	i++;
// 	// }
// 	// while (temp->next != NULL)
// 	// {
// 	// 	/* Checking the Length of the Lines are the Same */
// 	// 	if (len_line != ft_strlen_line_1(temp->line))
// 	// 		return (0);
// 	// 	temp = temp->next;
// 	// }



// 	/* Checking if first Line and Last Line is Made from 1s */
// 	temp = (*lines);
// 	// if (ft_strchr_modified(temp->line, '1'))
// 	// 	return (1);
// 	if (!ft_strchr_modified(temp->line, '1'))
// 		return (0);
// 	while (temp->next != NULL)
// 		temp = temp->next;
// 	// if (!ft_strchr_modified(temp->line, '1'))
// 	// 	return (1);
// 	if (!ft_strchr_modified(temp->line, '1'))
// 		return (0);
	

	
// 	// /* Check if First Char and Last Char is 1 */
// 	// temp = (*lines);
// 	// while (temp->next != NULL)
// 	// {
// 	// 	j = 0;
// 	// 	if (temp->line[j] != 1)
// 	// 		return (0);
// 	// 	j = len_line;
// 	// 	if (temp->line[j] != 1)
// 	// 		return (0);
// 	// 	temp = temp->next;
// 	// }
// 	// return (1);
// }