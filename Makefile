#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/28 15:28:47 by mkurchin          #+#    #+#              #
#    Updated: 2017/09/28 15:29:03 by mkurchin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem_in
LIB_NAME = libft.a
LIB_PATH = ./libft/
PRINTF_NAME = libftprintf.a
PRINTF_PATH = ./ft_printf/
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_NAME))
CC = gcc
SRC = main.c get_next_line.c ft_init_struct.c hndl_data.c hndl_route.c \
 del_cross_rt.c output_ant.c parse_data.c bypass.c bypass_core.c \
 hndl_data2.c hndl_route2.c valid_data.c free_mem.c valid_data2.c \
 sort_routes.c output_ant2.c parse_data2.c hndl_route3.c out_map.c
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		@make -C ft_printf
		gcc $(FLAGS) $(OBJ) $(LIB) $(PRINTF) -o $(NAME)

clean:
		@make fclean -C libft/
		@make fclean -C ft_printf/
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all