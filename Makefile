INCLUDES = -Ilibft/Includes -I.

LIB = libft

LIB.A = libft.a

LI_SRC_NAME = input_check.c lem_in.c main.c validate_format.c trim_graph.c

LI_OBJ_NAME = $(LI_SRC_NAME:.c=.o)

SRC_PATH = src

OBJ_PATH = obj

LI_SRC = $(addprefix $(SRC_PATH)/, $(LI_SRC_NAME))

LI_OBJ = $(addprefix $(OBJ_PATH)/, $(LI_OBJ_NAME))

NAME_C = lem_in

FLAGS = -Wall -Wextra -Werror

all : library $(NAME_C)

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
