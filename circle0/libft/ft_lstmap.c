/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:53:58 by dakang            #+#    #+#             */
/*   Updated: 2023/10/25 16:22:39 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;
	void	*temp_content;

	result = 0;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		temp_content = f(lst -> content);
		temp = ft_lstnew(temp_content);
		if (temp == NULL)
		{
			free(temp_content);
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, temp);
		lst = lst -> next;
	}
	return (result);
}
