# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/02 01:52:24 by sgadinga          #+#    #+#              #
#    Updated: 2026/05/02 01:52:24 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := tests
CC := cc
CFLAGS := -Wall -Werror -Wextra -I../includes -I../libft/includes

SRC_DIR := .
SRCS := $(SRC_DIR)/test_harena.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

../libft/libft.a:
	$(MAKE) -C ../libft

$(NAME): $(OBJS) ../harena.a ../libft/libft.a
	$(CC) $(OBJS) ../harena.a ../libft/libft.a -lm -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all run
