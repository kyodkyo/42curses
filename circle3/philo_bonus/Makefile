CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

NAME = philo_bonus

INCLUDE = philo_bonus.h
SRCS = execute_bonus.c init_bonus.c philo_bonus.c utils_bonus.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re