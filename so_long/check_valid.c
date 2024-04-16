/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:33:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/16 17:21:52 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	if (argc != 2)
		error_exit();
	while (argv[i])
		i++;
	if (argv[i - 4] != '.' || argv[i - 3] != 'b' 
		|| argv[i - 2] != 'e' || argv[i - 1] != 'r')
		error_exit();
}
