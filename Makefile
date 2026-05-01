# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/01 23:56:20 by sgadinga          #+#    #+#              #
#    Updated: 2026/05/02 01:57:18 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := harena.a
CC := cc
CFLAGS := -Wall -Werror -Wextra -Iincludes -Ilibft/includes
ARCHIVE := ar rcs

SRC_DIR := src
OBJ_DIR := obj

SRCS := $(addprefix $(SRC_DIR)/, harena_create.c harena_alloc.c harena_reset.c harena_destroy.c harena_save.c harena_restore.c harena_calloc.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

test: $(NAME)
	$(MAKE) -C tests run

$(NAME): $(OBJS)
	$(ARCHIVE) $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C tests clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C tests fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
