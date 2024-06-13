/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:32:19 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/13 21:00:26 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	unlink("/tmp/.infile");
	exit(1);
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_info(t_info *info, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3 - info->heredoc)
	{
		free_2d_arr(info->cmds[i].arg);
		free(info->cmds[i].path);
		i++;
	}
	free(info->cmds);
	free_2d_arr(info->path);
}
