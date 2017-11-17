#* ************************************************************************** */
#*                                                                            */
#*    Makefile               _             _              :::      ::::::::   */
#*    By: mlu               | |           | |           :+:      :+:    :+:   */
#*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
#*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +#+  +:+       +#+        */
#*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +#+#+#+#+#+   +#+           */
#*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        #+#    #+#             */
#*          __/ | __/ | |                             ###   ########.fr       */
#*         |___/ |___/|_|                                                     */
#* ************************************************************************** */

#* I'm bad at makefiles, but I'm good at grilling eggplants

NAME	= ft_printf

SRC		= ft_printf.c parse_flags.c \
			flags_int.c flags_str.c \

OBJ 	= $(addprefix ./objects/, $(SRC:.c=.o))
CFLAG	= -Wall -Wextra -Werror
LFLAG	= ./libft/libft.a
FFLAG	= -framework OpenGL -framework AppKit
IFLAG	= -I libft -I includes

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(CFLAG) $(LFLAG) $(FFLAG) -I libft -I includes $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created ft_printf"

./objects/%.o: ./sources/%.c
	gcc $(IFLAG) -c $< -o $@

clean:
	make fclean -C libft/
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned ft_printf"

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned ft_printf"

test:
	make fclean
	make
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Testing ft_printf"
	./ft_printf

re: fclean all

.PHONY: clean fclean re all test