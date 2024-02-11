/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:28:10 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/12 02:01:36 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list *v_list)
{
	int		c;
	int		res;

	c = (char)va_arg(*v_list, int);
	res = write(1, &c, 1);
	if (res == -1)
		return (-1);
	return (1);
}

int	ft_print_s(va_list *v_list)
{
	int		len;
	int		res;
	char	*str;

	len = 0;
	res = 0;
	str = va_arg(*v_list, char *);
	if (str == NULL)
	{
		res = write(1, "(null)", 6);
		if (res == -1)
			return (-1);
		return (6);
	}
	while (*str)
	{
		res = write(1, *str, 1);
		if (res == -1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}

int	ft_prinf_p(va_list *v_list)
{
	int					i;
	int					len;
	char				arr[20];
	unsigned long long	address;

	i = 0;
	len = 0;
	address = va_arg(*v_list, unsigned long long);
	if (address == NULL)
		if (write(1, "0x", 2) == -1)
			return (-1);
	while (address >= 16)
	{
		arr[i] = "0123456789abcdef"[address % 16];
		address /= 16;
		i++;
	}
	arr[i] = "0123456789abcdef"[address];
	len = ft_len(arr, i);
	if (len == -1)
		return (-1);
	return (len + 2);
}

int	ft_specifier(va_list *v_list, const char c)
{
	if (c == 'c')
		return (ft_print_c(*v_list));
	else if (c == 's')
		return (ft_print_s(*v_list));
	else if (c == 'p')
		return (ft_print_p(*v_list));
	else if (c == 'i' || c == 'd')
		return (ft_print_d_i(*v_list));
	else if (c == 'u')
		return (ft_print_u(*v_list));
	else if (c == 'x')
		return (ft_print_x(*v_list));
	else if (c == 'X')
		return (ft_printl_X(*v_list));
	else if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	else
		return (-1);
}

int	ft_printf(char const *str, ...)
{
	int		res;
	int		count;
	va_list	v_list;

	res = 0;
	va_start(v_list, str);
	while (*str)
	{
		count = 1;
		if (*str == '%')
		{
			str++;
			count = ft_specifier(&v_list, *str++);
			if (count == -1)
				return (-1);
		}
		else
		{
			if (write(1, *str++, 1) == -1)
				return (-1);
		}
		res += count;
	}
	va_end(v_list);
	return (res);
}
