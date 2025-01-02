# Binary
BIN = bankster

# Compiler
CC = c++
CFLAGS =  -std=c++98 -g
#-Wall -Wextra -Werror
VG = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks.log
# --track-fds=all

# Color variables
RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYN = \033[0;36m
WHT = \033[0;37m
RES = \033[0m

# Directories
INC_DIR = ./
SRC_DIR = ./
OBJ_DIR = ./


# Find all .c files in src/ and its subdirectories
SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')

# Create object file paths
OBJ_FILES := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))

TOTAL_FILES := $(words $(SRC_FILES))
COMPILED_FILES := $(shell if [ -d "$(OBJ_DIR)" ]; then find $(OBJ_DIR) -name "*.o" | wc -l; else echo 0; fi)

# Phony targets
.PHONY: all clean fclean re

# Rules
all: $(BIN)

$(BIN): $(OBJ_FILES) | $(OBJ_DIR)
	@$(CC) -I$(INC_DIR) $(CFLAGS) $(OBJ_FILES) -o $@
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(OBJ_DIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%% $(RES)\r"
	@echo "\n$(GRN)➾ [ ${BIN} ] created$(RES)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(OBJ_DIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%%$(RES)\r"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -f leaks.log
	@rm -f leaks-old.log
	@echo "${RED}➾ Cleaned the workspace${RES}"

fclean: clean
	@rm -f $(BIN)
	@echo "${RED}➾ Fully cleaned the workspace${RES}"

re: fclean all

#Debugging
leaks: all
	@if [ -f leaks.log ]; then mv leaks.log leaks-old.log; fi
	$(VG) ./$(BIN)

san: all
	@if [ -f leaks.log ]; then mv leaks.log leaks-old.log; fi
	./$(BIN)