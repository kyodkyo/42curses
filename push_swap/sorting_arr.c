/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:02:49 by dakyo             #+#    #+#             */
/*   Updated: 2024/03/30 23:17:20 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_sorted_arr(t_stack **stack_a, int size)
{
	int		i;
	int		*arr;
	t_node	*temp;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	temp = (*stack_a)->top;
	while (i < size)
	{
		arr[i] = temp->content;
		i++;
		temp = temp->next;
	}
	arr_quick_sort(arr, 0, size - 1);
	return (arr);
}

int	partition(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	temp;
	int	pivot;

	i = left - 1;
	j = left;
	temp = 0;
	pivot = arr[right];
	while (j < right)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		j++;
	}
	temp = arr[right];
	arr[right] = arr[i + 1];
	arr[i + 1] = temp;
	return (i + 1);
}

void	arr_quick_sort(int *arr, int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = partition(arr, left, right);
		arr_quick_sort(arr, left, pivot - 1);
		arr_quick_sort(arr, pivot + 1, right);
	}
}
