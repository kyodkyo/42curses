/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:13:22 by dakang            #+#    #+#             */
/*   Updated: 2024/01/14 17:52:46 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_node(int fd, t_list **list)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (-1);
	new->fd = fd;
	new->end_of_file = 0;
	new->prev = NULL;
	new->next = *list;
	*list = new;
	return (1);
}

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

void	make_after_nl(t_list *list)
{
	char	*temp;
	int		i;
	int		len;

	i = find_new_line(list->prev);
	len = ft_strlen(list->prev);
	if ((list->prev)[i + 1] != '\0')
		temp = ft_strdup(list->prev + i + 1, len - i);
	else
		temp = NULL;
	free(list->prev);
	list->prev = temp;
}

char	*read_buffer(int fd, t_list *list)
{
	char	buffer[BUFFER_SIZE];
	int		read_size;

	if (list->end_of_file == 1)
	{
		free(list->prev);
		return (NULL);
	}
	if (find_new_line(list->prev) != -1)
		make_after_nl(list);
	while (find_new_line(list->prev) == -1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size > 0)
			list->prev = ft_strjoin(list->prev, buffer, read_size);
		if (read_size < BUFFER_SIZE && find_new_line(list->prev) == -1)
		{
			list->end_of_file = 1;
			break ;
		}
	}
	return (list->prev);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*buffer;

	if (get_fd(fd, list) == NULL)
	{
		if (get_next_node(fd, &list) == -1)
			return (NULL);
	}
	buffer = read_buffer(fd, get_fd(fd, list));
	if (buffer == NULL)
	{
		free_one(fd, &list);
		return (NULL);
	}
	if (buffer != NULL && find_new_line(buffer) != -1)
		return (ft_strdup(buffer, find_new_line(buffer) + 1));
	return (ft_strdup(buffer, find_new_line(buffer)));
}
