/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:57:10 by dakang            #+#    #+#             */
/*   Updated: 2024/04/06 17:46:47 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	free_arr(argc, arr);
	check_sorted(&stack_a, &stack_b);
	free_stack(stack_a);
	free(stack_a);
	free_stack(stack_b);
	free(stack_b);
}
