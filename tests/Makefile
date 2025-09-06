# Defining Colors
GREEN := \033[0;32m
RED := \033[0;31m
CYAN := \033[36m
RESET := \033[0m



NAME = unit_test
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes

# GET_LIBFT_REPO = https://github.com/tpandya42/Libft.git
# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a
# LIBFT_INCLUDES = -I$(LIBFT_DIR)/includes

SRC_DIR = basic_tests
OBJ_DIR = obj
MAIN = main.c

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS)) $(OBJ_DIR)/main.o


FRAMEWORK_DIR = ../framework
FRAMEWORK = $(FRAMEWORK_DIR)/libunit.a

# for including libunit.h
CFLAGS += -I$(FRAMEWORK_DIR)/includes -I$(FRAMEWORK_DIR)

#Executing the executable in test:
EXEC = ./unit_test





RM = rm -f

all: $(FRAMEWORK) $(NAME)

# $(NAME): $(OBJS)
# 	@# Getting libft from Github if it's not present
# 	@if [ ! -d "$(LIBFT_DIR)" ]; then \
# 		echo "Cloning libft from $(GET_LIBFT_REPO)..."; \
# 		git clone $(GET_LIBFT_REPO) $(LIBFT_DIR); \
# 	fi
# 	@# Making it...
# 	@if [ -f $(LIBFT_DIR)/Makefile ]; then \
# 		make -C $(LIBFT_DIR); \
# 	fi
# 	@if [ -f $(LIBFT) ]; then \
# 		ar rcs $@ $(OBJS) $(LIBFT); \
# 	else \
# 		ar rcs $@ $(OBJS); \
# 	fi	
# 	@echo "$(CYAN)LIBUNIT BUILT!!!!$(RESET)";
#

$(NAME): $(OBJS) $(FRAMEWORK)
	@echo "$(CYAN)Linking $(NAME) with $(FRAMEWORK)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $@
	@echo "$(GREEN)Built $(NAME) ✔$(RESET)"

$(FRAMEWORK):
	@echo "$(CYAN)Building framework (libunit.a) in $(FRAMEWORK_DIR)$(RESET)"
	@$(MAKE) -C $(FRAMEWORK_DIR) || { echo "$(RED)Failed to build framework$(RESET)"; exit 1; }
		
		

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -c $< -o $@

$(OBJ_DIR)/main.o: $(MAIN) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: get_libft

get_libft:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		echo "$(LIBFT_DIR) already exists"; \
	else \
		git clone $(GET_LIBFT_REPO) $(LIBFT_DIR); \
	fi

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

test: all
	$(EXEC)

clean:
	$(RM) $(OBJS)
	@if [ -d $(FRAMEWORK_DIR) ]; then $(MAKE) -C $(FRAMEWORK_DIR) clean; fi
	$(RM) -r $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@if [ -d $(FRAMEWORK_DIR) ]; then $(MAKE) -C $(FRAMEWORK_DIR) fclean || true; fi
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
