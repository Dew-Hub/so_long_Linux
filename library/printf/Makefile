# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 22:57:39 by buonturk          #+#    #+#              #
#    Updated: 2023/11/06 22:59:44 by buonturk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

SRC			=	ft_printf.c ft_printf_utils.c

OBJ			=	$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
