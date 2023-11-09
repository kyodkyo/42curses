/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:09:28 by dakyo             #+#    #+#             */
/*   Updated: 2023/11/09 14:22:23 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int find_position(char *s)
{
	int s_len;
	int index;
	
	s_len = 0;
	index = -1;
	while (s[s_len])
		s_len++;
	while (++index < s_len)
	{
		if (s[index] == '\n')
			return (index);
	}
	return(-1);
}

char *find_new_line(char **total_line, char *buffer)
{
	char	*result;
	char	*temp;
	int		new_line_point;

	result = NULL;
	if (find_position(*total_line) == -1)
	{
		if (*total_line[0] != '\0')
			result = ft_strdup(*total_line, ft_strlen(*total_line));
		free(*total_line);
		*total_line = NULL;
	}
	else
	{
		result = ft_strdup(*total_line, find_position(*total_line) + 1);
		new_line_point = ft_strlen(*total_line + find_position(*total_line) + 1);
		temp = ft_strdup((*total_line + find_position(*total_line) + 1), new_line_point);
		free(*total_line);
		*total_line = temp;
	}
	free(buffer);
	return (result);
}

char	*read_buffer(int fd, char *buffer, char **total_line)
{
	ssize_t	read_size;
	char	*temp;

	buffer[BUFFER_SIZE] = '\0';
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		temp = ft_strjoin(*total_line, buffer);
		free(*total_line);
		*total_line = temp;
		if (find_position(*total_line) != -1)
			return (find_new_line(total_line, buffer));
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (find_new_line(total_line, buffer));
}

char	*get_next_line(int fd)
{
	static char	*total_line;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, buffer, BUFFER_SIZE) == -1)
	{        
		free(buffer);
		return (NULL);
	}
	if (total_line != NULL && find_position(total_line) != -1)
		return (find_new_line(&total_line, buffer));
	if (total_line == NULL)
	{
		total_line = (char *)malloc(sizeof(char) * 1);
		if (total_line == NULL)
			return (NULL);
		total_line[0] = '\0';
	}
	return (read_buffer(fd, buffer, &total_line));    
}
