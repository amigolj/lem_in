#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 16:43:49 by mkurchin          #+#    #+#              #
#    Updated: 2017/04/19 16:43:50 by mkurchin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FL = -Wall -Wextra -Werror

SRC = ft_add_fl.c ft_atoi.c ft_bzero.c \
	ft_handle_num.c ft_handle_fl_num_u.c ft_handle_fl_str.c \
	ft_isdigit.c ft_itoa_base.c ft_parse.c ft_print_mod.c \
		ft_printf.c ft_putchar.c ft_putstr.c ft_putstr2.c ft_putstr_n.c \
		ft_sv_fl.c ft_strlen_wchr.c ft_strlen.c wchar.c \
		ft_hndl_fl_num.c ft_hndl_num2.c ft_hndl_num_u.c ft_hndl_num_u2.c ft_hndl_is_sign_base.c \
		wchar2.c hndl_fl_s.c ft_printf_add.c


OBJ = ft_add_fl.o ft_atoi.o ft_bzero.o \
	ft_handle_num.o ft_handle_fl_num_u.o ft_handle_fl_str.o \
	ft_isdigit.o ft_itoa_base.o ft_parse.o ft_print_mod.o \
		ft_printf.o ft_putchar.o ft_putstr.o ft_putstr2.o ft_putstr_n.o \
		ft_sv_fl.o ft_strlen_wchr.o ft_strlen.o wchar.o \
		ft_hndl_fl_num.o ft_hndl_num2.o ft_hndl_num_u.o ft_hndl_num_u2.o ft_hndl_is_sign_base.o \
		wchar2.o hndl_fl_s.o ft_printf_add.o

all: $(NAME)

$(NAME):
	gcc -c $(FL) $(SRC)  
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all