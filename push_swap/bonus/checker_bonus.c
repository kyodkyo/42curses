/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:57:25 by dakang            #+#    #+#             */
/*   Updated: 2024/04/06 17:47:20 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int		res;
	char	*com;

	res = 0;
	while (1)
	{
		com = get_next_line(0);
		if (!com)
			break ;
		res = check_command1(stack_a, stack_b, com);
		if (res == -1)
		{
			res = check_command2(stack_a, stack_b, com);
			if (res == -1)
			{
				free(com);
				free_stack_exit(*stack_a, *stack_b);
			}
		}
		free(com);
	}
	if (is_stack_sort(*stack_a, (*stack_a)->size, 1) == 0 || (*stack_b)->top)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	compare_command(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_command1(t_stack **stack_a, t_stack **stack_b, char *com)
{
	if (!(compare_command(com, "pa\n")))
		pa(stack_a, stack_b);
	else if (!(compare_command(com, "pb\n")))
		pb(stack_a, stack_b);
	else if (!(compare_command(com, "ra\n")))
		ra(stack_a);
	else if (!(compare_command(com, "rb\n")))
		rb(stack_b);
	else if (!(compare_command(com, "rr\n")))
		rr(stack_a, stack_b);
	else if (!(compare_command(com, "sa\n")))
		sa(stack_a);
	else if (!(compare_command(com, "sb\n")))
		sb(stack_b);
	else if (!(compare_command(com, "ss\n")))
		ss(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

int	check_command2(t_stack **stack_a, t_stack **stack_b, char *com)
{
	if (!(compare_command(com, "rra\n")))
		rra(stack_a);
	else if (!(compare_command(com, "rrb\n")))
		rrb(stack_b);
	else if (!(compare_command(com, "rrr\n")))
		rrr(stack_a, stack_b);
	else
		return (-1);
	return (0);
}
