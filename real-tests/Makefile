# Defining Colors
GREEN := \033[0;32m
RED := \033[0;31m
CYAN := \033[36m
RESET := \033[0m


CRAZY_ANIMATION =

NAME = unit_test
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes

# GET_LIBFT_REPO = https://github.com/tpandya42/Libft.git
# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a
# LIBFT_INCLUDES = -I$(LIBFT_DIR)/includes

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))


FRAMEWORK_DIR = ../framework
FRAMEWORK = $(FRAMEWORK_DIR)/libunit.a


RM = rm -f

all: $(NAME)

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

$(NAME): $(OBJS)
	@# Calling Makefile of Framework
	@if [ ! -d "$(FRAMEWORK)" ]; then \
		echo "Calling Makefile of framework"; \
		make -C $(FRAMEWORK_DIR); \
	fi
	@if [ -f $(FRAMEWORK) ]; then \
		$(OBJS) $(FRAMEWORK); \
	else \
		@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME) \
	fi
	@echo "$(CYAN) GONNA DO SOMETHING!!!!$(RESET)";
		
		

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -c $< -o $@

.PHONY: get_libft
get_libft:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		echo "$(LIBFT_DIR) already exists"; \
	else \
		git clone $(GET_LIBFT_REPO) $(LIBFT_DIR); \
	fi

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)




clean:
	$(RM) $(OBJS)
	$(RM) -r $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	-rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
