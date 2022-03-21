/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:25:08 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 15:34:23 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

enum {
	ON_DESTROY = 17
};

typedef struct s_data
{
	void	*img;
	int		size_y;
	int		size_x;
	int		point_x;
	int		point_y;
}			t_data;

typedef struct s_long
{
	void	*mlx;
	void	*mlx_win;
	int		moves;
	int		collect;
	int		collected;
	int		player;
	int		exit;
	int		pos_x;
	t_list	*lines;
	t_data	img;
}			t_long;

/* Input Checkers */
int		is_map(char *argv);
int		check_map(t_list **lines);

/* Map Checkers */
int		ft_strchr_first_line(const char *s, char c);
int		ft_strchr_second_line(const char *s, char c);
int		is_first_last_char(t_list **lines);
int		is_p_c_e_1_0(t_list **lines);
int		check_p_e_c_in_map(t_long *arch, t_list	**lines);
int		is_length(t_list **lines);
int		is_first_last_line(t_list **lines);

/* Utils */
int		ft_strlen_line(t_list **lines);
int		ft_strlen_line_1(char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);

/* Linked Lists Utils */
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*create_element(char *character);
t_list	*list_init(int fd_map);
int		list_element_count(t_list **lines);
void	free_list(t_list **lines);

/* Creating the Visual Map */
void	load_assests(t_long	*arch, char c, int x, int y);
void	create_visual_map(t_long *arch);

/* Keyboard Hooks and Rules of the Game */
int		key_hook(int keycode, t_long *arch);
t_list	*player_position(t_long *arch, t_list *lines);
char	*player_next_move(t_list *temp, t_long *arch, int keycode);
void	p_position_and_counting_objects(t_long *arch, int keycode);
int		finish(t_long *arch);
int		loop(t_long *arch);

#endif