CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
NAME_BONUS = pipex_bonus

INCLUDE = pipex.h
BONUS_DIR = ./bonus/

SRCS = etc.c ft_utils.c info.c pipex.c process.c
SRCS_BONUS = $(BONUS_DIR)etc_bonus.c $(BONUS_DIR)ft_utils_bonus.c $(BONUS_DIR)get_next_line_utils.c $(BONUS_DIR)get_next_line.c \
$(BONUS_DIR)info_bonus.c $(BONUS_DIR)pipex_bonus.c $(BONUS_DIR)process_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus