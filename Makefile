NAME = libftprintf.a

SRC = srcs/*.c

OBJ = $(SRC:.c=.o)

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
