/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:48:12 by dakyo             #+#    #+#             */
/*   Updated: 2024/05/19 17:43:15 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_cmd	cmd;
	t_info	info;

	if (argc != 5)
		error_exit();
	set_info(&info, argv, envp);
	i = 0;
	while (i < 2)
	{
		pipe_process(&info, i);
		i++;
	}
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	free_all(&info);
}
