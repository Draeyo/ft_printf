NAME = libftprintf.a

SRC = srcs/*.c

OBJ = $(SRC:.c=.o)

INCLUDES = includes/ft_printf.h

LIBFTDIR = libft/

LFT = -lft

all: $(NAME)

$(NAME): $(OBJ) libft
	ar rc $(NAME) $(OBJ) && ranlib $(NAME)

libft:
	$(MAKE) -C $(LIBFTDIR)

$(OBJ):
	gcc -c $(SRC) -Wall -Werror -Wextra -L $(LIBFTDIR) $(LFT)

clean: cleanlib
	/bin/rm -f $(OBJ)

cleanlib:
	$(MAKE) -C clean libft/

fclean: clean fcleanlib
	/bin/rm -f $(NAME)

fcleanlib: cleanlib
	$(MAKE) -C fclean libft/

re: fclean all
