/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:07:04 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/29 22:45:25 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_double_new_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] && map[i] == '\n')
			if (map[i + 1] && map[i + 1] == '\n')
				cub_error("double new line error");
		i++;
	}
}

int	is_null_space(char c)
{
	if (c == '\0' || c == ' ')
		return (1);
	return (0);
}

void	is_valid_surround(int i, int j, char **map)
{
	if (map[i - 1])
	{
		if (is_null_space(map[i - 1][j]) || is_null_space(map[i - 1][j - 1])
			|| is_null_space(map[i - 1][j + 1]))
			cub_error("invalid surround error");
	}
	else if (map[i])
	{
		if (is_null_space(map[i][j - 1]) || is_null_space(map[i][j + 1]))
			cub_error("invalid surround error");
	}
	else if (map[i + 1])
	{
		if (is_null_space(map[i + 1][j]) || is_null_space(map[i + 1][j - 1]) ||
			is_null_space(map[i + 1][j + 1]))
			cub_error("invalid surround error");
	}
}

void	is_valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				is_valid_surround(i, j, map);
			j++;
		}
		i++;
	}
}

void	check_map(t_cub *cub)
{
	int		i;
	long	f_line;

	if (cub->player_num != 1)
		cub_error("player must be one");
	f_line = 0;
	while (cub->map[f_line])
	{
		if (cub->map[f_line] != '\n')
			break ;
		f_line++;
	}
	check_double_new_line(cub->map + f_line);
	cub->map_arr = ft_split(cub->map, '\n');
	if (!cub->map_arr)
		cub_error("malloc error");
	is_valid_map(cub->map_arr);
	is_valid_wall(cub->map_arr);
	i = 0;
	while (cub->map_arr[i])
		i++;
	cub ->map_height = i;
	free(cub->map);
}
