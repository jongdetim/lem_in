# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tide-jon <tide-jon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/26 16:43:01 by tide-jon       #+#    #+#                 #
#    Updated: 2019/09/13 15:23:56 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		lem-in

LIBFT =		libft/libft.a

FILES =		main.c input_check.c lem_in.c validate_format.c \
			bfs.c pathing.c combos.c print.c trim_graph.c

SRCS =		$(FILES:%=src/%)

OBJECTS =	$(SRCS:src/%.c=obj/%.o)

FLAGS =		-g -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
			@ gcc $(FLAGS) -o $@ $(OBJECTS) -L ./libft/ -lft
			@ echo "lem-in executable compiled"

$(LIBFT):
	 		@ make -C ./libft/

obj/%.o : src/%.c lem_in.h
			@ gcc $(FLAGS) $< -c -o $@ -I ./lem_in.h

clean :
			@ make clean -C ./libft/ && rm -f $(OBJECTS)

fclean :
			@ make fclean -C ./libft/ && rm -f $(NAME) && \
			rm -f $(OBJECTS)

re : fclean all

.PHONY: clean fclean all re
