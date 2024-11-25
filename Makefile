# Common
SRC_DIR := src
OBJ_DIR := obj
CC := cc
CFLAGS := -Wall -Wextra -Werror -I./lib/libft/include -Iinclude
LIBFT_DIR := lib/libft
LIBFT_DEPENDENCY := $(LIBFT_DIR)/libft.a

# Exetuable setup
PUSH_SWAP_NAME := push_swap
PUSH_SWAP_SRC := $(SRC_DIR)/main.c
PUSH_SWAP_OBJ := $(PUSH_SWAP_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(PUSH_SWAP_NAME)

# Server rules
$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(LIBFT_DEPENDENCY)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) -L$(LIBFT_DIR) -lft -o $(PUSH_SWAP_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Other rules
$(LIBFT_DEPENDENCY):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(PUSH_SWAP_NAME)

re: fclean all

.PHONY: all clean fclean re
