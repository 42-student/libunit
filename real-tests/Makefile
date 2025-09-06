# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smargine <smargine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 01:02:56 by smargine          #+#    #+#              #
#    Updated: 2025/09/07 01:20:10 by smargine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := real_tests
SRCS := main
SRCS += $(addprefix ft_isdigit/, \
	00_ft_isdigit_launcher \
	01_ft_isdigit_basic_test \
	02_ft_isdigit_char_test \
	03_ft_isdigit_null_test \
	04_ft_isdigit_space_test \
)
SRCS += $(addprefix ft_strcmp/, \
	00_ft_strcmp_launcher \
	01_ft_strcmp_basic_test \
	02_ft_strcmp_plus_test \
	03_ft_strcmp_minus_test \
	04_ft_strcmp_null_test \
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
BINS := $(SRCS:%=%.o)
LIBUNITDIR := ../framework
LIBUNIT := $(LIBUNITDIR)/libunit.a
LIBFTDIR := ../libft
LIBFT := $(LIBFTDIR)/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -pedantic -std=c99 -Wconversion -Wshadow
CPPFLAGS := -I$(LIBUNITDIR) -I$(LIBFTDIR)/include
LDFLAGS := -L$(LIBUNITDIR) -L$(LIBFTDIR)
LDLIBS := -lunit -lft

.PHONY: all clean debug fclean re test
all: $(NAME)

$(NAME): $(LIBUNIT) $(BINS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(BINS) -o $@ $(LDFLAGS) $(LDLIBS)

$(LIBUNIT):
	$(MAKE) -C $(LIBUNITDIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -w $(CPPFLAGS) -c $< -o $@

clean:
	rm -fr $(BINS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

test:
	@$(MAKE) all --silent
	@./$(NAME)
