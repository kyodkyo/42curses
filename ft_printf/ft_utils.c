/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:25:31 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/12 16:46:07 by dakang           ###   ########.fr       */
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

int	ft_print_u(va_list *v_list)
{
	int				i;
	int				len;
	char			arr[10];
	unsigned int	num;

	i = 0;
	len = 0;
	num = va_arg(*v_list, unsigned int);
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

int	ft_print_x(va_list *v_list, int check)
{
	int				i;
	int				len;
	char			*str;
	char			arr[10];
	unsigned int	num;

	i = 0;
	len = 0;
	num = va_arg(*v_list, unsigned int);
	if (check == 1)
		str = "0123456789abcdef";
	else if (check == 2)
		str = "0123456789ABCDEF";
	while (num >= 16)
	{
		arr[i++] = str[num % 16];
		num /= 16;
	}
	arr[i] = str[num];
	len = ft_len(arr, i);
	if (len == -1)
		return (-1);
	return (len);
}
