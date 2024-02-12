/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:19:08 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/12 16:46:16 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_c(va_list *v_list);
int	ft_print_s(va_list *v_list);
int	ft_prinf_p(va_list *v_list);
int	ft_specifier(va_list *v_list, const char c);
int	ft_printf(char const *str, ...);

int	ft_len(char *arr, int i);
int	ft_print_d_i(va_list *v_list);
int	ft_print_u(va_list *v_list);
int	ft_print_x(va_list *v_list, int check);

#endif