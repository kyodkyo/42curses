/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_proprocess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:42:12 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 18:51:07 by dakang           ###   ########.fr       */
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
				arr[j++] = split_in_argv(temp, &k, argc, arr);
		}
	}
	arr[size] = 0;
	return (arr);
}

char	*split_in_argv(char *argv, int *k, int argc, char **arr)
{
	int		i;
	int len;
	char	*res;

	i = 0;
	len = ft_strlen(argv, *k);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (argv[*k] && argv[*k] != ' ')
	{
		res[i] = argv[*k];
		i++;
		(*k)++;
	}
	res[i] = 0;
	if (!check_valid(res))
	{
		write(1, "Error\n", 6);
		free_arr(argc, arr, 1);
	}
	return (res);
}

int check_valid(char *str)
{
	int i;
	int sign;
	long long res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[])
}

void free_arr(int argc, char *arr, int flag)
{
	int i;

	i = 0;
	while (i < argc)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	if (flag == 1)
		exit(1);
}