/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:02:08 by dakang            #+#    #+#             */
/*   Updated: 2024/04/21 03:26:04 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(int fd, t_map *map)
{
	char	*line;
	char	*total;
	char	*tmp;

	total = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->board_height++;
		tmp = total;
		total = ft_strjoin(total, line);
		if (tmp)
			free(tmp);
		if (!total)
			free(total);
		free(line);
		line = NULL;
	}
	map->board = ft_split(total, '\n');
	if (!map->board)
		error_exit('j');
	free(total);
}

void	set_image(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, \
			map->board_width * 64, map->board_height * 64, "my_mlx");
	map->racoon = mlx_xpm_file_to_image(map->mlx, "./textures/racoon.xpm",
			&map->img_width, &map->img_height);
	map->tree = mlx_xpm_file_to_image(map->mlx, "./textures/tree.xpm",
			&map->img_width, &map->img_height);
	map->floor = mlx_xpm_file_to_image(map->mlx, "./textures/floor.xpm",
			&map->img_width, &map->img_height);
	map->seed = mlx_xpm_file_to_image(map->mlx, "./textures/seed.xpm",
			&map->img_width, &map->img_height);
	map->house = mlx_xpm_file_to_image(map->mlx, "./textures/house.xpm",
			&map->img_width, &map->img_height);
	map->house_open = mlx_xpm_file_to_image(map->mlx, "./textures/house_open.xpm",
			&map->img_width, &map->img_height);
	if (!map->racoon || !map->tree || !map->floor
		|| !map->seed || !map->house)
		error_exit('k');
}

void	image_to_board(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->win_y = 0;
	while (map->board[i])
	{
		j = 0;
		map->win_x = 0;
		while (map->board[i][j])
		{
			put_image_to_window(map, i, j);
			check_wall(map);
			j++;
			map->win_x += 64;
		}
		i++;
		map->win_y += 64;
	}
}

void	put_image_to_window(t_map *map, int i, int j)
{
	if (map->board[i][j] == '0')
		put_image_to_window_floor(map);
	else if (map->board[i][j] == '1')
		put_image_to_window_tree(map);
	else if (map->board[i][j] == 'C')
		put_image_to_window_seed(map);
	else if (map->board[i][j] == 'E')
	{
		map->exit_pos_x = i;
		map->exit_pos_y = j;
		put_image_to_window_house(map);
	}
	else if (map->board[i][j] == 'P')
		put_image_to_window_racoon(map, i, j);
	else
		error_exit('l');
}

void	check_wall(t_map *map)
{
	int	k;

	k = 0;
	while (k < map->board_width)
	{
		if (map->board[0][k] != '1'
			|| (map->board[map->board_height - 1][k]) != '1')
			error_exit('m');
		k++;
	}
	k = 0;
	while (k < map->board_height)
	{
		if (map->board[k][0] != '1'
			|| (map->board[k][map->board_width - 1]) != '1')
			error_exit('n');
		k++;
	}
}
