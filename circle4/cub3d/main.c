/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:29:58 by dakang            #+#    #+#             */
/*   Updated: 2024/10/08 21:39:28 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		cub_error("argc error");
	if (check_file(argv[1]))
		cub_error("file error");
	init(&cub, argv[1]);
	make_map(&cub);
	execute(&cub);
}
