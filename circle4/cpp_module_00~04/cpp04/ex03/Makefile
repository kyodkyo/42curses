NAME = ex03

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp \
	ICharacter.cpp IMateriaSource.cpp MateriaSource.cpp
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
