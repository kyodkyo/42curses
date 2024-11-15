NAME = ex02

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) -o $@ $^

%.o : %.cpp
	$(CPP) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
