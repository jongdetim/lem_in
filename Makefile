# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tide-jon <tide-jon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/26 16:43:01 by tide-jon       #+#    #+#                 #
#    Updated: 2019/09/09 18:48:33 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		lem-in

LIBFT =		libft/libft.a

FILES =		input_check.c main.c validate_format.c build_graph.c \
			bfs.c pathing.c combos.c combos2.c print1.c trim_graph.c \
			build_hash.c help_build.c parse_links.c print2.c

SRCS =		$(FILES:%=src/%)

OBJECTS =	$(addprefix obj/, $(SRCS:src/%.c=%.o))

FLAGS =		-Wall -Wextra -Werror

all : $(MKDIR) $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
			gcc $(FLAGS) -o $@ $(OBJECTS) -L ./libft/ -lft
			echo "lem-in executable compiled"

$(LIBFT):
	 		make -C ./libft/

./obj/%.o : src/%.c
			mkdir -p obj
			gcc $(FLAGS) $< -c -o $@

clean :
			@ make clean -C ./libft/ && rm -f $(OBJECTS)

fclean :
			@ make fclean -C ./libft/ && rm -f $(NAME) && \
			rm -f $(OBJECTS)

re : fclean all

.PHONY: clean fclean all re
