/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:54:08 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/30 00:18:21 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_cub(t_cub *cub, char *file)
{
	int	i;

	cub->fd = open(file, O_RDONLY);
	if (cub->fd < 0)
		cub_error("file open error");
	cub->map = NULL;
	cub->map_arr = NULL;
	cub->player_num = 0;
	cub->player = (t_player *)malloc(sizeof(t_player));
	cub->image = (t_image *)malloc(sizeof(t_image));
	cub->color = (t_color *)malloc(sizeof(t_color));
	if (!cub->player || !cub->image || !cub->color)
		cub_error("malloc error");
	cub->map_width = 0;
	cub->map_height = 0;
	cub->color->ceil_flag = 0;
	cub->color->floor_flag = 0;
	i = 0;
	while (i < 4)
	{
		cub->img[i].init = NULL;
		cub->img[i].path = NULL;
		cub->img[i].data = NULL;
		i++;
	}
}

void	save_map(t_cub *cub)
{
	int		count;
	char	*line;

	count = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(cub->fd);
		if (!line)
			break ;
		if (count < 6)
			dir_color_check(line, &count, cub);
		else
			valid_map_check(line, &cub->map, cub);
		free(line);
		line = NULL;
	}
	close(cub->fd);
	free(line);
}

void	check_dir_dup(t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp[5];

	i = -1;
	tmp[0] = cub->img[NORTH].path;
	tmp[1] = cub->img[SOUTH].path;
	tmp[2] = cub->img[WEST].path;
	tmp[3] = cub->img[EAST].path;
	tmp[4] = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				continue ;
			else
			{
				if (!(ft_strncmp(tmp[i], tmp[j], ft_strlen(tmp[j]))))
					cub_error("direction dup error");
			}
		}
	}
}

void	check_color_dup(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (cub->color->ceil[i] != cub->color->floor[i])
			return ;
		i++;
	}
	cub_error("color dupicate error");
}

void	init(t_cub *cub, char *file)
{
	init_cub(cub, file);
	cub->mlx = mlx_init();
	if (!cub->mlx)
		cub_error("mlx init error");
	save_map(cub);
	if (!cub->map)
		cub_error("map error");
	check_map(cub);
	check_dir_dup(cub);
	check_color_dup(cub);
}
