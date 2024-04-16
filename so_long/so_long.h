/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:23:00 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/16 21:52:04 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define KEY_ESC	53
# define KEY_PRESS	2
# define KEY_EXIT	17

# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2

typedef struct s_map {
	void	*mlx_ptr;
	char	**board;
	char	**dfs_board;
	int		board_width;
	int		board_height;
	void	*win;
	void	*character;
	void	*obstacle;
	void	*background;
	void	*item;
	void	*wall;
	void	*exit_door;
	int		image_width;
	int		img_height;
	int		c_cnt;
	int		e_cnt;
	int		e_pos;
	int		p_cnt;
	int		p_pos;
	int		x;
	int		y;
	int		items;
	int		item_flag;
	int		exit_flag;
	int		exit_locate[2];
	int		move_cnt;
}	t_map;

/** check_valid.c */
void	check_input(int argc, char *argv);
int		line_count(char *line);
void	check_len(int len, t_map *map);
int		check_total(int len, char *line, t_map *map);

/** etc.c */
void	error_exit(void);
void	free_arr(char **arr);

/** ft_utils.c */
void	*ft_bzero(void *map, size_t len);

/** get_next_line_utils.c*/
int		ft_strlen(char const *str);
int		ft_strchr(char const *str);
char	*ft_strdup(char const *str);
char	*ft_strjoin(char *temp, char const *buffer);
char	*ft_substr(char const *str, int start, int end);

/** get_next_line.c */
int		update_buffer(int fd, ssize_t *read_size, char **prev);
int		make_line(char **prev, char **line);
void	free_all(char **prev, char **line);
char	*get_next_line(int fd);

/** setting_map.c */
void	initialize(t_map *map);
void	*make_map(int fd, t_map *map);
void	set_image(t_map *map);

#endif