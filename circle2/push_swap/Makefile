CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

INCLUDE = push_swap.h

SRCS = etc.c ft_utils.c input_preprocess.c pa_pb_ra_rb_rr.c push_swap.c rra_rrb_rrr.c sa_sb_ss.c \
		set_stack.c sorting_arr.c sorting_hard.c sorting_quick.c sorting_stack.c sorting_utils.c

BONUS_DIR = ./bonus/
SRCS_BONUS = $(BONUS_DIR)checker_bonus.c $(BONUS_DIR)etc_bonus.c $(BONUS_DIR)ft_utils_bonus.c $(BONUS_DIR)get_next_line_bonus.c \
			$(BONUS_DIR)get_next_line_utils_bonus.c $(BONUS_DIR)input_preprocess_bonus.c $(BONUS_DIR)pa_pb_ra_rb_rr_bonus.c \
			$(BONUS_DIR)push_swap_bonus.c $(BONUS_DIR)rra_rrb_rrr_bonus.c $(BONUS_DIR)sa_sb_ss_bonus.c $(BONUS_DIR)set_stack_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus : $(NAME_BONUS)

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