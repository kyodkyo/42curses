/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:48:12 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/14 16:17:22 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc != 5)
		error_exit("argc error\n");
	set_info(&info, argv, envp);
	execute_pipex(&info, envp, -1);
	free_all(&info);
}
