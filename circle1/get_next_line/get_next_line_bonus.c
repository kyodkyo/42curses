/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:37:10 by dakang            #+#    #+#             */
/*   Updated: 2024/01/15 21:54:16 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_buffer(int fd, ssize_t *read_size, char **prev)
{
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];

	while (ft_strchr(*prev) == -1)
	{
		*read_size = read(fd, buffer, BUFFER_SIZE);
		if (*read_size == -1)
		{
			free(*prev);
			*prev = NULL;
			return (1);
		}
		if (*read_size == 0)
			break ;
		buffer[*read_size] = 0;
		temp = *prev;
		*prev = ft_strjoin(temp, buffer);
		free(temp);
		if (!(*prev))
			return (1);
	}
	return (0);
}

int	make_line(char **prev, char **line)
{
	int		i;
	char	*temp;

	i = ft_strchr(*prev);
	if (i == -1)
		i = ft_strlen(*prev);
	*line = ft_substr(*prev, 0, i + 1);
	if (!(*line))
	{
		free(*prev);
		*prev = 0;
		return (1);
	}
	temp = *prev;
	*prev = ft_substr(temp, i + 1, ft_strlen(temp) - i - 1);
	if (!(*prev))
	{
		free(*line);
		free(temp);
		return (1);
	}
	else
		free(temp);
	return (0);
}

void	free_all(char **prev, char **line)
{
	free(*prev);
	*prev = NULL;
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		read_size;
	static char	*prev[OPEN_MAX];

	if (BUFFER_SIZE <= 0 && fd < 0)
		return (NULL);
	if (!prev[fd])
	{
		prev[fd] = ft_strdup("");
		if (!prev[fd])
			return (NULL);
	}
	if (read_buffer(fd, &read_size, &prev[fd]))
		return (NULL);
	if (make_line(&prev[fd], &line))
		return (NULL);
	if (read_size == 0 && *prev[fd] == '\0')
		free_all(&prev[fd], &line);
	return (line);
}
