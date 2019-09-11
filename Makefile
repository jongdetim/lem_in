# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tide-jon <tide-jon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/26 16:43:01 by tide-jon       #+#    #+#                 #
#    Updated: 2019/09/04 14:01:00 by awehlbur      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

INCLUDES =		-Ilibft/Includes -I.

LIB =			libft

LIB.A =			libft.a

LI_SRC_NAME =	input_check.c lem_in.c main.c validate_format.c trim_graph.c \
				bfs.c pathing.c combos.c print_solution.c

LI_OBJ_NAME =	$(LI_SRC_NAME:.c=.o)

SRC_PATH =		src

OBJ_PATH =		obj

LI_SRC =		$(addprefix $(SRC_PATH)/, $(LI_SRC_NAME))

LI_OBJ =		$(addprefix $(OBJ_PATH)/, $(LI_OBJ_NAME))

NAME_C =		lem_in

FLAGS =			-Wall -Wextra -Werror

all : 			library $(NAME_C)

library :
				make -C $(LIB)

$(NAME_C) : $(LI_OBJ)
				gcc -g -o $@ $(LI_OBJ) $(INCLUDES) $(LIB)/$(LIB.A)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
				@mkdir -p $(OBJ_PATH)
				@mkdir -p $(dir $(LI_OBJ))
				gcc -g -o $@ -c $< $(INCLUDES) $(FLAGS)

clean :
				rm -fr $(OBJ_PATH)
				make clean -C $(LIB)

fclean : clean
				rm -f $(NAME_C)
				make fclean -C $(LIB)

re : fclean all
