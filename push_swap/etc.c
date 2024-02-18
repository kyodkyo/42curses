/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:56:07 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 20:07:48 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_arr(int argc, char **arr, char *res)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(res);
}
