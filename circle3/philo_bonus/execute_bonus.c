/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:58:28 by dakang            #+#    #+#             */
/*   Updated: 2024/07/15 16:22:30 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pass_time(long long wait_time, t_info *info)
{
	long long	start;
	long long	now;

	start = get_cur_time();
	while (!get_set_finish_flag(info, 0))
	{
		now = get_cur_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}

void	philo_eating(t_info *info, t_philo *philo)
{
	sem_wait(info->forks);
	action_print(info, philo->id, "has taken a fork");
	if (info->num_of_philo != 1)
	{
		sem_wait(info->forks);
		action_print(info, philo->id, "has taken a fork");
		action_print(info, philo->id, "is eating");
		sem_wait(info->time_lock);
		philo->last_eat_time = get_cur_time();
		philo->eat_count = philo->eat_count + 1;
		sem_post(info->time_lock);
		pass_time((long long)info->time_to_eat, info);
		sem_post(info->forks);
		sem_post(info->forks);
	}
}

void	*check_philo_dead(void *argv)
{
	long long	cur;
	long long	last_time;
	t_info		*info;
	t_philo		*philo;

	philo = (t_philo *)argv;
	info = philo->info;
	while (!get_set_finish_flag(info, 0))
	{
		sem_wait(info->time_lock);
		last_time = philo->last_eat_time;
		sem_post(info->time_lock);
		cur = get_cur_time();
		if (cur - last_time >= info->time_to_die)
		{
			action_print(info, philo->id, "died");
			get_set_finish_flag(info, 1);
			break ;
		}
		usleep(1000);
	}
	exit(1);
	return (0);
}

int	process_routine(void *argv)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)argv;
	info = philo->info;
	if (pthread_create(&(philo->thread), NULL, check_philo_dead, argv))
		return (1);
	if (philo->id % 2 == 1)
		usleep(info->time_to_eat * 1000);
	while (!get_set_finish_flag(info, 0))
	{
		if (info->num_of_philo - 1 == philo->id && philo->eat_count == 0)
			usleep(1);
		philo_eating(info, philo);
		if (info->num_of_philo == 1)
			pass_time((long long)info->time_to_die, info);
		if (info->number_of_must_eat == philo->eat_count)
			info->finished_eat_philo++;
		action_print(info, philo->id, "is sleeping");
		pass_time((long long)info->time_to_sleep, info);
		action_print(info, philo->id, "is thinking");
	}
	return (0);
}

int	run_philo(t_info *info)
{
	int	i;
	int	status;

	i = 0;
	while (i < info->num_of_philo)
	{
		info->philo[i].pid = fork();
		if (info->philo[i].pid == 0)
		{
			info->philo[i].last_eat_time = get_cur_time();
			if (process_routine(&info->philo[i]))
				return (1);
			return (0);
		}
		i++;
	}
	waitpid(-1, &status, 0);
	if (status == -1)
	{
		i = -1;
		while (++i < info->num_of_philo)
			kill(info->philo[i].pid, -1);
	}
	return (0);
}
