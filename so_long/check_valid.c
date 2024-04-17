/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:33:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/17 20:57:19 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char *argv)
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
}

int	line_count(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

void	check_len(int len, t_map *map)
{
	if (map->board_width == 0)
		map->board_width = len;
	if (map->board_width != len)
		error_exit();
}

int	check_total(int len, char *line, t_map *map)
{
	int	i;

	i = 0;
	check_len(len, map);
	while (i < len)
	{
		if (line[i] == 'C')
			map->c_cnt++;
		else if (line[i] == 'E')
		{
			map->e_cnt++;
			map->e_pos = ((map->board_height - 1) * len) + i;
		}
		else if (line[i] == 'P')
		{
			map->p_cnt++;
			map->p_pos = ((map->board_height - 1) * len) + i;
		}
		else if (line[i] == '0' || line[i] == '1')
			continue ;
		else
			error_exit();
		i++;
	}
	return (1);
}
