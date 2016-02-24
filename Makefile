NAME = libftprintf.a

SRC = $(wildcard srcs/*.c) \
	  $(wildcard libft/*.c)

OBJ = $(SRC:.c=.o)

INC = includes/

all: $(NAME)

$(NAME): $(OBJ)
	@(ar rc $(NAME) $(OBJ) && ranlib $(NAME))
	@(echo "Library compilation : OK") 

%.o: %.c
	@(gcc -c $< -o $@ -Wall -Werror -Wextra -I $(INC))
	@(echo "$@ update : OK")

clean:
	@(/bin/rm -f $(OBJ))
	@(echo "Binary files deleted.")

fclean: clean
	@(/bin/rm -f $(NAME))
	@(echo "$(NAME) deleted.")

re: fclean all
