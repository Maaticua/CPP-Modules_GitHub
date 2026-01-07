# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 17:02:30 by macaruan          #+#    #+#              #
#    Updated: 2026/01/07 12:37:36 by macaruan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	Animal.cpp		\
		WrongAnimal.cpp	\
		Cat.cpp			\
		WrongCat.cpp	\
		Dog.cpp			\
		main.cpp		\

OBJS = $(SRCS:.cpp=.o)

HEADERS =	Animal.hpp		\
			WrongAnimal.hpp	\
			Cat.hpp			\
			WrongCat.hpp	\
			Dog.hpp			\

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)


$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)✓ Compiled: $<$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
