/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:25:37 by dakyo             #+#    #+#             */
/*   Updated: 2024/07/09 20:23:22 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_info	info;

	if (argc != 5 && argc != 6)
		return (error("argc error"));
	memset(&info, 0, sizeof(t_info));
	if (init_info(argc, argv, &info))
		return (error("init info error"));
	if (init_philo(&info, &philo))
		return (error("init philo error"));
	if (run_philo(&info, philo))
		return (error("philo execute error"));
	return (0);
}
