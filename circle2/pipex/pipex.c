/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:48:12 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/29 01:35:01 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_valid_access(char *cmd, char **path)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*n_path;

	i = 0;
	fd = access(cmd, X_OK);
	if (fd == -1)
		return (cmd);
	n_path = ft_strjoin('/', cmd);
	while (path[i])
	{

	}
	free(n_path);
	return (NULL);
}

void	set_data(t_data *data, char **argv, char **envp)
{
	data->infile = open(argv[1], O_RDONLY);
	data->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->infile == -1 || data->outfile == -1)
		error_exit();
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	data->path = ft_split(*envp + 5, ':');
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd1_path = check_valid_access(data->cmd1, data->path);
	data->cmd2 = ft_split(argv[3], ' ');
	data->cmd2_path = check_valid_access(data->cmd2, data->path);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		error_exit();
	set_data(&data, argv, envp);
}


