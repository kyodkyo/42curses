/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:34:06 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/29 22:37:04 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cub_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int	free_arr(char **str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (flag);
}

int	is_only_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
