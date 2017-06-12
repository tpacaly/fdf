# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/08 19:35:38 by tpacaly           #+#    #+#              #
#    Updated: 2017/06/08 19:37:09 by tpacaly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = src/
SRC_NAME = $(SRC_PATH)fdf.c\


LIBFT_PATH = libft/
LIBFT_LIB = libft/libft.a

MINI_PATH = minilibx_macos/
MINI_LIB = minilibx_macos/libmlx.a

CC = gcc
FLAG = -Wall -Wextra -Werror -framework OpenGL -framework AppKit

all: $(NAME)
	$(NAME):
	cd $(LIBFT_PATH) && make re
	cd $(MINI_PATH) && make re
	$(CC) $(FLAG) $(SRC_NAME) $(LIBFT_LIB) $(MINI_LIB)  -o $(NAME)
clean:
	cd $(LIBFT_PATH) && make clean	
	cd $(MINI_PATH) && make clean

fclean:
	cd $(LIBFT_PATH) && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
