/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:42 by dakyo             #+#    #+#             */
/*   Updated: 2024/04/06 17:30:44 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

/** etc.c */
void	error_exit(void);
void	free_arr(int argc, char **arr);
void	free_arr_res(int argc, char **arr, char *res);
void	free_stack(t_stack *stack);

/** ft_utils.c */
int		ft_strlen(const char *str, int k);
int		ft_atoi(const char *str);
t_node	*ft_lstnew(t_stack *stack, int content);
void	ft_lstadd_back(t_stack *stack, t_node **node, t_node *new);
t_node	*ft_lstlast(t_node *node, t_node *new);

/** input_preprocess.c */
int		check_valid_input(int argc, char **argv);
int		num_count_in_argv(char *argv);
char	**split_input(int argc, char **argv, int size);
char	*split_in_argv(int argc, char *argv, int *k, char **arr);
int		check_valid_int(char *str);

/** pa_pb.c */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/** rra_rrb_rrr.c */
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/** sa_sb_ss.c */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/** set_stack.c */
t_stack	*make_stack(void);
void	init_push_stack_a(char **arr, t_stack *stack_a, int size);
int		check_a_stack(t_node *node, int size);
int		check_b_stack(t_node *node, int size);
int		is_stack_sort(t_stack *stack, int size, int sign);

/** sorting_arr.c */
int		*get_sorted_arr(t_stack **stack_a, int size);
int		partition(int *arr, int left, int right);
void	arr_quick_sort(int *arr, int left, int right);

/** sorting_hard.c */
void	hard_coding(t_stack **stack_a, t_stack **stack_b, int size, int flag);
void	three_node_a_sort(t_stack **stack_a, int cnt);
void	under_three_a_sort(t_stack **stack_a, int cnt);
void	three_node_b_sort(t_stack **stack_b, int cnt);
void	under_three_b_sort(t_stack **stack_b, int cnt);

/** sorting_quick.c */
void	arr_initialize(int *arr);
void	a_to_b(t_stack **stack_a, t_stack **stack_b, int size);
void	a_to_b_2(t_stack **stack_a, t_stack **stack_b, int size, int *arr);
void	b_to_a(t_stack **stack_a, t_stack **stack_b, int size);
void	b_to_a_2(t_stack **stack_a, t_stack **stack_b, int size, int *arr);

/** sorting_stack.c */
void	initialize(int *ra_cnt, int *rb_cnt, int *pb_cnt);
void	ra_rb(t_stack **stack, int *cnt, int sign);
void	set_pivot(t_stack **stack_a, int *pivot1, int *pivot2, int size);
void	quick_sort(t_stack **stack_a, t_stack **stack_b, int size);

/** sorting_utils.c */
int		count_stack_size(t_stack **stack);
int		rrr_count(t_stack **stack_a, t_stack **stack_b, int ra, int rb);
void	rrb_a_to_b(t_stack **stack_b, int rb_count, int n);
void	pa_pb(t_stack **stack_a, t_stack **stack_b, int *count, int sign);
void	rr_count(t_stack **stack_a, t_stack **stack_b, int *count, int *n);

#endif