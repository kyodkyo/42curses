/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:03:50 by dakang            #+#    #+#             */
/*   Updated: 2023/10/21 17:32:25 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			count++;
	}
	return (count);
}

char	*save_word(const char *s, int n)
{
	int		i;
	char	*res;

	i = -1;
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (++i < n)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

char	**free_all(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	words = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	while (i < words && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		temp = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		res[i] = save_word(&s[temp], j - temp);
		if (res[i++] == NULL)
			return (free_all(res));
	}
	res[i] = NULL;
	return (res);
}
