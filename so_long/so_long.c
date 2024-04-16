/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:22:41 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/16 17:32:25 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	check_input(argc, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit();
	initialize(&map);
	make_map(fd, &map);
	if (map->p_cnt != 1 || map->c_cnt != 1 || map->e_cnt != 1)
		error_exit();
	set_image(&map);
	return (0);
}
