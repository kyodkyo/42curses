/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:58:53 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/30 22:57:17 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_coding(t_stack **stack_a, t_stack **stack_b, int size, int flag)
{
	if (flag == 1)
	{
		if (size == count_stack_size(stack_a))
			three_node_a_sort(stack_a, size);
		else
			under_three_a_sort(stack_a, size);
		return ;
	}
	else if (flag == 2)
	{
		if (size == count_stack_size(stack_b))
		{
			three_node_b_sort(stack_b, size);
			while (size-- > 0)
				pa(stack_a, stack_b);
		}
		else
		{
			under_three_b_sort(stack_b, size);
			while (size-- > 0)
				pa(stack_a, stack_b);
		}
	}
}

void	three_node_a_sort(t_stack **stack_a, int size)
{
	int	a;
	int	b;
	int	c;

	if (is_stack_sort(*stack_a, size, 1))
		return ;
	while (!(is_stack_sort(*stack_a, size, 1)))
	{
		a = (*stack_a)->top->content;
		b = (*stack_a)->top->next->content;
		if (size == 3)
			c = (*stack_a)->top->next->next->content;
		if (size == 2 || (a < b && b > c && a < c) || (a > b && b < c && a < c)
			|| (a > b && b > c && a > c))
		{
			sa(stack_a);
			continue ;
		}
		if ((a > b && b < c))
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	under_three_a_sort(t_stack **stack_a, int size)
{
	int	a;
	int	b;
	int	c;

	if (size == 1 || is_stack_sort(*stack_a, size, 1))
		return ;
	while (!(is_stack_sort(*stack_a, size, 1)))
	{
		a = (*stack_a)->top->content;
		b = (*stack_a)->top->next->content;
		if (size == 3)
			c = (*stack_a)->top->next->next->content;
		if (size == 2 || (a > b && a > c) || (c > a && c > b))
			sa(stack_a);
		else if ((b > a && b > c))
		{
			ra(stack_a);
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	three_node_b_sort(t_stack **stack_b, int size)
{
	int	a;
	int	b;
	int	c;

	if (size == 1 || is_stack_sort(*stack_b, size, 2))
		return ;
	while (!(is_stack_sort(*stack_b, size, 2)))
	{
		a = (*stack_b)->top->content;
		b = (*stack_b)->top->next->content;
		if (size == 3)
			c = (*stack_b)->top->next->next->content;
		if (size == 2 || (a > b && b < c && a > c) || (a < b && b > c && a > c)
			|| (a < b && b < c && a < c))
		{
			sb(stack_b);
			continue ;
		}
		if (a < b && b > c)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	under_three_b_sort(t_stack **stack_b, int size)
{
	int	a;
	int	b;
	int	c;

	if (is_stack_sort(*stack_b, size, 2))
		return ;
	while (!(is_stack_sort(*stack_b, size, 2)))
	{
		a = (*stack_b)->top->content;
		b = (*stack_b)->top->next->content;
		if (size == 3)
			c = (*stack_b)->top->next->next->content;
		if (size == 2 || (a < b && a < c) || (c < a && c < b))
		{
			sb(stack_b);
		}
		else if ((b < a && b < c))
		{
			rb(stack_b);
			sb(stack_b);
			rrb(stack_b);
		}
	}
}
