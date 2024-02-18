/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:53:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 21:40:21 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack(int size, char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack -> size = size;
	stack -> name = name;
	stack -> top = NULL;
	stack -> bottom = NULL;
	return (stack);
}

void	init_push_stack_a(int argc, char **arr, t_stack *stack_a)
{
	int i;
	int temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(arr[i]);
		if (i == 0)
		{
			stack_a -> top = ft_lstnew(temp);
			if (!stack_a -> top)
			{
				free_stack(stack_a);
				error_exit();
			}
		}
		else
		{
			
		}
		i++;
	}
}
