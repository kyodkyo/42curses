/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:44:32 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/30 00:17:17 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_2d_array(char **arr)
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

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		free_2d_array(info->cmds[i].arg);
		i++;
	}
	free_2d_array(info->path);
}
