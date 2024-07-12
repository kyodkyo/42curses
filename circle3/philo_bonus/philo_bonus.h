/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:36:58 by dakang            #+#    #+#             */
/*   Updated: 2024/07/12 14:13:08 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct info{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				finish_flag;
	int				finished_eat_philo;
	int				id;
	int				eat_count;
	long long		start_time;
	long long		last_eat_time;
	pid_t			pid;
	sem_t			*forks;
	sem_t			*print_lock;
	sem_t			*die_lock;
	pthread_t		monitor;
	struct timeval	time;
}	t_info;

int	error(char *str);

#endif