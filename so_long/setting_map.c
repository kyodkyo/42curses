/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:02:08 by dakang            #+#    #+#             */
/*   Updated: 2024/04/22 18:38:46 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_board(int fd, t_map *map)
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
		error_exit();
	free(total);
	check_board(map);
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
		put_image_to_board(map, map->floor, map->floor);
	else if (map->board[i][j] == '1')
		put_image_to_board(map, map->floor, map->tree);
	else if (map->board[i][j] == 'C')
		put_image_to_board(map, map->floor, map->seed);
	else if (map->board[i][j] == 'E')
	{
		put_image_to_board(map, map->floor, map->house);
		map->exit_pos_x = i;
		map->exit_pos_y = j;
	}
	else if (map->board[i][j] == 'P')
	{
		put_image_to_board(map, map->floor, map->duck);
		map->now_x = j;
		map->now_y = i;
	}
	else
		error_exit();
}

void	put_image_to_board(t_map *board, void *img, void *img2)
{
	mlx_put_image_to_window(board->mlx, board->win, img,
		board->win_x, board->win_y);
	if (img2 == board->floor)
		return ;
	mlx_put_image_to_window(board->mlx, board->win, img2,
		board->win_x, board->win_y);
}

void	check_wall(t_map *map)
{
	int	k;

	k = 0;
	while (k < map->board_width)
	{
		if (map->board[0][k] != '1'
			|| (map->board[map->board_height - 1][k]) != '1')
			error_exit();
		k++;
	}
	k = 0;
	while (k < map->board_height)
	{
		if (map->board[k][0] != '1'
			|| (map->board[k][map->board_width - 1]) != '1')
			error_exit();
		k++;
	}
}
