/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:35:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/08 16:49:32 by dakyo            ###   ########.fr       */
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
