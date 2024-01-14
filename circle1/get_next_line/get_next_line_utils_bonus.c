/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:39:12 by dakang            #+#    #+#             */
/*   Updated: 2024/01/14 17:52:59 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*get_fd(int fd, t_list *list)
{
	while (!list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, int buf_size)
{
	int		i;
	int		s1_len;
	char	*res;

	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2, buf_size));
	s1_len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (s1_len + buf_size + 1));
	if (res == NULL)
		return (NULL);
	while (*s1 != '\0')
		res[i++] = *s1++;
	while (*s2 != '\0')
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s1, int size)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] && i < size)
	{		
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	free_one(int fd, t_list **list)
{
	t_list	*temp;
	t_list	*head;

	if ((*list)->fd == fd)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
	else
	{
		head = *list;
		temp = get_fd(fd, *list);
		while ((*list)->next->fd != fd)
			*list = (*list)->next;
		(*list)->next = (*list)->next->next;
		free(temp);
		*list = head;
	}
}
