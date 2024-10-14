/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:46:31 by dakang            #+#    #+#             */
/*   Updated: 2024/09/29 16:06:12 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(const char *string)
{
	int		i;
	int		count;
	char	*res;

	i = 0;
	count = ft_strlen(string);
	res = (char *)malloc(count * sizeof(char) + 1);
	if (!res)
		return (0);
	while (string[i])
	{
		res[i] = string[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
