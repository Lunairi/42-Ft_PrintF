# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlu <marvin@student.42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 13:48:43 by mlu               #+#    #+#              #
#    Updated: 2017/06/13 12:45:09 by mlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ./sources/*.c ./libft/*.c

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
HEADER	= includes/

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c -I$(HEADER) -I ./libft $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
