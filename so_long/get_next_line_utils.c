/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:27:17 by dakang            #+#    #+#             */
/*   Updated: 2024/04/20 14:16:15 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
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

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	i;
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
