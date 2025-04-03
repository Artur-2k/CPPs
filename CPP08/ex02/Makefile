# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fang <fang@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 15:32:26 by fang              #+#    #+#              #
#    Updated: 2025/04/03 15:32:28 by fang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary name
NAME = first 

# Compiler
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Files
SRC = main.cpp
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
