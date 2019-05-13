# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/11 15:00:18 by krioliin       #+#    #+#                 #
#    Updated: 2019/05/13 19:28:00 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
LIB		= libft/libft.a
CFLAGS	= -Wall -Wextra -Werror
FILES	= main main_algoritm serve_data file_validation \
 print_map auxiliary_funcs auxiliary_funcs2
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):
	make -C libft/ clean && make -C libft/
	clang -o $(NAME) $(SRC) $(LIB) $(CFLAGS)

run_fillit:
	clang -o $(NAME) $(SRC) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all