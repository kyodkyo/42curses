/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:33 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/06 17:42:33 by dakang           ###   ########.fr       */
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
	free_arr(argc, arr);
	stack_b = make_stack();
	if (is_stack_sort(stack_a, size, 1) == 1)
		return (0);
	if (size <= 3)
		hard_coding(&stack_a, &stack_b, size, 1);
	else
		quick_sort(&stack_a, &stack_b, size);
	free_stack(stack_a);
	free(stack_a);
	free_stack(stack_b);
	free(stack_b);
}
