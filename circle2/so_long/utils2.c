/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:16:48 by dakyo             #+#    #+#             */
/*   Updated: 2024/05/12 13:05:14 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*split_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (0);
}

int	count_word(char const *str, char c)
{
	int	count;

	if (!str)
		error_exit();
	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

char	*dup_word(char const *str, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (!res)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			res[j] = dup_word(&str[i], c);
			if (!res[j++])
				return (split_free(res, j - 2));
		}
		while (str[i] && str[i] != c)
			i++;
	}
	res[j] = 0;
	return (res);
}

void	ft_putnbr(int n)
{
	if (!n)
	{
		write(1, "0", 1);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	n += '0';
	write(1, &n, 1);
}
