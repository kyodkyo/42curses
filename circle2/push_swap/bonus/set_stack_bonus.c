/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:32:00 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/06 17:46:29 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	t_node	*node;
	int		str_len;

	node = ft_lstnew(stack_a, ft_atoi(arr[0]));
	if (!(stack_a->top))
		stack_a->top = node;
	if (size == 1)
	{
		stack_a->bottom = node;
		return ;
	}
	i = 1;
	while (i < size)
	{
		str_len = ft_strlen(arr[i], 0);
		if (str_len == 0 && arr[i] == (void *)0)
			error_exit();
		node = ft_lstnew(stack_a, ft_atoi(arr[i]));
		ft_lstadd_back(stack_a, &stack_a->top, node);
		i++;
	}
	stack_a->bottom = node;
	stack_a->size = i;
}

int	check_a_stack(t_node *node, int size)
{
	int	i;

	i = 1;
	while (i < size && node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	check_b_stack(t_node *node, int size)
{
	int	i;

	i = 1;
	while (i < size && node->next)
	{
		if (node->content < node->next->content)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	is_stack_sort(t_stack *stack, int size, int sign)
{
	t_node	*node;

	if (size == 1)
		return (1);
	node = stack->top;
	if (sign == 1)
		return (check_a_stack(node, size));
	else if (sign == 2)
		return (check_b_stack(node, size));
	return (1);
}
