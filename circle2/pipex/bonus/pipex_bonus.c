/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:06:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/05/06 00:07:22 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_cmd	cmd;
	t_info	info;

	if (argc < 6)
		error_exit();
	set_info(&info, argc, argv, envp);
	i = 0;
	while (i < argc - 3 - info.heredoc)
	{
		pipe_process(&info, i, argc);
		i++;
	}
	while (wait(0) != -1)
		;
	free_info(&info);
}
