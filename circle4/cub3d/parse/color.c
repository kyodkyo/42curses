/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:41:24 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/29 16:55:13 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*replace_line(char *str)
{
	int		i;
	char	*res;

	if (!str)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		if (str[i] == '\n')
			break ;
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	check_rgb_count(char **tmp_list, int *color_list)
{
	int	count;

	count = 0;
	while (tmp_list[count])
		count++;
	if (count != 3)
		cub_error("color count error");
	count = 0;
	while (tmp_list[count])
	{
		color_list[count] = ft_atoi(tmp_list[count]);
		count++;
	}
}

void	put_color(char *path, int *color_list)
{
	int		i;
	int		com;
	char	**tmp_list;

	i = -1;
	com = 0;
	while (path[++i])
	{
		if (path[i] == ',')
			com++;
	}
	if (com > 2)
		cub_error("color comma error");
	i = -1;
	while (path[++i])
	{
		if (!(path[i] == ',' || path[i] == '\n'
				|| (path[i] >= '0' && path[i] <= '9')))
			cub_error("color range error");
	}
	tmp_list = ft_split(path, ',');
	if (!tmp_list)
		cub_error("split error");
	check_rgb_count(tmp_list, color_list);
	free_arr(tmp_list, 0);
}

void	set_color(char *col, char *path, int *count, t_cub *cub)
{
	int	len;

	len = ft_strlen(col);
	if (!(ft_strncmp(col, "F", len)) && !(cub->color->floor_flag))
	{
		put_color(path, cub->color->floor);
		cub->color->floor_flag = 1;
	}
	else if (!(ft_strncmp(col, "C", len)) && !(cub->color->ceil_flag))
	{
		put_color(path, cub->color->ceil);
		cub->color->ceil_flag = 1;
	}
	else
		cub_error("color error");
	(*count)++;
}

void	check_color(char *line, int *count, t_cub *cub)
{
	int		len;
	char	*path;
	char	**tmp;

	len = 0;
	path = NULL;
	tmp = ft_split(line, ' ');
	if (!tmp)
		cub_error("split error");
	while (tmp[len])
		len++;
	if (len == 2)
	{
		path = replace_line(tmp[1]);
		set_color(tmp[0], path, count, cub);
	}
	else
		cub_error("check color error");
	free(path);
	free_arr(tmp, 0);
}
