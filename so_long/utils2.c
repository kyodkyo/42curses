/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:16:48 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/21 01:24:37 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			ptr[j] = ft_word_dup(&s[i], c);
			if (!ptr[j++])
				return (ft_split_free(ptr, j - 2));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	ptr[j] = 0;
	return (ptr);
}

void	*ft_split_free(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
	return (0);
}

int	cnt_word(const char *s, char c)
{
	int	word;

	word = 0;
	if (!s)
		error_exit('o');
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			word++;
		while (*s && *s != c)
			s++;
	}
	return (word);
}

char	*ft_word_dup(const char *src, char c)
{
	int		i;
	char	*dst;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
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
