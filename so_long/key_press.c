/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:10:24 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/22 18:40:13 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	key_press(int code, t_map *map)
{
	int	x;
	int	y;

	if (code == KEY_W)
		move_duck(map, map->now_x, map->now_y - 1);
	else if (code == KEY_A)
		move_duck(map, map->now_x - 1, map->now_y);
	else if (code == KEY_S)
		move_duck(map, map->now_x, map->now_y + 1);
	else if (code == KEY_D)
		move_duck(map, map->now_x + 1, map->now_y);
	else if (code == KEY_ESC)
		finish_game(map);
	return (0);
}

void	move_duck(t_map *map, int nx, int ny)
{
	if (map->board[ny][nx] == '1')
		return ;
	if (map->board[ny][nx] == 'E' && map->items == 0)
		finish_game(map);
	mlx_put_image_to_window(map->mlx, map->win, map->floor,
		map->now_x * 64, map->now_y * 64);
	if (map->board[ny][nx] == 'C')
	{
		map->items--;
		map->board[ny][nx] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->floor,
			nx * 64, ny * 64);
		if (map->items == 0)
			mlx_put_image_to_window(map->mlx, map->win, map->house,
				map->exit_pos_y * 64, map->exit_pos_x * 64);
	}
	if (map->board[map->now_y][map->now_x] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->house,
			map->exit_pos_y * 64, map->exit_pos_x * 64);
	ft_putnbr(++(map->move_cnt));
	write(1, "\n", 1);
	map->now_x = nx;
	map->now_y = ny;
	mlx_put_image_to_window(map->mlx, map->win, map->duck,
		map->now_x * 64, map->now_y * 64);
}

int	finish_game(t_map *map)
{
	int	i;

	i = 0;
	while (map->board[i])
	{
		free(map->board[i]);
		i++;
	}
	free(map->board);
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

void	set_image(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, \
			map->board_width * 64, map->board_height * 64, "my_mlx");
	map->duck = mlx_xpm_file_to_image(map->mlx, "./textures/duck.xpm",
			&map->img_width, &map->img_height);
	map->tree = mlx_xpm_file_to_image(map->mlx, "./textures/tree.xpm",
			&map->img_width, &map->img_height);
	map->floor = mlx_xpm_file_to_image(map->mlx, "./textures/floor.xpm",
			&map->img_width, &map->img_height);
	map->seed = mlx_xpm_file_to_image(map->mlx, "./textures/seed.xpm",
			&map->img_width, &map->img_height);
	map->house = mlx_xpm_file_to_image(map->mlx, "./textures/house.xpm",
			&map->img_width, &map->img_height);
	map->house_open = mlx_xpm_file_to_image(map->mlx,
			"./textures/house_open.xpm", &map->img_width, &map->img_height);
	if (!map->duck || !map->tree || !map->floor
		|| !map->seed || !map->house)
		error_exit();
	image_to_board(map);
}
