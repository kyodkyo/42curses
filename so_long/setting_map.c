/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:02:08 by dakang            #+#    #+#             */
/*   Updated: 2024/04/16 16:32:13 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (map->col == 0)
		map->col = len;
	if (map->col != len)
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
			map->e_pos = ((map->row - 1) * len) + i;
		}
		else if (line[i] == 'P')
		{
			map->p_cnt++;
			map->p_pos = ((map->row - 1) * len) + i;
		}
		else if (line[i] == '0' || line[i] == '1')
			continue ;
		else
			error_exit();
		i++;
	}
	return (1);
}

void	*make_map(int fd, t_map *map)
{
	int		len;
	char	*line;
	char	*total;

	line = NULL;
	total = NULL;
	ft_bzero(&map, sizeof(t_map));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len = line_count(line);
		map->row++;
		if (check_total(len, line, map) == 1)
			total = ft_strjoin(line, total);
		else
		{
			free_arr(total);
			break ;
		}
	}
	free(line);
	return (total);
}

void    initialize(t_map *map)
{
    // map 초기화
}
