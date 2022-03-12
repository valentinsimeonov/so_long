/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:25:08 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/12 16:30:09 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_long
{
	void	*mlx;
	void	*mlx_win;
	// t_list	*lines;
	// t_data	*img;
}			t_long;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_data;

typedef struct s_list
{
	char	*line;
	struct	s_list *next;
}			t_list;

/* Input Checkers */
int	is_map(char *argv);
int	check_map(t_list **lines);

// int	check_if_map_rectangle(t_list **lines, int lines_count);  /// TO DELETE
int	check_P_E_C_in_map(t_list **lines);
int	is_length_of_lines_the_same(t_list **lines);
int	is_first_and_last_line_is_one(t_list **lines);


/* Utils */
int	ft_strlen_line(t_list **lines);
int	ft_strlen_line_1(char *s);

int	ft_atoi(const char *str);

int	ft_strchr_first_line(const char *s, char c);
int	ft_strchr_second_line(const char *s, char c);
int	is_first_char_and_last_char_one(t_list **lines);
int	is_only__P_C_E_1_0_in_map(t_list **lines);



/* Linked Lists Utils */
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*create_element(char *character);
t_list	*list_init(int fd_map);
int	list_element_count(t_list **lines);




/* TO DELETE*/
void	print_list(t_list **stack);




/* Get Next Line */
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*move_in_line(char *line, char *buf);
char	*ft_strjoin(char const *s1, char const *s2);



#endif