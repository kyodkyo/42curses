/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:53:46 by dakang            #+#    #+#             */
/*   Updated: 2023/10/23 18:08:29 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next_lst;

	next_lst = *lst;
	while (next_lst)
	{
		temp = next_lst -> next;
		ft_lstdelone(next_lst, del);
		next_lst = temp;
	}
	*lst = NULL;
}
