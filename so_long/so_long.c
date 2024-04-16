/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:22:41 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/15 23:51:13 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int fd;
	t_map map;

	fd = check_input(argc, argv[1]);
	initialize(fd, &map, sizeof(t_map));


	return (0);
}
void *initialize(int fd, void *map, size_t len)
{
	char *line;
	char *total_line;
	char *temp;
	
	total_line = NULL;
	ft_bzero(&map, sizeof(t_map));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		
	}
	map_init(fd, &map);
}
