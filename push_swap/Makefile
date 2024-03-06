CC = cc # -Wall -Wextra -Werror
NAME = push_swap
INCLUDE = push_swap.h
SRCS = etc.c ft_utils.c input_preprocess.c push_swap.c set_stack.c sort_check.c
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