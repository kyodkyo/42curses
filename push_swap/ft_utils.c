/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:53:31 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 16:33:22 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str, int k)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[k] && str[k] != ' ')
	{
		if (str[k] == ' ')
			break ;
		k++;
		i++;
	}
	return (i);
}
