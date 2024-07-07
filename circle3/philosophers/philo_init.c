/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:56:17 by dakang            #+#    #+#             */
/*   Updated: 2024/07/07 16:33:15 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (pthread_mutex_init(&(info->print_locks), NULL))
		return (1);
	if (pthread_mutex_init(&(info->time), NULL))
		return (1);
	return (0);
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
	info->start_time = get_time();
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
		(*philo)[i].last_eat_time = get_time();
		i++;
	}
	return (0);
}
