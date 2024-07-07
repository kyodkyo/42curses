CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo
NAME_BONUS = philo_bonus

INCLUDE = philo.h
BONUS_DIR = ./bonus/

SRCS = philo.c
SRCS_BONUS = $(BONUS_DIR)philo.c 

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus