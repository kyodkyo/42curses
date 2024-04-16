/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:23:00 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/16 16:30:55 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./mlx/mlx.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_map {
	char **board;
	char **dfs_board;
	int row;
	int col;
	int c_cnt;
	int e_cnt;
	int e_pos;
	int p_cnt;
	int p_pos;
	char	**map;
}	t_map;

/** check_valid.c */
void	check_input(int argc, char *argv);

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
int		line_count(char *line);
void	check_len(int len, t_map *map);
int		check_total(int len, char *line, t_map *map);
void	*make_map(int fd, t_map *map);
void	initialize(t_map *map);

#endif