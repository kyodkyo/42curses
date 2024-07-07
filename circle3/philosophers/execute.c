/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:43:58 by dakang            #+#    #+#             */
/*   Updated: 2024/07/07 23:00:05 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	action_print(t_info *info, int id, char *message)
{
	long long cur_time;

	pthread_mutex_lock(&(info->print_locks));
	cur_time = get_time();
	if (cur_time == -1)
		return (1);
	if (!(info->finish))
		printf("%lld %d %s\n", cur_time - info->start_time, id + 1, message);
	if (ft_strncmp(message, "died", 4) == 0)
		return (0);
	pthread_mutex_unlock(&(info->print_locks));
	return (0);
}

void	philo_action(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->forks[philo->left]));
	action_print(info, philo->id, "has taken a fork");
}

void	thread_routine(void *argv)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)argv;
	info = philo->info;
	if (philo->id % 2 == 0)
		sleep_even_philo(info);
	while (!info->finish)
	{
		philo_action(info, philo);
	}
}

void check_philo_finish()
{
	
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
