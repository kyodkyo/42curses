/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:25:37 by dakyo             #+#    #+#             */
/*   Updated: 2024/08/02 15:40:59 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str)
{
	printf("%s\n", str);
	return (1);
}

void f(){
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_info	info;

// atexit(f);
	if (argc != 5 && argc != 6)
		return (error("argc error"));
	memset(&info, 0, sizeof(t_info));
	if (init_info(argc, argv, &info))
		return (error("init info error"));
	if (init_philo(&info, &philo))
	{
		free(philo);
		return (error("init philo error"));
	}
	if (run_philo(&info, philo))
	{
		free(philo);
		return (error("philo execute error"));
	}
	free(philo);
	return (0);
}
