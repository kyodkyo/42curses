/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:18:10 by dakang            #+#    #+#             */
/*   Updated: 2024/09/27 12:52:27 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int s2_len, int s1_len)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
	{
		free(s1);
		return (0);
	}
	i = 0;
	while (i < s1_len)
	{
		tmp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		tmp[s1_len + i] = s2[i];
		i++;
	}
	tmp[s1_len + i] = '\0';
	free(s1);
	return (tmp);
}
