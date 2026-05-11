# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/01 23:56:20 by sgadinga          #+#    #+#              #
#    Updated: 2026/05/02 02:34:46 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := harena.a
CC := cc
CFLAGS := -Wall -Werror -Wextra -Iincludes -I../libft/includes
ARCHIVE := ar rcs

SRC_DIR := src
OBJ_DIR := obj

SRCS := $(addprefix $(SRC_DIR)/, harena_init.c harena_create.c harena_alloc.c harena_save.c harena_restore.c harena_calloc.c harena_reset.c harena_destroy.c harena_free.c)
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
