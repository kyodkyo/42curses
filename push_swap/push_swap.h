/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:42 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 20:31:00 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	int				flag;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

/** etc.c */
void	error_exit(void);
void	free_arr(int argc, char **arr, char *res);

/** ft_utils.c */
int		ft_strlen(const char *str, int k);

/** input_preprocess.c */
int		num_count_in_argv(char *argv);
char	**split_input(int argc, char **argv, int size);
char	*split_in_argv(int argc, char *argv, int *k, char **arr);
int		check_valid(char *str);

#endif