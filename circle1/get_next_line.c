/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:43:17 by dakang            #+#    #+#             */
/*   Updated: 2023/11/03 21:18:35 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_buffer(int fd, char *buffer)
{
	ssize_t	size;

	size = read(fd, buffer, BUFFER_SIZE);
	if (size < 0)
	{
		free(buffer);
		return (-1);
	}
	buffer[size] = '\0';
	return (size);
}

char	*find_line(char **result, char buffer)
{
	int		i;
	int		count;
	char	*temp;
	char	*cut_line;

	i = -1;
	count = 1;
	temp = *result;
	while (*result[++i] != '\n')
		count++;
	cut_line = (char *)malloc(sizeof(char) * (count + 1));
	if (cut_line == NULL)
		return (NULL);
	cut_line[count] = '\n';
	while (--count >= 0)
		cut_line[count] = *result[count];
	*result = ft_strchr(*result, '\n'); //????ㅇㅣ러ㅎ게만 해도 되나
	if (*result == 0)
		return (0);
	free(temp);
	free(buffer);
	return (cut_line);
}

char	*file_end(char **result, char *buffer)
{
	char	*file_data;

	free(buffer);
	file_data = *result;
	*result = 0;
	return (file_data);
}

char	*get_next_line(int fd)
{
	ssize_t		buf_size;
	char		*buffer;
	char		*temp;
	static char	*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	temp = ft_strchr(result, '\n');
	while (temp != 0)
	{
		buf_size = read_buffer(fd, buffer);
		if (buf_size == -1)
			return (0);
		result = ft_strjoin(result, buffer);
		if (result == 0)
			return (0);
		if (buf_size == 0)
			return (file_end(&result, buffer));
		temp = ft_strchr(result, '\n');
	}
	return (find_line(&result, buffer));
}
/*
파일이 끝나거나, 개행을 찾거나 둘 중 하나
acc
asddd
size = 5?
윗줄만 반환하고 a는 정적변수에 담아두고 이후 gnl이 다시 호출되었을 때 사용됨
free
*/