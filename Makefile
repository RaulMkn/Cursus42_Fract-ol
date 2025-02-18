# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 21:07:40 by rmakende          #+#    #+#              #
#    Updated: 2025/02/18 21:44:59 by rmakende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3


MINILIBX_DIR = ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a
LIBS = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

LIBFT_DIR = ./Libft
LIBRARY = $(LIBFT_DIR)/libft.a
LIB_HEADERS = $(LIBFT_DIR)/libft.h

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINT_HEADERS = $(PRINTF_DIR)/ft_printf.h

SRCS = fractol.c

OBJS = $(SRCS:.c=.o)
NAME = fractol

all: $(LIBRARY) $(PRINTF) $(MINILIBX) $(PRINTF) $(NAME)

$(MINILIBX):
	cd $(MINILIBX_DIR) && $(MAKE)

$(LIBRARY):
	cd $(LIBFT_DIR) && $(MAKE)

$(PRINTF):
	cd $(PRINTF_DIR) && $(MAKE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBRARY) $(PRINTF) $(MINILIBX) $(LIBS)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	cd $(MINILIBX_DIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(MINILIBX_DIR) && $(MAKE) clean

re: fclean all

.PHONY: all clean fclean re
