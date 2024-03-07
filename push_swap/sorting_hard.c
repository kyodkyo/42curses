/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:35:06 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/07 23:16:45 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_content(t_stack **stack_a)
{
	int		min;
	t_node	*temp;

	temp = (*stack_a)->top;
	min = temp->content;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->content < min)
			min = temp->content;
	}
	return (min);
}

void	hard_coding(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size == 1)
		return ;
	else if ((*stack_a)->size == 2)
		sa(stack_a);
	else if ((*stack_a)->size == 3)
		node_3_sorting(stack_a);
	else if ((*stack_a)->size == 4)
		node_4_sorting(stack_a, stack_b);
	else
		node_5_sorting(stack_a, stack_b);
}

void	node_3_sorting(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->top->content;
	middle = (*stack_a)->top->next->content;
	bottom = (*stack_a)->bottom->content;
	while (!(top < middle && middle < bottom))
	{
		if (top > middle && top > bottom)
			ra(stack_a);
		else if (top > middle)
			sa(stack_a);
		else if (middle > bottom)
			rra(stack_a);
		top = (*stack_a)->top->content;
		middle = (*stack_a)->top->next->content;
		bottom = (*stack_a)->bottom->content;
	}
}

void	node_4_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min_content(stack_a);
	while (1)
	{
		if ((*stack_a)->top->content == min)
		{
			pb(stack_a, stack_b);
			break ;
		}
		ra(stack_a);
	}
	node_3_sorting(stack_a);
	pa(stack_a, stack_b);
}

void	node_5_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		min;

	i = 0;
	min = get_min_content(stack_a);
	while (i < 2)
	{
		if ((*stack_a)->top->content == min)
		{
			pb(stack_a, stack_b);
			min = get_min_content(stack_a);
			i++;
		}
		ra(stack_a);
	}
	node_3_sorting(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->top->content > (*stack_a)->top->next->content)
		sa(stack_a);
}
