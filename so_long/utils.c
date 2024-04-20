/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:00:28 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/21 02:35:39 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	if (count == 0 || size == 0)
		*(char *)res = 0;
	ft_bzero(res, count * size);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = -1;
	while (++i < n)
		ptr[i] = 0;
}

void	*initialize(void *arr, int value, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)arr;
	i = 0;
	while (i < len)
		temp[i++] = value;
	return (temp);
}

char	**make_visited(t_map *map)
{
	int		i;
	char	**visited;

	i = 0;
	visited = ft_calloc(map->board_height + 1, sizeof(char **));
	while (i < map->board_height)
	{
		visited[i] = ft_calloc(map->board_width + 1, sizeof(char *));
		i++;
	}
	return (visited);
}

void	free_2d_array(int board_length, char **board)
{
	int	i;

	i = 0;
	while (i < board_length)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
