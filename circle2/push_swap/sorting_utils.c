/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:11:10 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/30 21:47:59 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack_size(t_stack **stack)
{
	int		n;
	t_node	*temp;

	n = 0;
	temp = (*stack)->top;
	while (temp)
	{
		temp = temp -> next;
		n++;
	}
	return (n);
}

int	rrr_count(t_stack **stack_a, t_stack **stack_b, int ra, int rb)
{
	int	n;

	n = 0;
	while (n < ra && n < rb)
	{
		rrr(stack_a, stack_b);
		n++;
	}
	return (n);
}

void	rrb_a_to_b(t_stack **stack_b, int rb_count, int n)
{
	while (n < rb_count)
	{
		if (n < rb_count)
			rrb(stack_b);
		n++;
	}
}

void	pa_pb(t_stack **stack_a, t_stack **stack_b, int *count, int sign)
{
	if (sign == 1)
		pa(stack_a, stack_b);
	else if (sign == 2)
		pb(stack_a, stack_b);
	(*count)++;
}

void	rr_count(t_stack **stack_a, t_stack **stack_b, int *count, int *n)
{
	rr(stack_a, stack_b);
	(*count)++;
	(*n)++;
}
