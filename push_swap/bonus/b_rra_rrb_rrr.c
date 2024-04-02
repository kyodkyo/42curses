/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rra_rrb_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:51:08 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/02 17:46:01 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rra(t_stack **stack_a)
{
	t_node	*temp;

	if (!(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	temp = (*stack_a)->bottom;
	(*stack_a)->bottom = (*stack_a)->bottom->prev;
	(*stack_a)->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = (*stack_a)->top;
	(*stack_a)->top->prev = temp;
	(*stack_a)->top = (*stack_a)->top->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_node	*temp;

	if (!(*stack_b)->top || !(*stack_b)->top->next)
		return ;
	temp = (*stack_b)->bottom;
	(*stack_b)->bottom = (*stack_b)->bottom->prev;
	(*stack_b)->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = (*stack_b)->top;
	(*stack_b)->top->prev = temp;
	(*stack_b)->top = (*stack_b)->top->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*temp;

	if (!(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	temp = (*stack_a)->bottom;
	(*stack_a)->bottom = (*stack_a)->bottom->prev;
	(*stack_a)->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = (*stack_a)->top;
	(*stack_a)->top->prev = temp;
	(*stack_a)->top = (*stack_a)->top->prev;
	if (!(*stack_b)->top || !(*stack_b)->top->next)
		return ;
	temp = (*stack_b)->bottom;
	(*stack_b)->bottom = (*stack_b)->bottom->prev;
	(*stack_b)->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = (*stack_b)->top;
	(*stack_b)->top->prev = temp;
	(*stack_b)->top = (*stack_b)->top->prev;
	write(1, "rrr\n", 4);
}
