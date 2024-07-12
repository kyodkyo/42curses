/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:36:58 by dakang            #+#    #+#             */
/*   Updated: 2024/07/12 17:34:18 by dakang           ###   ########.fr       */
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

typedef struct s_philo{
	struct s_info	*info;
	int				id;
	int				eat_count;
	long long		last_eat_time;
	pid_t			pid;
	pthread_t		thread;
}	t_philo;

typedef struct s_info{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				finish_flag;
	int				finished_eat_philo;
	long long		start_time;
	sem_t			*forks;
	sem_t			*print_lock;
	sem_t			*time_lock;
	sem_t			*flag_lock;
	struct s_philo	*philo;
}	t_info;

int			error(char *str);

long long	get_cur_time(void);
int			init_info(int argc, char **argv, t_info *info);
int			init_philo(t_info *info);

int			run_philo(t_info *info);

int			error(char *str);
int			action_print(t_info *info, int id, char *str);

#endif