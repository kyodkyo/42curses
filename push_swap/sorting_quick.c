/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:35:25 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/07 23:25:03 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	ra;
	int	rb;
	int	pb;
	int	pivot1;
	int	pivot2;

	ra = 0;
	rb = 0;
	pb = 0;
	pivot1 = select_pivot1(stack_a);
	pivot2 = select_pivot2(stack_a);
	// while (size--)
	// {

	// }
}
