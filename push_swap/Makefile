CC = cc -Wall -Wextra -Werror -g3 

NAME = push_swap
NAME_BONUS = checker

INCLUDE = push_swap.h

SRCS = etc.c ft_utils.c input_preprocess.c pa_pb_ra_rb_rr.c push_swap.c rra_rrb_rrr.c sa_sb_ss.c \
		set_stack.c sorting_arr.c sorting_hard.c sorting_quick.c sorting_stack.c sorting_utils.c

BONUS_DIR = ./bonus/
SRCS_BONUS = $(BONUS_DIR)b_checker.c $(BONUS_DIR)b_etc.c $(BONUS_DIR)b_ft_utils.c $(BONUS_DIR)b_get_next_line_utils.c \
			$(BONUS_DIR)b_get_next_line.c $(BONUS_DIR)b_input_preprocess.c $(BONUS_DIR)b_pa_pb_ra_rb_rr.c \
			$(BONUS_DIR)b_rra_rrb_rrr.c $(BONUS_DIR)b_set_stack.c $(BONUS_DIR)main.c $(BONUS_DIR)p_sa_sb_ss.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus