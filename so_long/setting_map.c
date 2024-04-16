/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:02:08 by dakang            #+#    #+#             */
/*   Updated: 2024/04/16 22:06:36 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    initialize(t_map *map)
{
	// map 초기화
}

void	*make_map(int fd, t_map *map)
{
	int		len;
	char	*line;
	char	*total;

	line = NULL;
	total = NULL;
	ft_bzero(&map, sizeof(t_map)); //수정 필요
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len = line_count(line);
		map->board_height++;
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

void	set_image(t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->win = mlx_new_window(map->mlx_ptr, \
			map->board_width * 64, map->board_height * 64, "my_mlx");
	image_to_board(map);
}

void	image_to_board(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->board[i])
	{
		j = 0;
		while (map->board[i][j])
		{
			// 캐릭터 확인해서 이미지 뿌리기
			// 가장 바깥줄들 벽인지 확인하기
			j++;
		}
		i++;
	}
}
