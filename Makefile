# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tide-jon <tide-jon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/26 16:43:01 by tide-jon       #+#    #+#                 #
#    Updated: 2019/09/16 20:14:31 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		lem-in

LIBFT =		libft/libft.a

FILES =		main.c input_check.c validate_format.c connect_graph.c \
			bfs.c pathing.c combos.c print.c trim_graph.c get_rooms.c \
			spawn_ants.c build_graph.c combo_helper.c

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
			@ mkdir -p obj
			@ gcc $(FLAGS) $< -c -o $@

clean :
			@ make clean -C ./libft/ && rm -f $(OBJECTS)

fclean :
			@ make fclean -C ./libft/ && rm -f $(NAME) && \
			rm -f $(OBJECTS)

re : fclean all

.PHONY: clean fclean all re
