# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 17:02:30 by macaruan          #+#    #+#              #
#    Updated: 2025/12/16 16:15:33 by macaruan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Diamondtrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

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
