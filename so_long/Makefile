# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 16:13:01 by dakyo             #+#    #+#              #
#    Updated: 2024/04/19 18:05:41 by dakyo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -Wall -Wextra -Werror

NAME = so_long
INCLUDE = so_long.h
SRCS = check_valid.c etc.c get_next_line_utils.c get_next_line.c \
put_image.c setting_map.c so_long.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o: %.c
	make -C ./mlx
	$(CC) -Imlx -c $< -o $@ -I $(INCLUDE)

clean:
	make -C ./mlx clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
