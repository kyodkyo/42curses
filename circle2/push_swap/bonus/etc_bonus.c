/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:56:07 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/06 17:47:14 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_arr(int argc, char **arr)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_arr_res(int argc, char **arr, char *res)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(res);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*node;

	node = stack -> top;
	while (node)
	{
		temp = node -> next;
		free(node);
		node = NULL;
		node = temp;
	}
}

void	free_stack_exit(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	error_exit();
}
