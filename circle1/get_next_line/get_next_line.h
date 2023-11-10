/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:43:11 by dakang            #+#    #+#             */
/*   Updated: 2023/11/09 21:52:14 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 500
#endif

int find_new_line(char *total_line);
char *check_new_line(char **total_line, char *buffer);
char *read_buffer(int fd, char *buffer, char **total_line);
char *get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1, int size);
int		ft_strlen(const char *s);

#endif