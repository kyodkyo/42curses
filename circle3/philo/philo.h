/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:25:11 by dakyo             #+#    #+#             */
/*   Updated: 2024/07/10 22:33:19 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct info{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				finish_flag;
	int				finished_eat_philo;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	flag_lock;
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

int			run_philo(t_info *info, t_philo *philo);

long long	get_cur_time(void);
int			init_info(int argc, char **argv, t_info *info);
int			init_philo(t_info *info, t_philo **philo);

int			error(char *str);
int			action_print(t_info *info, int id, char *str);
void		pass_time(long long wait_time, t_info *info);

// n=0이면 get, n=1이면 set
int			get_set_finish_flag(t_info *info, int n);

#endif