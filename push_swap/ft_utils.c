/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:53:31 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/31 18:03:43 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str, int k)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i++] != ' ')
		k++;
	return (k);
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

t_node	*ft_lstnew(t_stack *stack, int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		free_stack(stack);
		error_exit();
	}
	node -> content = content;
	node -> prev = NULL;
	node -> next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack *stack, t_node **node, t_node *new)
{
	t_node	*temp;

	if (!*node)
		*node = new;
	else
	{
		temp = ft_lstlast(*node, new);
		if (!temp)
		{
			free_stack(stack);
			error_exit();
		}
		temp->next = new;
		new->prev = temp;
	}
}

t_node	*ft_lstlast(t_node *node, t_node *new)
{
	while (node -> next)
	{
		if (node -> content == new -> content)
			return (0);
		node = node -> next;
	}
	if (node -> content == new -> content)
		return (0);
	return (node);
}
