/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:21:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/03 22:19:56 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
