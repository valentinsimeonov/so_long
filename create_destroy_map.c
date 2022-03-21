/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:04:00 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 15:30:16 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_long *arch)
{
	char	*moves;

	moves = ft_itoa(arch->moves);
	mlx_string_put(arch->mlx, arch->mlx_win, 30, 30, 0xffff00, moves);
	return (0);
}

/* Freeing the Allocated Memory for Linked List and for Graphical Interface */
int	finish(t_long *arch)
{
	free_list(&arch->lines);
	mlx_destroy_window(arch->mlx, arch->mlx_win);
	write(1, "You have Closed the Game!\n", 26);
	exit(0);
}

/* Creating the Visual Map */
void	create_visual_map(t_long *arch)
{
	t_list	*temp;
	char	*line;
	int		i;

	i = 0;
	arch->img.point_x = 0;
	arch->img.point_y = 0;
	temp = arch->lines;
	while (temp)
	{
		line = temp->line;
		while (line[i] && line[i] != '\n')
		{
			load_assests(arch, line[i], arch->img.point_x, arch->img.point_y);
			i++;
			arch->img.point_x += 48;
		}
		temp = temp->next;
		arch->img.point_x = 0;
		arch->img.point_y += 48;
		i = 0;
	}
}

/* Loading Pictures as the Pixels for the Graphical Map
according to their Corresponding Lettter or Number */
void	load_assests(t_long	*arch, char c, int x, int y)
{
	if (c == '1')
		arch->img.img = mlx_xpm_file_to_image(arch->mlx, \
		"./data/red_walls.xpm", &arch->img.size_x, &arch->img.size_y);
	else if (c == 'P')
	{
		arch->img.img = mlx_xpm_file_to_image(arch->mlx, \
		"./data/space.xpm", &arch->img.size_x, &arch->img.size_y);
		arch->img.img = mlx_xpm_file_to_image(arch->mlx, \
		"./data/sun_resized.xpm", &arch->img.size_x, &arch->img.size_y);
	}
	else if (c == 'E')
		arch->img.img = mlx_xpm_file_to_image(arch->mlx, \
		"./data/exit_x.xpm", &arch->img.size_x, &arch->img.size_y);
	else if (c == 'C')
	{
		arch->img.img = mlx_xpm_file_to_image(arch->mlx, \
		"./data/space.xpm", &arch->img.size_x, &arch->img.size_y);
		arch->img.img = mlx_xpm_file_to_image(arch->mlx, \
		"./data/heart.xpm", &arch->img.size_x, &arch->img.size_y);
	}
	else
		arch->img.img = mlx_xpm_file_to_image(arch->mlx, \
		"./data/space.xpm", &arch->img.size_x, &arch->img.size_y);
	mlx_put_image_to_window(arch->mlx, arch->mlx_win, arch->img.img, x, y);
	mlx_destroy_image(arch->mlx, arch->img.img);
}
