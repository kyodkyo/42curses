/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:33:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/15 21:53:56 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	if (argc != 2)
		error_exit();
	while (argv[i])
		i++;
	if (argv[i-4] != '.' || argv[i-3] != 'b')
		error_exit();
	if (argv[i-2] != 'e' || argv[i-1] != 'r')
		error_exit();
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit();
	return (fd);
}
