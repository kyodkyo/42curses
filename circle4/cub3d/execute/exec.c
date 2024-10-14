/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:53:31 by dakyo             #+#    #+#             */
/*   Updated: 2024/10/12 16:27:48 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_color(t_cub *cub)
{
	int	w;
	int	h;

	w = 0;
	while (w < WIDTH)
	{
		h = 0;
		while (h < HEIGHT / 2)
		{
			cub->buf[h][w] = cub->color->c_color;
			cub->buf[HEIGHT - h - 1][w] = cub->color->f_color;
			h++;
		}
		w++;
	}
}

void	raycasting(t_cub *cub)
{
	int		i;
	t_dda	dda;
	t_ray	ray;

	i = 0;
	while (i < WIDTH)
	{
		init_dda_ray(cub, &dda, &ray, i);
		run_dda(cub, &dda);
		set_texture_dir(dda.side, &ray);
		calc_wall_size(&dda, &ray);
		calc_texture_x(cub, &dda, &ray);
		calc_texture_y(cub, &dda, ray, i);
		i++;
	}
}

void	draw_cub(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cub->image->data[x + y * WIDTH] = cub->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image->init, 0, 0);
}

void	key_press(t_cub *cub)
{
	mlx_hook(cub->window, KEY_PRESS, 0, &play_game, cub);
	mlx_hook(cub->window, KEY_EXIT, 0, &close_window, cub);
}

void	execute(t_cub *cub)
{
	fill_color(cub);
	raycasting(cub);
	draw_cub(cub);
	key_press(cub);
	mlx_loop(cub->mlx);
}
