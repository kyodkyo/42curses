/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:53:31 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 21:09:36 by dakyo            ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int		i;
	int		flag;
	long	num;

	i = 0;
	flag = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return ((int)num * flag);
}

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> prev = NULL;
	node -> next = NULL;
	return (node);
}
