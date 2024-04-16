/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:59:10 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/16 15:33:39 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_bzero(void *map, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)map;
	while (i < len)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
