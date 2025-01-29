# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 21:36:18 by artuda-s          #+#    #+#              #
#    Updated: 2025/01/29 22:24:38 by artuda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# Binary name
NAME = first

# Compiler
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Files
SRC = main.cpp ClapTrap.cpp 
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