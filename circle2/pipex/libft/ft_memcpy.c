/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:36:54 by dakang            #+#    #+#             */
/*   Updated: 2023/10/21 22:59:31 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_temp;
	const unsigned char	*src_temp;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_temp = (unsigned char *)dest;
	src_temp = (const unsigned char *)src;
	i = -1;
	while (++i < len)
		dest_temp[i] = src_temp[i];
	return (dest);
}
