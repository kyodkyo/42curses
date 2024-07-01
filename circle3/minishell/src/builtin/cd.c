/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:57 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 18:56:29 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	cd(t_ASTNode *node, t_list *env_list)
{
	int		res;
	char	*path;
	t_env	*env_home;

	if (node->cmd->argc > 2)
		perror("cd");
	if (!node->cmd->argv[1])
	{
		env_home = find_by_key(env_list, "HOME");
		path = env_home->value;
	}
	else
		path = node->cmd->argv[1];
	res = chdir(path);
	if (res == -1)
		perror("cd");
}
