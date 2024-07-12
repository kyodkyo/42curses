/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:28:47 by dakang            #+#    #+#             */
/*   Updated: 2024/07/12 17:37:10 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error(char *str)
{
	printf("%s\n", str);
	return (1);
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

	sem_wait(info->print_lock);
	cur_time = get_cur_time();
	if (cur_time == -1)
		return (1);
	if (!get_set_finish_flag(info, 0))
		printf("%lld %d %s\n", cur_time - info->start_time, id + 1, str);
	if (ft_strncmp(str, "died", 4) == 0)
		return (0);
	sem_post(&(info->print_lock));
	return (0);
}
