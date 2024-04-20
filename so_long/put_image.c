/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:44:05 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/21 03:22:49 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window_floor(t_map *board)
{
	mlx_put_image_to_window(board->mlx, board->win, board->floor,
		board->win_x, board->win_y);
}

void	put_image_to_window_tree(t_map *board)
{
	put_image_to_window_floor(board);
	mlx_put_image_to_window(board->mlx, board->win, board->tree,
		board->win_x, board->win_y);
}

void	put_image_to_window_seed(t_map *board)
{
	put_image_to_window_floor(board);
	mlx_put_image_to_window(board->mlx, board->win, board->seed,
		board->win_x, board->win_y);
}

void	put_image_to_window_house(t_map *board)
{
	put_image_to_window_floor(board);
	mlx_put_image_to_window(board->mlx, board->win, board->house,
		board->win_x, board->win_y);
}

void	put_image_to_window_racoon(t_map *board, int i, int j)
{
	put_image_to_window_floor(board);
	mlx_put_image_to_window(board->mlx, board->win, board->racoon,
		board->win_x, board->win_y);
	board->now_x = j;
	board->now_y = i;
}
