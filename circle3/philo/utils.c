/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:53:29 by dakang            #+#    #+#             */
/*   Updated: 2024/07/25 15:53:53 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] && i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	if (us1[i] == '\0' && i < n)
		return (us1[i] - us2[i]);
	return (0);
}

int	action_print(t_info *info, int id, char *str)
{
	long long	cur_time;

	pthread_mutex_lock(&(info->print_lock));
	cur_time = get_cur_time();
	if (cur_time == -1)
		return (1);
	if (!get_set_finish_flag(info, 0))
		printf("%lld %d %s\n", cur_time - info->start_time, id + 1, str);
	if (ft_strncmp(str, "died", 4) == 0)
		return (0);
	pthread_mutex_unlock(&(info->print_lock));
	return (0);
}

int	get_set_finish_flag(t_info *info, int n)
{
	int	result;

	result = 0;
	if (n == 0)
	{
		pthread_mutex_lock(&(info->flag_lock));
		result = info->finish_flag;
		pthread_mutex_unlock(&(info->flag_lock));
	}
	else if (n == 1)
	{
		pthread_mutex_lock(&(info->flag_lock));
		info->finish_flag = 1;
		pthread_mutex_unlock(&(info->flag_lock));
	}
	return (result);
}

int	get_finished_eat_count(t_info *info)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&(info->eat_lock));
	res = info->finished_eat_philo;
	pthread_mutex_unlock(&(info->eat_lock));
	return (res);
}

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
