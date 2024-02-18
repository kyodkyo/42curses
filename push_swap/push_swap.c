/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:33 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 21:18:49 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		size;
	char	**arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	i = 0;
	size = 0;
	while (++i < argc)
		size += num_count_in_argv(argv[i]);
	arr = split_input(argc, argv, size);
	stack_a = make_stack(stack_a, 'a');
	init_push_stack_a(argc, arr, stack_a);
	stack_b = make_stack(stack_b, 'b');
}
