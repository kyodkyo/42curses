/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:30:26 by dakang            #+#    #+#             */
/*   Updated: 2024/10/12 16:06:44 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080

# define WALL_X 0
# define WALL_Y 1

# define MOVE_SPEED 0.1
# define ROTATION_SPEED 50

# define KEY_PRESS 2
# define KEY_EXIT 17

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_dir;

typedef struct s_dda
{
	int		dir;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		wall_height;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
}	t_dda;

typedef struct s_raycast
{
	int		start;
	int		end;
	int		color;
	int		tex_x;
	int		tex_y;
	int		tex_dir;
	double	step;
	double	tex_pos;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_image
{
	void	*init;
	char	*path;
	int		*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_color
{
	int				ceil[3];
	int				ceil_flag;
	unsigned int	c_color;
	int				floor[3];
	int				floor_flag;
	unsigned int	f_color;
}	t_color;

typedef struct s_cub
{
	int			fd;
	char		*map;
	char		**map_arr;
	void		*mlx;
	void		*window;
	int			player_num;
	int			**buf;
	int			map_width;
	int			map_height;
	t_player	*player;
	t_image		*image;
	t_image		img[4];
	t_color		*color;
}	t_cub;

/** parse */
void	check_color(char *line, int *count, t_cub *cub);
void	check_dir(char *line, int *count, t_cub *cub);
void	init(t_cub *cub, char *file);
void	cub_error(char *str);
int		free_arr(char **str, int flag);
int		check_file(char *str);
void	dir_color_check(char *line, int *count, t_cub *cub);
void	valid_map_check(char *line, char **map, t_cub *cub);
void	check_map(t_cub *cub);
int		is_only_space(char *line);
void	is_valid_wall(char **map);
void	make_map(t_cub *cub);
void	check_map(t_cub *cub);

/** execute */
void	execute(t_cub *cub);
void	init_dda_ray(t_cub *cub, t_dda *dda, t_ray *ray, int i);
void	run_dda(t_cub *cub, t_dda *dda);
void	set_texture_dir(int side, t_ray *ray);
void	calc_wall_size(t_dda *dda, t_ray *ray);
void	calc_texture_x(t_cub *cub, t_dda *dda, t_ray *ray);
void	calc_texture_y(t_cub *cub, t_dda *dda, t_ray ray, int i);
int		close_window(t_cub *cub);
int		play_game(int keycode, t_cub *cub);

#endif