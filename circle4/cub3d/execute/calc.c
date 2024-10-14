/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:32:56 by dakyo             #+#    #+#             */
/*   Updated: 2024/10/12 16:55:30 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_texture_dir(int side, t_ray *ray)
{
	if (side == WALL_X)
	{
		ray->tex_dir = NORTH;
		if (ray->ray_dir_x > 0)
			ray->tex_dir = SOUTH;
	}
	if (side == WALL_Y)
	{
		ray->tex_dir = WEST;
		if (ray->ray_dir_y > 0)
			ray->tex_dir = EAST;
	}
}

void	calc_wall_size(t_dda *dda, t_ray *ray)
{
	if (dda->side == WALL_X)
		dda->perp_wall_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		dda->perp_wall_dist = dda->side_dist_y - dda->delta_dist_y;
	if (dda->perp_wall_dist == 0)
		dda->perp_wall_dist = 1e30;
	dda->wall_height = (int)((double)HEIGHT / dda->perp_wall_dist);
	ray->start = (-(dda->wall_height) / 2) + (HEIGHT / 2);
	ray->end = (dda->wall_height / 2) + (HEIGHT / 2);
	if (ray->start < 0)
		ray->start = 0;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
}

void	calc_texture_x(t_cub *cub, t_dda *dda, t_ray *ray)
{
	double	pos;

	if (dda->side == WALL_X)
		pos = cub->player->pos_y + dda->perp_wall_dist * ray->ray_dir_y;
	else
		pos = cub->player->pos_x + dda->perp_wall_dist * ray->ray_dir_x;
	pos -= floor(pos);
	ray->tex_x = (int)(pos * 64.0);
	if (dda->side == WALL_X && ray->ray_dir_x > 0)
		ray->tex_x = 64.0 - ray->tex_x - 1;
	if (dda->side == WALL_Y && ray->ray_dir_y < 0)
		ray->tex_x = 64.0 - ray->tex_x - 1;
}

void	calc_texture_y(t_cub *cub, t_dda *dda, t_ray ray, int i)
{
	int	j;

	ray.step = 1.0 * 64 / (double)dda->wall_height;
	ray.tex_pos = (ray.start - (double)HEIGHT / 2
			+ (double)dda->wall_height / 2) * ray.step;
	j = ray.start;
	while (j < ray.end)
	{
		ray.tex_y = (int)ray.tex_pos & 63;
		ray.tex_pos += ray.step;
		ray.color = cub->img[ray.tex_dir].data[64 * ray.tex_y + ray.tex_x];
		if (dda->side == WALL_Y)
			ray.color = (ray.color >> 1) & 8355711;
		cub->buf[j][i] = ray.color;
		j++;
	}
}
