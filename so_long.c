/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:25:28 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/17 17:06:31 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	
	int		fd_map;
	int	lines_count;
	t_long	arch;

	fd_map = open(argv[1], O_RDONLY);
	if (argc != 2 || !is_map(argv[1]) || fd_map <= 0)
		write(1, "Error, either Invalid Argument or Invalid Map", 44);
	arch.lines = list_init(fd_map);
	lines_count = list_element_count(&arch.lines);
	arch.moves = 0;
	arch.collected = 0;
	arch.collect = 0;
	arch.exit = 0;
	arch.player = 0;
	if (!check_P_E_C_in_map(&arch, &arch.lines) || !is_length_of_lines_the_same(&arch.lines) || \
	!is_first_and_last_line_is_one(&arch.lines) || !is_first_char_and_last_char_one(&arch.lines) \
	|| !is_only__P_C_E_1_0_in_map(&arch.lines))
		write(1, "Error, Map is Wack!", 19);
	/* Initialising the MLX Library and Creating the Game Window */
	arch.mlx = mlx_init();
	arch.mlx_win = mlx_new_window(arch.mlx, ft_strlen_line_1(arch.lines->line) * 48, \
	list_element_count(&arch.lines) * 48, "so_long");
	create_visual_map(&arch);
	mlx_key_hook(arch.mlx_win, key_hook, &arch);
	mlx_hook(arch.mlx_win, ON_DESTROY, 0, finish, &arch);
	mlx_loop_hook(arch.mlx, loop, &arch);
	mlx_loop(arch.mlx);
}

//////*   TO DELETE  *////////

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
