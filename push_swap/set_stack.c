/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:59:37 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/27 23:59:50 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack -> size = 0;
	stack -> top = NULL;
	stack -> bottom = NULL;
	return (stack);
}

void	init_push_stack_a(char **arr, t_stack *stack_a, int size)
{
	int		i;
	int		temp;
	t_node	*node;
	int		str_len;

	i = 0;
	while (i < size)
	{
		str_len = ft_strlen(arr[i], 0);
		if (str_len == 0 && arr[i] == (void *)0)
			error_exit();
		temp = ft_atoi(arr[i]);
		if (i == 0)
			stack_a->top = ft_lstnew(stack_a, temp);
		else
		{
			node = ft_lstnew(stack_a, temp);
			ft_lstadd_back(stack_a, &stack_a->top, node);
		}
		i++;
	}
	stack_a->bottom = node;
	stack_a->size = i;
}
