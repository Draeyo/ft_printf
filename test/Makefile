NAME = libftprintf.a

SRC = srcs/*.c \
	  libft/*.c

OBJ = *.o

INC = includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) && ranlib $(NAME)

$(OBJ):
	gcc -c $(SRC) -Wall -Werror -Wextra -I $(INC)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
