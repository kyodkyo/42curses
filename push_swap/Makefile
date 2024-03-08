CC = cc # -Wall -Wextra -Werror
NAME = push_swap
INCLUDE = push_swap.h
SRCS = etc.c ft_utils.c input_preprocess.c pa_pb.c push_swap.c \
		ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss.c set_stack.c \
		sort_check.c sorting_arr.c sorting_hard.c sorting_stack.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re