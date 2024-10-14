/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:59:04 by dakyo             #+#    #+#             */
/*   Updated: 2024/10/08 20:17:33 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_buf(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	cub->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	while (i < HEIGHT)
	{
		cub->buf[i] = (int *)malloc(sizeof(int) * WIDTH);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			cub->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

char	set_player(int i, int j, char pos, t_cub *cub)
{
	cub->player->pos_x = i + 0.5;
	cub->player->pos_y = j + 0.5;
	if (pos == 'N')
	{
		cub->player->dir_x = -1;
		cub->player->plane_y = 0.66;
	}
	else if (pos == 'S')
	{
		cub->player->dir_x = 1;
		cub->player->plane_y = -0.66;
	}
	else if (pos == 'E')
	{
		cub->player->dir_y = 1;
		cub->player->plane_x = 0.66;
	}
	else if (pos == 'W')
	{
		cub->player->dir_y = -1;
		cub->player->plane_x = -0.66;
	}
	else
		return (0);
	return (1);
}

void	init_player(t_cub *cub)
{
	int	i;
	int	j;

	cub->player->dir_x = 0;
	cub->player->dir_y = 0;
	cub->player->plane_x = 0;
	cub->player->plane_y = 0;
	i = 0;
	while (cub->map_arr[i])
	{
		j = 0;
		while (cub->map_arr[i][j])
		{
			if (set_player(i, j, cub->map_arr[i][j], cub))
				return ;
			j++;
		}
		i++;
	}
}

void	make_map(t_cub *cub)
{
	init_buf(cub);
	init_player(cub);
	cub->color->c_color = (cub->color->ceil[0] << 16)
		| (cub->color->ceil[1] << 8) | cub->color->ceil[2];
	cub->color->f_color = (cub->color->floor[0] << 16)
		| (cub->color->floor[1] << 8) | cub->color->floor[2];
	cub->window = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3d");
	cub->image->init = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->image->data = (int *)mlx_get_data_addr(
			cub->image->init, &(cub->image->bits_per_pixel),
			&(cub->image->size_line), &(cub->image->endian));
}
