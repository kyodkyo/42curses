/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:22:41 by dakyo             #+#    #+#             */
/*   Updated: 2024/05/12 13:21:54 by dakang           ###   ########.fr       */
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
	mlx_hook(map.win, KEY_EXIT, 0, &finish_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
