/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:38 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/14 16:09:16 by dakyo            ###   ########.fr       */
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

void	parent_process(int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
}

void	execute_pipex(t_info *info, int argc, char **envp)
{
	int	i;

	i = -1;
	while (++i < argc - 3 - info->heredoc)
	{
		if (pipe(info->fd) < 0)
			error_exit("pipe error\n");
		info->pid = fork();
		if (info->pid == -1)
			error_exit("fork error\n");
		else if (info->pid == 0)
		{
			if (i == 0)
				infile_process(info, info->fd);
			else if (i == argc - 4 - info->heredoc)
				outfile_process(info, info->fd);
			else
				middle_process(info->fd);
			execve(check_valid_access(*info->cmds[i].arg, info->path),
				info->cmds[i].arg, envp);
		}
		else
			parent_process(info->fd);
	}
	wait_process();
}
