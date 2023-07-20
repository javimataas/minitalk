# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 17:03:31 by jmatas-p          #+#    #+#              #
#    Updated: 2022/11/28 17:46:52 by jmatas-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

CC 		= 	gcc

CFLAGS 	= 	-Wall -Werror -Wextra

SRC		=  	ft_printf.c \
     		ft_printf_utils.c \
     		ft_printnbr_unsigned.c \
     		ft_itoa.c \
	 		ft_printhex.c \
	 		ft_printptr.c

INCLUDE	= 	ft_printf.h

OBJ 	= 	$(SRC:.c=.o)

all: 		$(NAME)

$(NAME):  	$(OBJ) $(INCLUDE)
			ar rcs $(NAME) $(OBJ)

.o: 		.c
			$(CC) -c $(CFLAGS) $(SRC) -I $(INCLUDE)


clean:
			rm -rf $(OBJ)

fclean:
			rm -rf $(OBJ)
			rm -rf $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
