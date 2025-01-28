# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 17:51:32 by artuda-s          #+#    #+#              #
#    Updated: 2025/01/28 22:14:05 by artuda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary name
NAME = phonebook

OBJ_DIR  = obj
INC_DIR = inc

# Compiler
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
IFLAGS = -I$(INC_DIR)

# Source files
SRC = src/Contact.cpp src/helpers.cpp src/main.cpp src/phonebook.cpp
# Object files
OBJ = $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Phony targets
.PHONY: all clean fclean re

# Rules
all: $(NAME)

$(NAME): $(OBJ) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all