/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:23:00 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/19 21:36:20 by dakyo            ###   ########.fr       */
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
	void	*mlx;
	char	**board;
	char	**dfs_board;
	int		board_width;
	int		board_height;
	void	*win;
	int		win_x;
	int		win_y;
	int		img_width;
	int		img_height;
	int		now_x;
	int		now_y;
	void	*racoon;
	void	*tree;
	void	*floor;
	void	*seed;
	void	*house;
	int		c_cnt;
	int		e_cnt;
	int		p_cnt;
	int		items;
	int		item_flag;
	int		exit_flag;
	int		exit_pos_x;
	int		exit_pos_y;
	int		move_cnt;
}	t_map;

/** check_valid.c */
int		check_input(int argc, char *argv);
void	check_board(t_map *map);
void	check_board_rec(t_map *map);
void	check_path(t_map *map);
void	dfs(t_map *map, int y, int x);

/** setting_map.c */
void	make_map(int fd, t_map *map);
void	set_image(t_map *map);
void	image_to_board(t_map *map);
void	put_image_to_window(t_map *map, int i, int j);
void	check_wall(t_map *map);

/** key_press.c */
int		key_press(int code, t_map *map);
void	move_racoon(t_map *map, int x, int y);
int		finish_game(t_map *map);

/** put_image.c */
void	put_image_to_window_floor(t_map *board);
void	put_image_to_window_tree(t_map *board);
void	put_image_to_window_seed(t_map *board);
void	put_image_to_window_house(t_map *board);
void	put_image_to_window_racoon(t_map *board, int i, int j);

/** utils.c */
void	error_exit(void);
void	*initialize(void *arr, int value, size_t len);
char	**ft_split(char const *s, char c);
void	*ft_split_free(char **ptr, int i);
int		cnt_word(const char *s, char c);
char	*ft_word_dup(const char *src, char c);
void	ft_putnbr(int n);

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

#endif