/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:36:21 by dakang            #+#    #+#             */
/*   Updated: 2024/07/12 14:19:33 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_info(int argc, char **argv, t_info *info)
{
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 5 && argc != 6)
		return (error("argc error"));
	memset(info, 0, sizeof(t_info));
	if (init_info(argc, argv, &info))
		return (error("init info error"));
	if (run_philo(&info))
		return (error("philo execute error"));
	return (0);
}
