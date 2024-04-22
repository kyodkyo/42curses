/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:22:41 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/22 19:43:18 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	check_input(argc, argv[1], &fd);
	initialize(&map);
	make_board(fd, &map);
	check_path(&map);
	mlx_hook(map.win, KEY_PRESS, 0, &key_press, &map);
	mlx_hook(map.win, 17, 0, &finish_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
