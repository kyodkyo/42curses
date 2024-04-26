/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:00:28 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/22 19:41:06 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	if (count == 0 || size == 0)
		*(char *)res = 0;
	ft_bzero(res, count * size);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = -1;
	while (++i < n)
		ptr[i] = 0;
}

void	initialize(t_map *map)
{
	map->board = NULL;
	map->dfs_board = NULL;
	map->board_width = 0;
	map->board_height = 0;
	map->img_width = 0;
	map->img_height = 0;
	map->now_x = 0;
	map->now_y = 0;
	map->duck = NULL;
	map->tree = NULL;
	map->floor = NULL;
	map->seed = NULL;
	map->house = NULL;
	map->house_open = NULL;
	map->c_cnt = 0;
	map->e_cnt = 0;
	map->p_cnt = 0;
	map->items = 0;
	map->item_flag = 0;
	map->exit_flag = 0;
	map->exit_pos_x = 0;
	map->exit_pos_y = 0;
	map->move_cnt = 0;
}

char	**make_visited(t_map *map)
{
	int		i;
	char	**visited;

	i = 0;
	visited = ft_calloc(map->board_height + 1, sizeof(char **));
	while (i < map->board_height)
	{
		visited[i] = ft_calloc(map->board_width + 1, sizeof(char *));
		i++;
	}
	return (visited);
}

void	free_2d_array(int board_length, char **board)
{
	int	i;

	i = 0;
	while (i < board_length)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
