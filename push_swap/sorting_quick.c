/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:44:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/28 00:15:10 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_initialize(int *arr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		arr[i] = 0;
		i++;
	}
}

void	a_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	n;
	int	arr[3];
	int	a_size;

	n = 0;
	a_size = count_stack_size(stack_a);
	if (is_stack_sort(*stack_a))
		return ;
	if (size <= 5)
		return (node_5_sorting(stack_a, stack_b));
	arr_initialize(arr);
	a_to_b_2(stack_a, stack_b, size, arr);
	if (a_size != size)
		n = rrr_count(stack_a, stack_b, arr[0], arr[2]);
	rrb_a_to_b(stack_b, arr[2], n);
	while (n < arr[0])
	{
		if (a_size != size)
			rra(stack_a);
		n++;
	}
	a_to_b(stack_a, stack_b, arr[0]);
	b_to_a(stack_a, stack_b, arr[2]);
	b_to_a(stack_a, stack_b, arr[1] - arr[2]);
	return ;
}

void	a_to_b_2(t_stack **stack_a, t_stack **stack_b, int size, int *arr)
{
	int	n;
	int	pivot[2];

	n = -1;
	set_pivot(stack_a, &pivot[0], &pivot[1]);
	while (++n < size)
	{
		if ((*stack_a)->top->content >= pivot[0])
			ra_rb(stack_a, &arr[0], 1);
		else
		{
			pb_count(stack_a, stack_b, &arr[1]);
			if ((*stack_b)->top->content > pivot[1])
			{
				if ((*stack_a)->top != NULL && n + 1 < size)
				{
					if ((*stack_a)->top->content >= pivot[0])
						rr_count(stack_a, stack_b, &arr[0], &n);
				}
				else
					rb(stack_b);
				arr[2]++;
			}
		}
	}
}

void	b_to_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	n;
	int	arr[3];

	n = size;
	arr_initialize(arr);
	if (is_stack_sort(*stack_b))
	{
		while (n-- > 0)
			pa(stack_a, stack_b);
	}
	if (size <= 5)
		return (node_5_sorting(stack_a, stack_b));
	b_to_a_2(stack_a, stack_b, size, arr);
	a_to_b(stack_a, stack_b, arr[1] - arr[0]);
	n = -1;
	while (++n < arr[0])
		rra(stack_a);
	a_to_b(stack_a, stack_b, arr[0]);
	n = -1;
	while (++n < arr[2])
		rrb(stack_b);
	b_to_a(stack_a, stack_b, arr[2]);
}

void	b_to_a_2(t_stack **stack_a, t_stack **stack_b, int size, int *arr)
{
	int	n;
	int	pivot[2];

	n = -1;
	set_pivot(stack_a, &pivot[0], &pivot[1]);
	while (++n < size)
	{
		if ((*stack_b)->top->content < pivot[1])
			ra_rb(stack_a, &arr[2], 2);
		else
		{
			pb_count(stack_a, stack_b, &arr[1]);
			if ((*stack_a)->top->content < pivot[0])
			{
				if ((*stack_b)->top != NULL && n + 1 < size)
				{
					if ((*stack_b)->top->content < pivot[1])
						rr_count(stack_a, stack_b, &arr[2], &n);
				}
				else
					ra(stack_a);
				arr[0]++;
			}
		}
	}
}
