/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:25:28 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/16 20:35:25 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	
	int		fd_map;
	int	lines_count;
	t_long	arch;
	// t_data	*img;
	// t_list	*lines;

	fd_map = open(argv[1], O_RDONLY);
	if (argc != 2 || !is_map(argv[1]) || fd_map <= 0)
		write(1, "Error, either Invalid Argument or Invalid Map", 44);
	arch.lines = list_init(fd_map);
	// print_list(&lines);
	lines_count = list_element_count(&arch.lines);
	
	if (!check_P_E_C_in_map(&arch.lines) || !is_length_of_lines_the_same(&arch.lines) || \
	!is_first_and_last_line_is_one(&arch.lines) || !is_first_char_and_last_char_one(&arch.lines) \
	|| !is_only__P_C_E_1_0_in_map(&arch.lines))
		write(1, "Error, Map is Wack!", 19);


	// /* Initialising the MLX Library and Creating the Game Window */
	arch.img = malloc(sizeof(t_data));
	arch.mlx = mlx_init();
	arch.mlx_win = mlx_new_window(arch.mlx, ft_strlen_line_1(arch.lines->line) * 48, \
	list_element_count(&arch.lines) * 48, "so_long");
	create_visual_map(&arch, &arch.lines, arch.img);
	mlx_key_hook(arch.mlx_win, key_hook, &arch);

	// mlx_hook(arch.mlx_win, ON_DESTROY, 0, )
	mlx_loop(arch.mlx);
	
}

int	key_hook(int keycode, t_long *arch, t_list	**lines, t_data *img)
{
	if (keycode == UP || keycode == DOWN \
	|| keycode == LEFT || keycode == RIGHT)
	{
		player_position(arch, lines, keycode);
		create_visual_map(arch, lines, img);
	}
	if (keycode == ESC)
		finish(arch);
	return (0);
}

void	player_position(t_long *arch, t_list **lines, int keycode)
{
	t_list	*temp;
	char	*next;

	temp = get_position(arch, *lines);
	next = next_move(temp, arch, keycode);
	if (*next != '1')
	{
		if (*next == 'C' || *next == '0')
		{
			if (*next == 'C')
				arch->collected++;
			arch->moves++;
		}
		else if (*next == 'E' && arch->collected == arch->collect)
		{
			arch->moves++;
			finish(arch);
		}
		else if (*next == 'E')
			return ;
		*next = 'P';
		*(char *)(temp->next->line + arch->pos_x) = '0';	
	}
	return ;
}

t_list	*get_position(t_long *arch, t_list *lines)
{
	t_list	*temp;
	
	temp = lines->next;
	print_list(&lines);
	while (temp)
	{
		arch->pos_x = 0;
		while (*(char *)(temp->line + arch->pos_x) \
		&& *(char *)(temp->line + arch->pos_x) != 'P' \
		&& *(char *)(temp->line + arch->pos_x) != '\n' )
			arch->pos_x++;
		if (*(char *)(temp->line + arch->pos_x) == 'P')
			break;
		lines = temp;
		temp = temp->next;
	}
	return (lines);
}

char	*next_move(t_list *temp, t_long *arch, int keycode)
{
	char	*next;

	next = (char *)temp->line;
	if (keycode == UP)
		next = (char *)temp->line + arch->pos_x;
	if (keycode == DOWN)
		next = (char *)temp->next->next->line + arch->pos_x;
	if (keycode == LEFT)
		next = (char *)temp->next->line + arch->pos_x - 1;
	if (keycode == RIGHT)
		next = (char *)temp->next->line + arch->pos_x + 1;
	return (next);
}

int	finish(t_long *arch)
{
	// ft_lstclear(lines, free);
	mlx_destroy_window(arch->mlx, arch->mlx_win);
	write(1, "You have Closed the Game!\n", 26);
	exit(0);
}

void	create_visual_map(t_long *arch, t_list	**lines, t_data *img)
{
	t_list	*temp;
	char	*line;
	int		i;

	i = 0;
	img->point_x = 0;
	img->point_y = 0;
	temp = *lines;
	while (temp)
	{
		line = temp->line;
		while (line[i] && line[i] != '\n')
		{
			load_assests(arch, img, line[i], img->point_x, img->point_y);
			i++;
			img->point_x += 48;
		}
		temp = temp->next;
		img->point_x = 0;
		img->point_y += 48;
		i = 0;
	}
}

void	load_assests(t_long	*arch, t_data *img, char c, int x, int y)
{
	if (c == '1')
		img->img = mlx_xpm_file_to_image(arch->mlx, "./data/red_walls.xpm", &img->size_x, &img->size_y);
	else if (c == 'P')
	{
		img->img = mlx_xpm_file_to_image(arch->mlx, "./data/space.xpm", &img->size_x, &img->size_y);
		img->img = mlx_xpm_file_to_image(arch->mlx, "./data/sun_resized.xpm", &img->size_x, &img->size_y);
	}
	else if (c == 'E')
		img->img = mlx_xpm_file_to_image(arch->mlx, "./data/exit_x.xpm", &img->size_x, &img->size_y);
	else if (c == 'C')
	{
		img->img = mlx_xpm_file_to_image(arch->mlx, "./data/space.xpm", &img->size_x, &img->size_y);
		img->img = mlx_xpm_file_to_image(arch->mlx, "./data/heart.xpm", &img->size_x, &img->size_y);
	}
	else
		img->img = mlx_xpm_file_to_image(arch->mlx, "./data/space.xpm", &img->size_x, &img->size_y);
	mlx_put_image_to_window(arch->mlx, arch->mlx_win, img->img, x, y);
	// printf("%p\n", img->img);
	// printf("%p\n", arch->mlx);
	mlx_destroy_image(arch->mlx, img->img);
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
	lines_count = 1;
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