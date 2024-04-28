/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:05:23 by dakang            #+#    #+#             */
/*   Updated: 2023/10/08 20:10:42 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		find;

	str = (unsigned char *)s;
	find = (unsigned char)c;
	while (n--)
	{
		if (*str == find)
			return ((void *)str);
		str++;
	}
	return (0);
}
