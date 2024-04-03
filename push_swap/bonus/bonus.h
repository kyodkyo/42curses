/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:37:48 by dakang            #+#    #+#             */
/*   Updated: 2024/04/03 13:40:02 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

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

/** b_checker.c */
void	check_sorted(t_stack **stack_a, t_stack **stack_b);
int		compare_command(char *s1, char *s2);
int		check_command1(t_stack **stack_a, t_stack **stack_b, char *com);
int		check_command2(t_stack **stack_a, t_stack **stack_b, char *com);

/** b_etc.c */
void	error_exit(void);
void	free_arr(int argc, char **arr, char *res);
void	free_stack(t_stack *stack);

/** b_ft_utils.c */
int		ft_strlen(const char *str, int k);
int		ft_atoi(const char *str);
t_node	*ft_lstnew(t_stack *stack, int content);
void	ft_lstadd_back(t_stack *stack, t_node **node, t_node *new);
t_node	*ft_lstlast(t_node *node, t_node *new);

/** b_get_next_line.c */
int		update_buffer(int fd, ssize_t *read_size, char **prev);
int		make_line(char **prev, char **line);
void	free_all(char **prev, char **line);
char	*get_next_line(int fd);

/** b_get_next_line_utils.c */
int		check_len(char const *str);
int		ft_strchr(char const *str);
char	*ft_strdup(char const *str);
char	*ft_strjoin(char *temp, char const *buffer);
char	*ft_substr(char const *str, int start, int end);

/** b_input_preprocess.c */
int		check_valid_input(int argc, char **argv);
int		num_count_in_argv(char *argv);
char	**split_input(int argc, char **argv, int size);
char	*split_in_argv(int argc, char *argv, int *k, char **arr);
int		check_valid_int(char *str);

/** b_pa_pb_ra_rb_rr.c */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/** b_rra_rrb_rrr.c */
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/** set_stack.c */
t_stack	*make_stack(void);
void	init_push_stack_a(char **arr, t_stack *stack_a, int size);
int		check_a_stack(t_node *node, int size);
int		check_b_stack(t_node *node, int size);
int		is_stack_sort(t_stack *stack, int size, int sign);

/** b_sa_sb_ss.c */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

#endif