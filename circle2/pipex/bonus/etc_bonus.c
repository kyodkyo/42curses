/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:32:19 by dakyo             #+#    #+#             */
/*   Updated: 2024/05/06 00:08:00 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
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

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		free_2d_arr(info->cmds[i].arg);
		i++;
	}
	free(info->cmds);
	free_2d_arr(info->path);
}
