/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:34:11 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/14 16:08:30 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*check_valid_access(char *cmd, char **path)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*n_path;

	i = 0;
	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	n_path = ft_strjoin("/", cmd);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], n_path);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(n_path);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free(n_path);
	error_exit("cmd error\n");
	return (NULL);
}

void	input_until_tag(t_info *info, char *tag)
{
	int		len;
	char	*tmp;

	len = ft_strlen(tag);
	info->infile = open("/tmp/.infile", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	while (1)
	{
		write(1, ">> ", 3);
		tmp = get_next_line(0);
		if (!ft_strncmp_gnl(tmp, tag, len))
			break ;
		write(info->infile, tmp, ft_strlen(tmp));
		free(tmp);
	}
	if (tmp)
		free(tmp);
	close(info->infile);
	info->infile = open("/tmp/.infile", O_RDONLY, 0644);
}

void	set_info2(t_info *info, int argc, char **argv)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = info->heredoc;
	size = argc - 2 - info->heredoc;
	info->cmds = (t_cmd *)malloc(sizeof(t_cmd) * size);
	if (!info->cmds)
		error_exit("malloc error\n");
	while (j < argc - 3)
	{
		info->cmds[i].arg = ft_split(argv[j + 2], ' ');
		if (!info->cmds[i].arg)
			error_exit("split error\n");
		i++;
		j++;
	}
	info->cmds[i].arg = 0;
}

void	set_info(t_info *info, int argc, char **argv, char **envp)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		info->heredoc = 1;
		info->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		info->heredoc = 0;
		info->infile = open(argv[1], O_RDONLY);
		info->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (info->infile == -1)
			error_exit("no such file or directory\n");
	}
	if (info->outfile == -1)
		error_exit("outfile error\n");
	if (info->heredoc)
		input_until_tag(info, argv[2]);
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	info->path = ft_split(*envp + 5, ':');
	set_info2(info, argc, argv);
}
