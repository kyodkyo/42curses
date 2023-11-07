/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:53:58 by dakang            #+#    #+#             */
/*   Updated: 2023/10/23 18:15:39 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	res = ft_lstnew(f(lst -> content));
	if (res == NULL)
		return (NULL);
	temp = res;
	lst = lst -> next;
	while (lst)
	{
		res -> next = ft_lstnew(f(lst -> content));
		if (res -> next == NULL)
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		res = res -> next;
		lst = lst -> next;
	}
	res -> next = NULL;
	return (res);
}
