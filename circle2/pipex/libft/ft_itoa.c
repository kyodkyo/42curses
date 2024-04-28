/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:44:18 by dakang            #+#    #+#             */
/*   Updated: 2023/10/22 15:19:35 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*res;
	unsigned int	num;

	len = int_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (n == 0)
		res[0] = '0';
	res[len] = '\0';
	while (num != 0)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
