/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:02:39 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/30 23:22:17 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(int *ra_cnt, int *rb_cnt, int *pb_cnt)
{
	*ra_cnt = 0;
	*rb_cnt = 0;
	*pb_cnt = 0;
}

void	ra_rb(t_stack **stack, int *cnt, int sign)
{
	if (sign == 1)
		ra(stack);
	else if (sign == 2)
		rb(stack);
	(*cnt)++;
}

void	set_pivot(t_stack **stack_a, int *pivot1, int *pivot2, int size)
{
	int	*arr;

	arr = get_sorted_arr(stack_a, size);
	*pivot1 = arr[size - (size / 3) - 1];
	*pivot2 = arr[size / 3];
	free(arr);
}

void	quick_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;
	int	pivot1;
	int	pivot2;

	initialize(&ra_cnt, &rb_cnt, &pb_cnt);
	set_pivot(stack_a, &pivot1, &pivot2, size);
	while (size-- > 0)
	{
		if ((*stack_a)->top->content >= pivot1)
			ra_rb(stack_a, &ra_cnt, 1);
		else
		{
			pb(stack_a, stack_b);
			pb_cnt++;
			if ((*stack_b)->top->content < pivot2)
				ra_rb(stack_b, &rb_cnt, 2);
		}
	}
	a_to_b(stack_a, stack_b, ra_cnt);
	b_to_a(stack_a, stack_b, pb_cnt - rb_cnt);
	b_to_a(stack_a, stack_b, rb_cnt);
}
