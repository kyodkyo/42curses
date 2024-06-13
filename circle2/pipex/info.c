/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:38:01 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/13 21:28:18 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (*s1)
	{
		str[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

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
	if (!access(cmd, X_OK))
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

void	set_info(t_info *info, char **argv, char **envp)
{
	int	i;

	info->infile = open(argv[1], O_RDONLY);
	info->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->infile < 0)
		error_exit("no such file or directory\n");
	if (info->outfile < 0)
		error_exit("outfile error\n");
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	info->path = ft_split(*envp + 5, ':');
	info->cmds = (t_cmd *)malloc(sizeof(t_cmd) * 3);
	if (!info->cmds)
		error_exit("malloc error\n");
	i = -1;
	while (++i < 2)
	{
		info->cmds[i].arg = ft_split(argv[i + 2], ' ');
		if (!info->cmds[i].arg)
			error_exit("split error\n");
	}
	info->cmds[i].arg = 0;
}
