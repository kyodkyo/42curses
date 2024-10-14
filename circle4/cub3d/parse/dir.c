/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:40:58 by dakyo             #+#    #+#             */
/*   Updated: 2024/10/12 16:19:10 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*replace_path(char *str)
{
	int		i;
	int		len;
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
	len = ft_strlen(res);
	if (len <= 4 || (!(res[len - 4] == '.' && res[len - 3] == 'x'
				&& res[len - 2] == 'p' && res[len - 1] == 'm')))
	{
		free(res);
		cub_error("invalid file extension");
	}
	return (res);
}

void	load_mlx(t_image *img, char *path, t_cub *cub)
{
	int	width;
	int	height;

	img->init = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	if (!img->init)
		cub_error("mlx xpm file to image error");
	img->data = (int *)mlx_get_data_addr(img->init,
			&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	if (!img->data)
		cub_error("mlx get data addr error");
}

void	put_image(int dir, char *path, int *count, t_cub *cub)
{
	char	*n_path;

	n_path = ft_strcpy(path);
	if (dir == NORTH)
	{
		load_mlx(&(cub->img[SOUTH]), path, cub);
		cub->img[NORTH].path = n_path;
	}
	else if (dir == SOUTH)
	{
		load_mlx(&(cub->img[NORTH]), path, cub);
		cub->img[SOUTH].path = n_path;
	}
	else if (dir == EAST)
	{
		load_mlx(&(cub->img[WEST]), path, cub);
		cub->img[EAST].path = n_path;
	}
	else if (dir == WEST)
	{
		load_mlx(&(cub->img[EAST]), path, cub);
		cub->img[WEST].path = n_path;
	}
	(*count)++;
}

void	set_dir(char *dir, char *path, int *count, t_cub *cub)
{
	int	len;

	len = ft_strlen(dir);
	if (!(ft_strncmp(dir, "NO", len)) && !(cub->img[NORTH].path))
		put_image(NORTH, path, count, cub);
	else if (!(ft_strncmp(dir, "SO", len)) && !(cub->img[SOUTH].path))
		put_image(SOUTH, path, count, cub);
	else if (!(ft_strncmp(dir, "EA", len)) && !(cub->img[EAST].path))
		put_image(EAST, path, count, cub);
	else if (!(ft_strncmp(dir, "WE", len)) && !(cub->img[WEST].path))
		put_image(WEST, path, count, cub);
	else
		cub_error("direction error");
}

void	check_dir(char *line, int *count, t_cub *cub)
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
		path = replace_path(tmp[1]);
		set_dir(tmp[0], path, count, cub);
	}
	else
		cub_error("check dir error");
	free(path);
	free_arr(tmp, 0);
}
