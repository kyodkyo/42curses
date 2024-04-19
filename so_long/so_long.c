/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:22:41 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/19 19:58:43 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = check_input(argc, argv[1]);
	initialize(&map, 0, sizeof(t_map));
	make_map(fd, &map);
	check_board(&map);
	set_image(&map);
	image_to_board(&map);
	// mlx_hook(map.win, KEY_PRESS, 0, &press_key, &map);
	// mlx_hook(map.win, 17, 0, &finish_game, &map);
	// mlx_loop(map.win);
	return (0);
}


// #include "./mlx/mlx.h"

// int main()
// {
// 	void *mlx;
// 	void *win;
// 	void *img;
// 	void *img2;
// 	void *img3;
// 	void *img4;
// 	void *img5;
// 	int img_width;
// 	int img_height;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "my_mlx");
// 	img = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm", &img_width, &img_height);
// 	// img2 = mlx_xpm_file_to_image(mlx, "./textures/house.xpm", &img_width, &img_height);
// 	img3 = mlx_xpm_file_to_image(mlx, "./textures/racoon.xpm", &img_width, &img_height);
// 	img4 = mlx_xpm_file_to_image(mlx, "./textures/seed.xpm", &img_width, &img_height);
// 	img5 = mlx_xpm_file_to_image(mlx, "./textures/tree.xpm", &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, win, img, 0, 0);
// 	// mlx_put_image_to_window(mlx, win, img2, 64, 0);
// 	mlx_put_image_to_window(mlx, win, img3, 128, 0);
// 	mlx_put_image_to_window(mlx, win, img4, 192, 64);
// 	mlx_put_image_to_window(mlx, win, img5, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }
