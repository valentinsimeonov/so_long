/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:25:28 by vsimeono          #+#    #+#             */
/*   Updated: 2022/03/21 19:33:24 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd_map;
	int		lines_count;
	t_long	arch;

	fd_map = open(argv[1], O_RDONLY);
	if (argc != 2 || !is_map(argv[1]) || fd_map <= 0)
		error_arg();
	arch.lines = list_init(fd_map);
	lines_count = list_element_count(&arch.lines);
	arch.moves = 0;
	arch.collected = 0;
	arch.collect = 0;
	arch.player = 0;
	if (!check_p_e_c_in_map(&arch, &arch.lines) || !is_length(&arch.lines) || \
	!is_first_last_line(&arch.lines) || !is_first_last_char(&arch.lines) \
	|| !is_p_c_e_1_0(&arch.lines))
		error(&arch);
	arch.mlx = mlx_init();
	arch.mlx_win = mlx_new_window(arch.mlx, ft_strlen_line_1(arch.lines->line) \
	* 48, list_element_count(&arch.lines) * 48, "so_long");
	create_visual_map(&arch);
	mlx_key_hook(arch.mlx_win, key_hook, &arch);
	mlx_hook(arch.mlx_win, ON_DESTROY, 0, finish, &arch);
	mlx_loop_hook(arch.mlx, loop, &arch);
	mlx_loop(arch.mlx);
}
