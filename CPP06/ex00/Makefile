# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fang <fang@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 11:56:28 by artuda-s          #+#    #+#              #
#    Updated: 2025/03/03 23:07:18 by fang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary name
NAME = convert 

# Compiler
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Files
SRC = main.cpp ScalarConverter.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = obj
# Phony targets
.PHONY: all clean fclean re

# Rules
all: $(NAME)

$(NAME): $(OBJ) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
