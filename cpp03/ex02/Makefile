# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 12:37:42 by lcuevas-          #+#    #+#              #
#    Updated: 2024/11/15 12:37:43 by lcuevas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
