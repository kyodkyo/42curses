# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 16:13:01 by dakyo             #+#    #+#              #
#    Updated: 2024/04/14 16:20:37 by dakyo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
INCLUDE = so_long.h
SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -Lmlx -lmx -framework OpenGL -framework AppKit -o $@

%.o: %.c
	make -C ./minilibx
	$(CC) $(CFLAGS) -I minilibx -c $< -o $@ -I $(INCLUDE)

clean:
	make -C ./minilibx clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
