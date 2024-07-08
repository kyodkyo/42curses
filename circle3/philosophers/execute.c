/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:43:58 by dakang            #+#    #+#             */
/*   Updated: 2024/07/08 16:55:06 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_action(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->forks[philo->left]));
	action_print(info, philo->id, "has taken a fork");
	if (info->num_of_philo != 1)
	{
		pthread_mutex_lock(&(info->forks[philo->right]));
		action_print(info, philo->id, "has taken a fork");
		action_print(info, philo->id, "is eating");
		pthread_mutex_lock(&(info->time));
		philo->last_eat_time = get_time();
		pthread_mutex_unlock(&(info->time));
		philo->eat_count = philo->eat_count + 1;
		pass_time((long long)info->time_to_eat, info);
		pthread_mutex_unlock(&(info->forks[philo->right]));
	}
	pthread_mutex_unlock(&(info->forks[philo->left]));
}

void	sleep_even_philo(t_info *info)
{
	int				diff;
	struct timeval	cur_time;
	struct timeval	time;

	gettimeofday(&cur_time, NULL);
	while (1)
	{
		gettimeofday(&time, NULL);
		diff = time.tv_usec - cur_time.tv_usec
			+ (time.tv_sec - cur_time.tv_sec) * 1000000;
		if (diff > info->time_to_eat * 900)
			break ;
		usleep(info->time_to_eat);
	}
}

void	*thread_routine(void *argv)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)argv;
	info = philo->info;
	if (philo->id % 2 == 0)
		sleep_even_philo(info);
	while (!info->finish)
	{
		if (info->num_of_philo - 1 == philo->id && philo->eat_count == 0)
			usleep(1);
		philo_action(info, philo);
		if (info->num_of_philo == 1)
			pass_time((long long)info->time_to_sleep, info);
		if (info->number_of_must_eat == philo->eat_count)
		{
			info->finished_eat++;
			break ;
		}
		action_print(info, philo->id, "is sleeping");
		pass_time((long long)info->time_to_sleep, info);
		action_print(info, philo->id, "is thinking");
	}
	return (0);
}

void	check_philo_finish(t_info *info, t_philo *philo)
{
	int			i;
	long long	cur;

	while (!info->finish)
	{
		if ((info->number_of_must_eat != 0)
			&& (info->num_of_philo == info->finished_eat))
		{
			info->finish = 1;
			break ;
		}
		i = 0;
		while (i < info->num_of_philo)
		{
			cur = get_time();
			if ((cur - philo[i].last_eat_time) >= info->time_to_die)
			{
				action_print(info, i, "died");
				info->finish = 1;
				pthread_mutex_unlock(&(info->print_locks));
				break ;
			}
			i++;
		}
	}
}

int	run_philo(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		philo[i].last_eat_time = get_time();
		if (pthread_create(&(philo[i].thread), NULL,
				thread_routine, &(philo[i])))
			return (1);
		i++;
	}
	check_philo_finish(info, philo);
	i = 0;
	while (i < info->num_of_philo)
		pthread_join(philo[i++].thread, NULL);
	return (0);
}
