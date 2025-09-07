# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smargine <smargine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 01:40:30 by smargine          #+#    #+#              #
#    Updated: 2025/09/07 01:52:54 by smargine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Defining Colors
GREEN := \033[0;32m
RED := \033[0;31m
CYAN := \033[36m
RESET := \033[0m



NAME = real_tests
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iincludes

# GET_LIBFT_REPO = https://github.com/tpandya42/Libft.git
# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a
# LIBFT_INCLUDES = -I$(LIBFT_DIR)/includes

#SRC_DIR = basic_tests
OBJ_DIR = obj
MAIN = main.c

SRCS := main
SRCS += $(addprefix ft_isdigit/, \
	00_ft_isdigit_launcher \
	01_ft_isdigit_basic_test \
	02_ft_isdigit_char_test \
	03_ft_isdigit_null_test \
	04_ft_isdigit_space_test \
)
SRCS += $(addprefix ft_strncmp/, \
	00_ft_strncmp_launcher \
	01_ft_strncmp_basic_test \
	02_ft_strncmp_plus_test \
	03_ft_strncmp_minus_test \
	04_ft_strncmp_null_test \
)
SRCS += $(addprefix ft_strjoin/, \
	00_ft_strjoin_launcher \
	01_ft_strjoin_basic_test \
	02_ft_strjoin_empty_test \
	03_ft_strjoin_null_test \
	04_ft_strjoin_special_test \
)
SRCS += $(addprefix ft_strlen/, \
	00_ft_strlen_launcher \
	01_ft_strlen_basic_test \
	02_ft_strlen_null_test \
	03_ft_strlen_empty_test \
	04_ft_strlen_newline_test \
)

OBJS := $(SRCS:%=%.o)
EXEC = ./real_tests

FRAMEWORK_DIR = ../framework
FRAMEWORK = $(FRAMEWORK_DIR)/libunit.a
LIBFT_DIR = $(FRAMEWORK_DIR)/libft
LIBFT = libft.a

# for including libunit.h
CFLAGS += -I$(FRAMEWORK_DIR)/includes -I$(FRAMEWORK_DIR)/ -I$(LIBFT_DIR)


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

$(NAME): $(OBJS) $(FRAMEWORK) $(LIBFT_DIR)/$(LIBFT)
	@echo "$(CYAN)Linking $(NAME) with $(FRAMEWORK) and libft.a$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) $(LIBFT_DIR)/$(LIBFT) -o $@
	@echo "$(GREEN)Built $(NAME) ✔$(RESET)"

$(LIBFT_DIR)/$(LIBFT):
	@echo "$(CYAN)Building local libft.a$(RESET)"
	@if [ ! -d $(LIBFT_DIR) ]; then echo "$(RED)Missing local libft directory at $(LIBFT_DIR)$(RESET)"; exit 1; fi
	@if [ -f $(LIBFT_DIR)/Makefile ]; then $(MAKE) -C $(LIBFT_DIR); else echo "$(RED)Missing libft Makefile$(RESET)"; exit 1; fi

$(FRAMEWORK): $(LIBFT_DIR)/$(LIBFT)
	@echo "$(CYAN)Building framework (libunit.a) in $(FRAMEWORK_DIR)$(RESET)"
	@$(MAKE) -C $(FRAMEWORK_DIR)
		
		

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -c $< -o $@

$(OBJ_DIR)/main.o: $(MAIN) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: get_libft

get_libft:
	@echo "Local libft expected at $(LIBFT_DIR). No clone performed."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

test: all
	@$(EXEC)

clean:
	@$(RM) $(OBJS)
	@make -C$(LIBFT_DIR) clean
	@if [ -d $(FRAMEWORK_DIR) ]; then $(MAKE) -C $(FRAMEWORK_DIR) clean; fi
	@echo "$(CYAN)>>>>>Cleaning<<<<<$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@if [ -d $(FRAMEWORK_DIR) ]; then $(MAKE) -C $(FRAMEWORK_DIR) fclean || true; fi
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)>>>>>Everything Cleaned Successfully<<<<<$(RESET)"


re: fclean all

.PHONY: all clean fclean re
