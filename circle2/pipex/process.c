/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:23:16 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/13 21:47:28 by dakyo            ###   ########.fr       */
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

void	execute_pipex(t_cmd *cmd, t_info *info, char **envp, int i)
{
	int		fd[2];
	pid_t	pid;

	while (++i < 2)
	{
		if (pipe(fd) < 0)
			error_exit("pipe error\n");
		pid = fork();
		if (pid == -1)
			error_exit("fork error\n");
		else if (pid == 0)
		{
			if (i == 0)
				infile_process(info, fd);
			else
				outfile_process(info, fd);
			execve(check_valid_access(*info->cmds[i].arg, info->path),
				info->cmds[i].arg, envp);
		}
		else
			parent_process(info, fd);
	}
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}
