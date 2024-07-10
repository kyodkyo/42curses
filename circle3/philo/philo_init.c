/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:56:17 by dakang            #+#    #+#             */
/*   Updated: 2024/07/10 22:27:53 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result > 9223372036854775807 && sign == -1)
		return (-1);
	else if (result > 9223372036854775807)
		return (-1);
	return (sign * result);
}

int	init_info_mutex(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->forks)
		return (1);
	while (i < info->num_of_philo)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(info->print_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(info->time_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(info->flag_lock), NULL))
		return (1);
	return (0);
}

long long	get_cur_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	init_info(int argc, char **argv, t_info *info)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->num_of_philo <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (1);
	info->start_time = get_cur_time();
	if (argc == 6)
	{
		info->number_of_must_eat = ft_atoi(argv[5]);
		if (info->number_of_must_eat <= 0)
			return (1);
		if (info->num_of_philo == 1)
			info->number_of_must_eat = 0;
	}
	if (init_info_mutex(info))
		return (1);
	return (0);
}

int	init_philo(t_info *info, t_philo **philo)
{
	int				i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->num_of_philo);
	if (!*philo)
		return (1);
	while (i < info->num_of_philo)
	{
		(*philo)[i].info = info;
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->num_of_philo;
		(*philo)[i].eat_count = 0;
		(*philo)[i].last_eat_time = get_cur_time();
		i++;
	}
	return (0);
}
