/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:28:10 by dakyo             #+#    #+#             */
/*   Updated: 2024/01/30 21:40:27 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(va_list v_list, const char c)
{
	if (c == 'c')
		return (ft_print_c(v_list));
	else if (c == 's')
		return (ft_print_s(v_list));
	else if (c == 'p')
		return (ft_print_p(v_list));
	else if (c == 'd')
		return (ft_print_d(v_list));
	else if (c == 'i')
		return (ft_print_i(v_list));
	else if (c == 'u')
		return (ft_print_u(v_list));
	else if (c == 'x')
		return (ft_print_x(v_list));
	else if (c == 'X')
		return (ft_printl_X(v_list));
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
			count = ft_specifier(v_list, *str++);
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
