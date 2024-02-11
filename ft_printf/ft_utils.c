/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:25:31 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/12 02:01:32 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(char *arr, int i)
{
	int	len;

	len = 0;
	while (i >= 0)
	{
		if (write(1, arr[i--], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_print_d_i(va_list *v_list)
{
	int			i;
	int			len;
	char		arr[20];
	long long	num;

	i = 0;
	len = 0;
	num = va_arg(*v_list, long long);
	if (num < 0)
	{
		if (write(1, '-', 1) == -1)
			return (-1);
		num *= -1;
		len++;
	}
	while (num >= 10)
	{
		arr[i++] = (num % 10) + '0';
		num /= 10;
	}
	arr[i] = num + '0';
	len = ft_len(arr, i);
	if (len == -1)
		return (-1);
	return (len);
}

// int ft_print_u
// int ft_print_x
// int ft_print_X