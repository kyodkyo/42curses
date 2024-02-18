/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:42 by dakyo             #+#    #+#             */
/*   Updated: 2024/02/18 21:09:48 by dakyo            ###   ########.fr       */
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
	char			name;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

/** etc.c */
void	error_exit(void);
void	free_arr(int argc, char **arr, char *res);

/** ft_utils.c */
int		ft_strlen(const char *str, int k);
int		ft_atoi(const char *str);
t_node	*ft_lstnew(int content);

/** input_preprocess.c */
int		num_count_in_argv(char *argv);
char	**split_input(int argc, char **argv, int size);
char	*split_in_argv(int argc, char *argv, int *k, char **arr);
int		check_valid(char *str);

/** set_stack.c */
t_stack	*make_stack(int size, char name);
void	init_push_stack_a(int argc, char **arr, t_stack *stack_a);

#endif