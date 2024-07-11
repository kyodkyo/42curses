/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:36:21 by dakang            #+#    #+#             */
/*   Updated: 2024/07/11 17:28:19 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (error("argc error"));
	memset(philo, 0, sizeof(t_philo));
	if (init_philo(&philo))
		return (error("init philo error"));
	if (run_philo(philo))
		return (error("philo execute error"));
	return (0);
}
