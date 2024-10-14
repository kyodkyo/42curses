/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:40:09 by dakyo             #+#    #+#             */
/*   Updated: 2024/10/08 17:36:09 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	init_side_dist(t_cub *cub, t_dda *dda, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (cub->player->pos_x - dda->map_x)
			* dda->delta_dist_x;
	}
	else
		dda->side_dist_x = (dda->map_x + 1.0 - cub->player->pos_x)
			* dda->delta_dist_x;
	if (ray->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (cub->player->pos_y - dda->map_y)
			* dda->delta_dist_y;
	}
	else
		dda->side_dist_y = (dda->map_y + 1.0 - cub->player->pos_y)
			* dda->delta_dist_y;
}

void	init_dda_ray(t_cub *cub, t_dda *dda, t_ray *ray, int i)
{
	double	cam;

	cam = 2 * i / (double)WIDTH - 1;
	ray->ray_dir_x = cub->player->dir_x + cub->player->plane_x * cam;
	ray->ray_dir_y = cub->player->dir_y + cub->player->plane_y * cam;
	dda->map_x = (int)(cub->player->pos_x);
	dda->map_y = (int)(cub->player->pos_y);
	if (ray->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = ft_abs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = ft_abs(1 / ray->ray_dir_y);
	dda->step_x = 1;
	dda->step_y = 1;
	init_side_dist(cub, dda, ray);
}

bool	check_wall_hit(t_cub *cub, t_dda *dda)
{
	bool	hit;
	char	pixel;

	hit = false;
	pixel = cub->map_arr[dda->map_x][dda->map_y];
	if (dda->map_x >= 0 && dda->map_y >= 0 && pixel == '1')
		hit = true;
	return (hit);
}

void	run_dda(t_cub *cub, t_dda *dda)
{
	bool	hit;

	hit = false;
	while (hit == false)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = WALL_X;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = WALL_Y;
		}
		hit = check_wall_hit(cub, dda);
	}
}
