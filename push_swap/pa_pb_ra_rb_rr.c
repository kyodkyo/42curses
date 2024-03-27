/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:35:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/28 00:02:55 by dakyo            ###   ########.fr       */
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
	temp->prev = (*stack_a)->bottom;
	(*stack_a)->bottom->next = temp;
	(*stack_a)->bottom = (*stack_a)->bottom->next;
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
	temp->prev = (*stack_b)->bottom;
	(*stack_b)->bottom->next = temp;
	(*stack_b)->bottom = (*stack_b)->bottom->next;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
