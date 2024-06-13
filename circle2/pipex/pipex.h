/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:48:36 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/13 21:31:45 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char	**arg;
	char	*path;
}	t_cmd;

typedef struct s_info
{
	int		infile;
	int		outfile;
	char	**path;
	t_cmd	*cmds;
}	t_info;

/** etc.c */
void	error_exit(char *str);
void	free_2d_array(char **arr);
void	free_all(t_info *info);

/** ft_utils.c */
int		count_word(char const *s, char c);
char	*save_word(const char *s, int n);
char	**free_arr(char **list);
char	**ft_split(char const *s, char c);

/** info.c */
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*check_valid_access(char *cmd, char **path);
void	set_info(t_info *info, char **argv, char **envp);

/** process.c */
void	infile_process(t_info *info, int *fd);
void	outfile_process(t_info *info, int *fd);
void	parent_process(t_info *info, int *fd);
void	execute_pipex(t_cmd *cmd, t_info *info, char **envp, int i);

#endif