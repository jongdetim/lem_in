# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tide-jon <tide-jon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/28 18:20:08 by tide-jon       #+#    #+#                 #
#    Updated: 2019/09/16 19:10:12 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror -c

SOURCES =	atoi bzero digcount isalnum isalpha isascii isdigit isprint \
		iswhitespace itoa lstadd lstaddend lstdel lstdelone lstiter \
		lstmap lstnew lstprintelemsizes memalloc memccpy memchr memcmp \
		memcpy memdel memmove memset putchar_fd putchar putendl \
		putnbr_fd putnbr putstr_fd putstr strcat strchr strclr strcmp \
		strcount strcpy strdel strdup strequ striter strjoin strlcat \
		strlen strmap strmapi strncat strncmp strncpy strnequ strnew \
		strnstr strrchr strsplit strstr strsub strtrim tolower toupper \
		putendl_fd striteri get_next_line digcountbase itoabase \
		putllnbr putullnbr ftoa strtoupper getnum chararrfree abs sqrt \
		power pythagoras printf conv_csp conv_di conv_u conv_o conv_x \
		conv_prcnt conv_f conv_x2 conv_o2 conv_di2 parsing dispatcher hashing \
		primes error get_substr

CFILE = $(SOURCES:%=ft_%.c)

OBJECTS = $(SOURCES:%=ft_%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@ ar rc $(NAME) $(OBJECTS)
		@ ranlib $(NAME)
		@ echo library compiled

%.o:	 %.c
		@ $(CC) $(CFLAGS) $< -o $@

clean:
		@ rm -f $(OBJECTS)
		@ echo clean completed

fclean:	 clean
		@rm -f $(NAME)

re:	 fclean all
