/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:29:13 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 21:42:12 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	env(t_list *env_list)
{
	char	*data;

	while (env_list)
	{
		if (((t_env *)(env_list->content))->value)
		{
			data = ((t_env *)(env_list->content))->data;
			write(STDOUT_FILENO, data, ft_strlen(data));
			write(STDOUT_FILENO, "\n", 1);
		}
		env_list = env_list->next;
	}
}
