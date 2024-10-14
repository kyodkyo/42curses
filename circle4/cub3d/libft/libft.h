/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:12:37 by dakyo             #+#    #+#             */
/*   Updated: 2024/09/29 16:51:23 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_atoi(const char *str);
char	**ft_split(char const *str, char c);
char	*ft_strcpy(const char *string);
char	*ft_strjoin(char *s1, char *s2, int s2_len, int s1_len);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif