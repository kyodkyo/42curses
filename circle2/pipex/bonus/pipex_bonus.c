/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:06:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/14 16:17:28 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_process(void)
{
	while (wait(0) != -1)
		;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc < 5)
		error_exit("argc error\n");
	set_info(&info, argc, argv, envp);
	execute_pipex(&info, argc, envp);
	free_info(&info, argc);
	unlink("/tmp/.infile");
}
