/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:04:09 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/07 22:18:33 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_sort(t_stack *stack_a)
{
	int		i;
	int		size;
	t_node	*node;

	i = 1;
	size = stack_a->size;
	node = stack_a->top;
	if (size == 1)
		return (1);
	while (i < size && node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	b_sort(t_stack *stack_b)
{
	int		i;
	int		size;
	t_node	*node;

	i = 1;
	size = stack_b->size;
	node = stack_b->top;
	if (size == 1)
		return (1);
	while (i < size && node->next)
	{
		if (node->content < node->next->content)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
