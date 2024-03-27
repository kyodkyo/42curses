CC = cc # -Wall -Wextra -Werror
NAME = push_swap
INCLUDE = push_swap.h
SRCS = etc.c ft_utils.c input_preprocess.c pa_pb_ra_rb_rr.c \
		push_swap.c rra_rrb_rrr.c sa_sb_ss.c set_stack.c \
		sorting_arr.c sorting_hard.c sorting_quick.c \
		sorting_stack.c sorting_utils.c
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