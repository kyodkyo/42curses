/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:35:18 by dakang            #+#    #+#             */
/*   Updated: 2024/01/14 17:49:59 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

typedef struct s_list
{
	int				fd;
	int				end_of_file;
	char			*prev;
	struct s_list	*next;
}		t_list;

int		get_next_node(int fd, t_list **list);
int		find_new_line(char *buf);
void	make_after_nl(t_list *list);
char	*read_buffer(int fd, t_list *list);
char	*get_next_line(int fd);

t_list	*get_fd(int fd, t_list *list);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, int buf_size);
char	*ft_strdup(const char *s1, int size);
void	free_one(int fd, t_list **list);

#endif