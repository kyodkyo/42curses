/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:23:16 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/30 00:30:46 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	parent_process(t_info *info, int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void	pipe_process(t_info *info, int i)
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
		else
			outfile_process(info, fd);
		if (execve(info->cmds[i].path, info->cmds[i].arg, NULL) < 0)
			error_exit();
	}
	else
		parent_process(info, fd);
}
