/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:25:11 by dakyo             #+#    #+#             */
/*   Updated: 2024/07/07 22:29:02 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct info{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				finish;
	int				finished_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_locks;
	pthread_mutex_t	time;
}	t_info;

typedef struct philo{
	int				id;
	int				left;
	int				right;
	int				eat_count;
	long long		last_eat_time;
	pthread_t		thread;
	t_info			*info;
}	t_philo;

/** init.c */
int			init_info(int argc, char **argv, t_info *info);
int			init_philo(t_info *info, t_philo **philo);

/** utils.c */
int			error(char *message);
long long	get_time(void);

/** ft_utils.c */
int			ft_atoi(const char *str);

#endif