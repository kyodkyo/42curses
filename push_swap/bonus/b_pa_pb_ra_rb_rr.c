/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pa_pb_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:35:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/06 15:38:37 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
}
