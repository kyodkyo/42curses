/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_proprocess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:42:12 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 16:35:34 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_count_in_argv(char *argv)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (argv[i])
	{
		while (argv[i] && argv[i] == ' ')
			i++;
		if (argv[i] && argv[i] != ' ')
		{
			i++;
			cnt++;
		}
		while (argv[i] && argv[i] != ' ')
			i++;
	}
	return (cnt);
}

char	**split_input(int argc, char **argv, int size)
{
	int		i;
	int		j;
	int		k;
	char	*temp;
	char	**arr;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	while (++i < argc)
	{
		temp = argv[i];
		k = 0;
		while (temp[k])
		{
			while (temp[k] && temp[k] == ' ')
				k++;
			while (temp[k] && temp[k] != ' ')
				arr[j++] = split_in_argv(temp, &k);
		}
	}
	arr[size] = 0;
	return (arr);
}

char	*split_in_argv(char *argv, int *k)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(argv, *k) + 1);
	if (!res)
		return (NULL);
	while (argv[*k] && argv[*k] != ' ')
	{
		res[i] = argv[*k];
		i++;
		(*k)++;
	}
	res[i] = 0;
	return (res);
}
