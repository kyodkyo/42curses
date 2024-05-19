/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:38 by dakyo             #+#    #+#             */
/*   Updated: 2024/05/19 17:04:08 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	infile_process(t_info *info, int *fd)
{
	close(fd[0]);
	dup2(info->infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(info->infile);
	close(fd[1]);
}

void	outfile_process(t_info *info, int *fd)
{
	close(fd[1]);
	dup2(info->outfile, STDOUT_FILENO);
	close(info->outfile);
}

void	middle_process(int *fd)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void	parent_process(t_info *info, int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
}

void	pipe_process(t_info *info, int i, int n)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		error_exit();
	pid = fork();
	if (pid == -1)
		error_exit();
	else if (pid == 0)
	{
		if (i == 0)
			infile_process(info, fd);
		else if (i == n - 4 - info->heredoc)
			outfile_process(info, fd);
		else
			middle_process(fd);
		if (execve(info->cmds[i].path, info->cmds[i].arg, NULL) < 0)
			error_exit();
	}
	else
		parent_process(info, fd);
}
