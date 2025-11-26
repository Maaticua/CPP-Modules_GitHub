# Compiler & flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Files
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = fixed

# Compilation
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Supprimer objets et binaire
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
