/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:33:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/19 21:36:14 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	if (argc != 2)
		error_exit();
	while (argv[i])
		i++;
	if (argv[i - 4] != '.' || argv[i - 3] != 'b'
		|| argv[i - 2] != 'e' || argv[i - 1] != 'r')
		error_exit();
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit();
	return (fd);
}

void	check_board(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->board[i])
	{
		j = 0;
		while (map->board[i][j])
		{
			if (map->board[i][j] == 'C')
				map->c_cnt++;
			else if (map->board[i][j] == 'E')
				map->e_cnt++;
			else if (map->board[i][j] == 'P')
				map->p_cnt++;
			j++;
		}
		i++;
	}
	if (map->c_cnt != 1 || map->e_cnt != 1 || map->p_cnt != 1)
		error_exit();
	check_board_rec(map);
}

void	check_board_rec(t_map *map)
{
	int	i;

	i = 0;
	map->board_width = ft_strlen(map->board[i]);
	if (map->board_width == 0)
		error_exit();
	while (map->board[i])
	{
		if (map->board_width != ft_strlen(map->board[i]))
			error_exit();
		i++;
	}
}

void	check_path(t_map *map)
{
	int	i;

	i = -1;
	map->dfs_board = malloc(sizeof(char *) * map->board_height + 1);
	if (!map->dfs_board)
		error_exit();
	map->dfs_board[map->board_height] = NULL;
	while (++i < map->board_height)
	{
		map->dfs_board[i] = ft_strdup(map->board[i]);
		if (!map->dfs_board[i])
			error_exit();
	}
	dfs(map, map->now_x, map->now_y);
	if (map->exit_flag != 1 || map->item_flag != 1)
	{
		free(map->dfs_board);
		error_exit();
	}
	i = -1;
	while (map->dfs_board[++i])
		free(map->dfs_board[i]);
	free(map->dfs_board);
}

void	dfs(t_map *map, int y, int x)
{
	if (map->c_cnt == 0)
		map->item_flag = 1;
	if (map->dfs_board[y][x] == '1' || x < 0 || y < 0
		|| x > map->board_width - 1 || map->board_height - 1 < y)
		return ;
	if (map->dfs_board[y][x] == 'C')
		map->c_cnt--;
	if (map->dfs_board[y][x] == 'E')
		map->exit_flag = 1;
	dfs(map, y - 1, x);
	dfs(map, y + 1, x);
	dfs(map, y, x - 1);
	dfs(map, y, x + 1);
}
