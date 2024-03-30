/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:33 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/30 23:16:31 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	char	**arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	size = check_valid_input(argc, argv);
	arr = split_input(argc, argv, size);
	stack_a = make_stack();
	init_push_stack_a(arr, stack_a, size);
	stack_b = make_stack();
	if (is_stack_sort(stack_a, size, 1) == 1)
		return (0);
	if (size <= 3)
		hard_coding(&stack_a, &stack_b, size, 1);
	else
		quick_sort(&stack_a, &stack_b, size);
}

	// printf("DEBUG\n");

	// int j=-1;
	// t_node	*tmp;
	// tmp = stack_a->bottom;
	// while(j < stack_a->size - 1)
	// {
	// 	printf("stack : %d\n", tmp->content);
	// 	tmp = tmp->next;
	// 	j++;
	// }
	// printf("size: %d\n", stack_a->size);