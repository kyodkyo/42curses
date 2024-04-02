/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_etc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:56:07 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/02 17:44:47 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_arr(int argc, char **arr, char *res)
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
