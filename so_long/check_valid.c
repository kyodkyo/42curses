/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:33:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/21 11:21:25 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char *argv, int *fd)
{
	int	i;

	i = 0;
	if (argc != 2)
		error_exit();
	while (argv[i])
		i++;
	if (argv[i - 4] != '.' || argv[i - 3] != 'b'
		|| argv[i - 2] != 'e' || argv[i - 1] != 'r')
		error_exit();
	*fd = open(argv, O_RDONLY);
	if (*fd < 0)
		error_exit();
}

void	check_board(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->board[++i])
	{
		j = -1;
		while (map->board[i][++j])
		{
			if (map->board[i][j] == 'C')
				map->c_cnt++;
			else if (map->board[i][j] == 'E')
				map->e_cnt++;
			else if (map->board[i][j] == 'P')
			{
				map->p_cnt++;
				map->now_x = j;
				map->now_y = i;
			}
		}
	}
	if (map->c_cnt < 1 || map->e_cnt != 1 || map->p_cnt != 1)
		error_exit();
	map->items = map->c_cnt;
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
	set_image(map);
}

void	check_path(t_map *map)
{
	int		i;
	char	**visited;

	i = -1;
	map->dfs_board = malloc(sizeof(char **) * (map->board_height + 1));
	if (!map->dfs_board)
		error_exit();
	map->dfs_board[map->board_height] = NULL;
	while (++i < map->board_height)
	{
		map->dfs_board[i] = ft_strdup(map->board[i]);
		if (!map->dfs_board[i])
			error_exit();
	}
	visited = make_visited(map);
	dfs(map, map->now_y, map->now_x, visited);
	if (map->exit_flag != 1 || map->item_flag != 1)
	{
		free_2d_array(map->board_height, map->dfs_board);
		error_exit();
	}
	map->items = map->c_cnt;
	free_2d_array(map->board_height, map->dfs_board);
	free_2d_array(map->board_height, visited);
}

void	dfs(t_map *map, int y, int x, char **visited)
{
	if (x < 0 || y < 0 || x > map->board_width - 1 || map->board_height - 1 < y
		|| map->dfs_board[y][x] == '1' || visited[y][x] == 1)
		return ;
	visited[y][x] = 1;
	if (map->dfs_board[y][x] == 'C')
		map->items--;
	if (map->items == 0)
		map->item_flag = 1;
	if (map->dfs_board[y][x] == 'E')
		map->exit_flag = 1;
	dfs(map, y - 1, x, visited);
	dfs(map, y + 1, x, visited);
	dfs(map, y, x - 1, visited);
	dfs(map, y, x + 1, visited);
}
