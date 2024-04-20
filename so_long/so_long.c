/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:22:41 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/21 03:03:09 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = check_input(argc, argv[1]);
	initialize(&map, 0, sizeof(t_map));
	make_map(fd, &map);
	check_board(&map);
	set_image(&map);
	image_to_board(&map);
	check_path(&map);
	mlx_hook(map.win, KEY_PRESS, 0, &key_press, &map);
	mlx_hook(map.win, 17, 0, &finish_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
