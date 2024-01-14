/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:48:11 by dakang            #+#    #+#             */
/*   Updated: 2024/01/14 17:37:19 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	find_new_line(char *total_line)
// {
// 	int	line_len;
// 	int	i;

// 	line_len = 0;
// 	i = 0;
// 	while (total_line[line_len])
// 		line_len++;
// 	while (i < line_len)
// 	{
// 		if (total_line[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

int	find_new_line(char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (-1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*make_result_line(char **total, char *buffer)
{
	char	*result;
	char	*temp;
	int		new_line_len;

	result = NULL;
	if (find_new_line(*total) == -1)
	{
		if (*total[0] != '\0')
			result = ft_strdup(*total, ft_strlen(*total));
		free(*total);
		*total = NULL;
	}
	else
	{
		result = ft_strdup(*total, find_new_line(*total) + 1);
		new_line_len = ft_strlen(*total + find_new_line(*total) + 1);
		temp = ft_strdup((*total + find_new_line(*total) + 1), new_line_len);
		free(*total);
		*total = temp;
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
		if (!temp)
		{
			free(temp);
			return (NULL);
		}
		free(*total_line);
		*total_line = temp;
		if (find_new_line(*total_line) != -1)
			return (make_result_line(total_line, buffer));
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (make_result_line(total_line, buffer));
}

char	*get_next_line(int fd)
{
	static char	*total_line;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		free(total_line);
		total_line = NULL;
		return (NULL);
	}
	if (total_line == NULL)
	{
		total_line = (char *)malloc(sizeof(char) * 1);
		if (total_line == NULL)
			return (NULL);
		total_line[0] = '\0';
	}
	if (total_line != NULL && find_new_line(total_line) != -1)
		return (make_result_line(&total_line, buffer));
	return (read_buffer(fd, buffer, &total_line));
}
