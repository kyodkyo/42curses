/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_input_preprocess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:34:49 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/06 14:00:05 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	check_valid_input(int argc, char **argv)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i], 0) == 0)
			error_exit();
		size += num_count_in_argv(argv[i]);
		i++;
	}
	return (size);
}

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
				arr[j++] = split_in_argv(argc, temp, &k, arr);
		}
	}
	arr[size] = 0;
	return (arr);
}

char	*split_in_argv(int argc, char *argv, int *k, char **arr)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(argv, *k);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	while (argv[*k] && argv[*k] != ' ')
	{
		res[i] = argv[*k];
		i++;
		(*k)++;
	}
	res[i] = 0;
	if (!check_valid_int(res))
	{
		free_arr_res(argc, arr, res);
		error_exit();
	}
	return (res);
}

int	check_valid_int(char *str)
{
	int			i;
	int			flag;
	long long	res;

	i = 0;
	flag = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
		if (res * flag > 2147483647 || res * flag < -2147483648)
			return (0);
	}
	return (1);
}
