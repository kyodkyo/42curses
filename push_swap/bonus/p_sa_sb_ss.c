/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sa_sb_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:18:01 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/06 15:38:54 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	sa(t_stack **stack_a)
{
	t_node	*temp;
	int		data;

	if (!(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	temp = (*stack_a)->top->next;
	data = temp->content;
	temp->content = (*stack_a)->top->content;
	(*stack_a)->top->content = data;
}

void	sb(t_stack **stack_b)
{
	t_node	*temp;
	int		data;

	if (!(*stack_b)->top || !(*stack_b)->top->next)
		return ;
	temp = (*stack_b)->top->next;
	data = temp->content;
	temp->content = (*stack_b)->top->content;
	(*stack_b)->top->content = data;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*temp;
	int		data;

	if (!(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	temp = (*stack_a)->top->next;
	data = temp->content;
	temp->content = (*stack_a)->top->content;
	(*stack_a)->top->content = data;
	if (!(*stack_b)->top || !(*stack_b)->top->next)
		return ;
	temp = (*stack_b)->top->next;
	data = temp->content;
	temp->content = (*stack_b)->top->content;
	(*stack_b)->top->content = data;
}
