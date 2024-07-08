/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:53:29 by dakang            #+#    #+#             */
/*   Updated: 2024/07/08 16:54:58 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str)
{
	printf("%s\n", str);
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

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

	pthread_mutex_lock(&(info->print_locks));
	cur_time = get_time();
	if (cur_time == -1)
		return (1);
	if (!(info->finish))
		printf("%lld %d %s\n", cur_time - info->start_time, id + 1, str);
	if (ft_strncmp(str, "died", 4) == 0)
		return (0);
	pthread_mutex_unlock(&(info->print_locks));
	return (0);
}

void	pass_time(long long wait_time, t_info *info)
{
	long long	start;
	long long	now;

	start = get_time();
	while (!(info->finish))
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}
