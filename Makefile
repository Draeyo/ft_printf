NAME = libftprintf.a

SRC = $(wildcard srcs/*.c) \
	  $(wildcard libft/*.c)

OBJ = $(SRC:.c=.o)

INC = includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) && ranlib $(NAME)

%.o: %.c
	gcc -c $< -o $@ -Wall -Werror -Wextra -I $(INC)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
