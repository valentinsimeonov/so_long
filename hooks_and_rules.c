/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_and_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:02:28 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/17 17:02:47 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Determining where the Key Pressed Takes the Player and what Action it Determines */
int	key_hook(int keycode, t_long *arch)
{
	if (keycode == UP || keycode == DOWN \
	|| keycode == LEFT || keycode == RIGHT)
	{
		p_position_and_counting_objects(arch, keycode);
		create_visual_map(arch);
	}
	if (keycode == ESC)
		finish(arch);
	return (0);
}

/* Using Player's Position and Next Move to Determine what Happens to the Objects in the Map and Finishes the Game */
void	p_position_and_counting_objects(t_long *arch, int keycode)
{
	t_list	*temp;
	char	*next;

	temp = player_position(arch, arch->lines);
	next = player_next_move(temp, arch, keycode);
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
			printf("%d\n", arch->collect);
			printf("%d\n", arch->collected);
			arch->moves++;
			finish(arch);
		}
		else if (*next == 'E')
			// finish(arch);
			return ;
		*next = 'P';
		*(char *)(temp->next->line + arch->pos_x) = '0';	
	}
	return ;
}

/* Determining the Player's Position in the Map */
t_list	*player_position(t_long *arch, t_list *lines)
{
	t_list	*temp;
	
	temp = lines->next;
	// print_list(&lines);
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

/* Determining where the Next Player Move would Arrive the Player*/
char	*player_next_move(t_list *temp, t_long *arch, int keycode)
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