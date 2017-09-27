# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shazan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 16:07:28 by shazan            #+#    #+#              #
#    Updated: 2016/06/21 15:12:22 by shazan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = lem-in

CC = gcc

LIB = libft/libft.a

FLAG = -Wall -Wextra -Werror -O3

LIBGRPH = -lmlx -framework OpenGL -framework Appkit

INC = lem.h

OBJ =  main.o keep_salle.o keep_lien.o test.o aff.o algo.o parse.o

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		@$(CC) $(FLAG) $(OBJ) $(LIB) -o $(NAME) $(LIBGRPH)

$(LIB):
		@echo "\033[33mLibft compilation\033[0m"
		@make -C libft/
		@echo "\033[33mProject compilation\033[0m"
		@echo "\033[32mCompilation SUCCESS\033[0m"

%.o : %.c $(INC)
		@$(CC) -c $(FLAG) $< -o $@

clean:
				@echo "\033[33m.o's cleaning\033[0m"
				@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
		@rm -rf $(NAME)

re: fclean all
