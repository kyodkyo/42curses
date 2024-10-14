NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRCS = main.c libft/ft_atoi.c libft/ft_split.c libft/ft_strcpy.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncmp.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c parse/color.c parse/dir.c parse/init.c parse/map.c parse/mlx.c \
	parse/utils.c parse/valid_check.c parse/wall.c execute/calc.c execute/dda.c execute/exec.c execute/game.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re