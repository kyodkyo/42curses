CC = cc -Wall -Wextra -Werror
SRCS = ft_printf.c ft_utils.c
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $@ $^

%.o: %.c
	$(CC) -c $< -o $@ -I $(INCLUDE)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re