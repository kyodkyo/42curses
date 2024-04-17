/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:44:48 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/17 21:04:10 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image_to_window_floor (t_map *map)
{
    mlx_put_image_to_window(map->mlx, map->win, map->floor, map->x, map->y);
}

void put_image_to_window_tree (t_map *map)
{
    
}

void put_image_to_window_seed (t_map *map)
{
    
}

void put_image_to_window_house (t_map *map)
{
    
}

void put_image_to_window_racoon (t_map *map)
{
    
}