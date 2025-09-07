MAKEFLAGS += --no-print-directory


# Defining Colors
GREEN := \033[0;32m
RED := \033[0;31m
CYAN := \033[36m
RESET := \033[0m


NAME = libunit.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I$(LIBFT_DIR)

SRC_DIR = src_main
OBJ_DIR = obj

SRCS = \
       $(SRC_DIR)/libunit.c \
       $(SRC_DIR)/libunit_helpers.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

RM = rm -f

all: $(NAME)

$(LIBFT):
	@if [ ! -d $(LIBFT_DIR) ]; then \
		echo "$(RED)Missing local libft directory '$(LIBFT_DIR)'. Add it before building.$(RESET)"; \
		exit 1; \
	fi
	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
		$(MAKE) -C $(LIBFT_DIR); \
	else \
		echo "$(RED)Missing libft Makefile inside '$(LIBFT_DIR)'.$(RESET)"; \
		exit 1; \
	fi

$(NAME): $(OBJS) $(LIBFT)
	@ar rcs $@ $(OBJS)
	@echo "$(CYAN)Built $(NAME) (libft kept as separate archive)$(RESET)";


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -c $< -o $@

get_libft:
	@echo "Local libft expected at $(LIBFT_DIR). No clone performed."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS)
	@make -C$(LIBFT_DIR) clean
	@echo "$(CYAN)>>>>>Cleaning<<<<<$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@-rm -rf $(OBJ_DIR)
	@echo "$(GREEN)>>>>>Everything Cleaned Successfully<<<<<$(RESET)"

re: fclean all

.PHONY: all clean fclean re
