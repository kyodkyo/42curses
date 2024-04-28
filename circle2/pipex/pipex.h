/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:48:36 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/29 01:25:23 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_data
{
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	char	**path;
	char	*cmd1;
	char	*cmd1_path;
	char	*cmd2;
	char	*cmd2_path;
	pid_t	pid;
}	t_data;

/** etc.c */
void	error_exit(void);

#endif