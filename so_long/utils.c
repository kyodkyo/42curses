/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:00:28 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/19 20:04:00 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	*initialize(void *arr, int value, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)arr;
	i = 0;
	while (i < len)
		temp[i++] = value;
	return (temp);
}

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
