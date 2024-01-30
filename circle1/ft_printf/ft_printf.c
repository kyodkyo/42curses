/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:28:10 by dakyo             #+#    #+#             */
/*   Updated: 2024/01/30 20:33:35 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(va_list v_list, const char *str, int *idx)
{
	idx++;
	if (str[*idx] == 'c')
		return (ft_print_c(v_list));
	else if (str[*idx] == 's')
		return (ft_print_s(v_list));
	else if (str[*idx] == 'p')
		return (ft_print_p(v_list));
	else if (str[*idx] == 'd')
		return (ft_print_d(v_list));
	else if (str[*idx] == 'i')
		return (ft_print_i(v_list));
	else if (str[*idx] == 'u')
		return (ft_print_u(v_list));
	else if (str[*idx] == 'x')
		return (ft_print_x(v_list));
	else if (str[*idx] == 'X')
		return (ft_printl_X(v_list));
	else if (str[*idx] == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	else
		return (-1);
}

int	ft_printf(char const *str, ...)
{
	int		idx;
	int		res;
	int		count;
	va_list	v_list;

	idx = 0;
	count = 0;
	va_start(v_list, str);
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			res = ft_specifier(v_list, str, &idx);
			if (res == -1)
				return (-1);
		}
		else
		{
			if (write(1, &str[idx], 1) == -1)
				return (-1);
			res++;
		}
		count += res;
		idx++;
	}
	va_end(v_list);
	return (count);
}
