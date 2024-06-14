/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:07:50 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/14 16:09:27 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_cmd
{
	char	**arg;
	char	*path;
}	t_cmd;

typedef struct s_info
{
	int		infile;
	int		outfile;
	int		heredoc;
	int		fd[2];
	char	**path;
	t_cmd	*cmds;
	pid_t	pid;
}	t_info;

/** etc_bonus.c */
void	error_exit(char *str);
void	free_2d_arr(char **arr);
void	free_info(t_info *info, int argc);

/** ft_utils_bonus.c */
int		ft_strncmp_gnl(const char *s1, const char *s2, int n);
int		count_word(char const *s, char c);
char	*save_word(const char *s, int n);
char	**free_arr(char **list);
char	**ft_split(char const *s, char c);

/** get_next_line_utils.c */
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

/** info_bonus.c */
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*check_valid_access(char *cmd, char **path);
void	input_until_tag(t_info *info, char *tag);
void	set_info2(t_info *info, int argc, char **argv);
void	set_info(t_info *info, int argc, char **argv, char **envp);

/** process_bonus.c */
void	infile_process(t_info *info, int *fd);
void	outfile_process(t_info *info, int *fd);
void	middle_process(int *fd);
void	parent_process(int *fd);
void	wait_process(void);
void	execute_pipex(t_info *info, int argc, char **envp);

#endif