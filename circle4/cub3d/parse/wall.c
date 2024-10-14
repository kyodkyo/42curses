/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:42:44 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/29 22:43:19 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_top_bottom(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != ' ' && map[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_left_right(char *map)
{
	int	len;
	int	left_wall;

	len = ft_strlen(map);
	left_wall = 0;
	while (map[left_wall])
	{
		if (map[left_wall] == '1')
			break ;
		left_wall++;
	}
	if (map[left_wall] != '1' && map[len - 1] != '1')
		cub_error("left right wall error");
}

void	is_valid_wall(char **map)
{
	int	i;
	int	l_line;

	l_line = 0;
	while (map[l_line])
		l_line++;
	if (check_top_bottom(map[0]))
		cub_error("top wall error");
	if (check_top_bottom(map[l_line - 1]))
		cub_error("bottom wall error");
	i = 0;
	while (map[i])
	{
		if (is_only_space(map[i]))
			continue ;
		check_left_right(map[i]);
		i++;
	}
}
