/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:33:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/19 20:03:34 by dakyo            ###   ########.fr       */
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
