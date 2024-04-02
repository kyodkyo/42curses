/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_get_next_line_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:48:02 by dakang            #+#    #+#             */
/*   Updated: 2024/04/02 14:48:12 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char const *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *temp, char const *buffer)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	len = ft_strlen(temp) + ft_strlen(buffer);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (*temp)
		res[i++] = *temp++;
	while (*buffer)
		res[i++] = *buffer++;
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *str, int start, int end)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	if (str == NULL)
	{
		res = ft_strdup("");
		if (res == NULL)
			return (NULL);
		return (res);
	}
	if (len <= end || len - start < end)
		end = len - start;
	res = (char *)malloc(sizeof(char) * (end + 1));
	if (res == NULL)
		return (NULL);
	while (i < end && start + i < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
