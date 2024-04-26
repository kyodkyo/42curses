/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_ra_rb_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:35:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/31 18:49:37 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*temp;

	if (!(*stack_b)->top)
		return ;
	temp = (*stack_b)->top;
	(*stack_b)->top = (*stack_b)->top->next;
	temp->next = (*stack_a)->top;
	(*stack_a)->top = temp;
	if (!(*stack_b)->top)
	{
		(*stack_b)->top = 0;
		(*stack_b)->bottom = 0;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*temp;

	if (!(*stack_a)->top)
		return ;
	temp = (*stack_a)->top;
	(*stack_a)->top = (*stack_a)->top->next;
	temp->next = (*stack_b)->top;
	(*stack_b)->top = temp;
	if (!(*stack_b)->bottom)
		(*stack_b)->bottom = temp;
	write(1, "pb\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_node	*temp;

	if (!(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	temp = (*stack_a)->top;
	(*stack_a)->top = (*stack_a)->top->next;
	(*stack_a)->top->prev = NULL;
	temp->next = NULL;
	(*stack_a)->bottom->next = temp;
	temp->prev = (*stack_a)->bottom;
	(*stack_a)->bottom = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_node	*temp;

	if (!(*stack_b)->top || !(*stack_b)->top->next)
		return ;
	temp = (*stack_b)->top;
	(*stack_b)->top = (*stack_b)->top->next;
	(*stack_b)->top->prev = NULL;
	temp->next = NULL;
	(*stack_b)->bottom->next = temp;
	temp->prev = (*stack_b)->bottom;
	(*stack_b)->bottom = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*temp;

	if (!(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	temp = (*stack_a)->top;
	(*stack_a)->top = (*stack_a)->top->next;
	(*stack_a)->top->prev = NULL;
	temp->next = NULL;
	(*stack_a)->bottom->next = temp;
	temp->prev = (*stack_a)->bottom;
	(*stack_a)->bottom = temp;
	if (!(*stack_b)->top || !(*stack_b)->top->next)
		return ;
	temp = (*stack_b)->top;
	(*stack_b)->top = (*stack_b)->top->next;
	(*stack_b)->top->prev = NULL;
	temp->next = NULL;
	(*stack_b)->bottom->next = temp;
	temp->prev = (*stack_b)->bottom;
	(*stack_b)->bottom = temp;
	write(1, "rr\n", 3);
}
