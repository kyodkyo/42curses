/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:10:24 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/19 21:25:49 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int code, t_map *map)
{
	int	x;
	int	y;

	x = map->now_x;
	y = map->now_y;
	if (code == KEY_W)
		move_racoon(map, x, y - 1);
	else if (code == KEY_A)
		move_racoon(map, x - 1, y);
	else if (code == KEY_S)
		move_racoon(map, x, y + 1);
	else if (code == KEY_D)
		move_racoon(map, x + 1, y);
	else if (code == KEY_ESC)
		finish_game(map);
	return (0);
}

void	move_racoon(t_map *map, int x, int y)
{
	if (map->board[y][x] == '1')
		return ;
	if (map->board[y][x] == 'E' && !map->item_flag)
		finish_game(map);
	if (map->board[y][x] == 'C')
	{
		map->items--;
		map->board[y][x] = 0;
		mlx_put_image_to_window(map->mlx, map->win, map->floor, x * 64, y * 64);
		if (!map->items)
			mlx_put_image_to_window(map->mlx, map->win, map->house,
				map->exit_pos_x * 64, map->exit_pos_y * 64);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->floor,
		map->now_x * 64, map->now_y * 64);
	if (map->board[map->now_x][map->now_y] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->house,
			map->now_x * 64, map->now_y * 64);
	map->move_cnt++;
	mlx_put_image_to_window(map->mlx, map->win, map->racoon, x * 64, y * 64);
	ft_putnbr(map->move_cnt);
	write(1, "\n", 1);
	map->now_x = x;
	map->now_y = y;
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
