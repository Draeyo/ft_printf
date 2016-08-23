NAME = libftprintf.a

SRC_PATH = ./srcs/

SRC_NAME = ft_calc_tag.c ft_conv_c.c ft_conv_d.c ft_conv_o.c ft_conv_p.c \
	  ft_conv_s.c ft_conv_tag.c ft_conv_u.c ft_conv_ws.c ft_conv_x.c \
	  ft_get_tag.c ft_itohex.c ft_itoo.c ft_nblen.c ft_noconv.c \
	  ft_padding.c ft_padding_int.c ft_padding_str.c ft_printf.c ft_putwchar_fd.c \
	  ft_s_atoi.c ft_strcut.c ft_strnewcpy.c ft_strupper.c ft_tag.c ft_uitooa.c \
	  ft_utility.c ft_uxtoa.c ft_valid.c ft_valid2.c ft_xtoa.c ft_xupper.c

LIBFT_PATH = ./libft/

LIBFT_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			 ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
			 ft_lstiter.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
			 ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
			 ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
			 ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
			 ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			 ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
			 ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
			 ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			 ft_wstrcpy.c ft_wstrlen.c
	  
CC = @gcc

CFLAGS = -Wall -Werror -Wextra -I $(INC)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME)) \
	  $(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

OBJ = $(SRC:.c=.o)

INC = ./includes/

all: $(NAME)

$(NAME): makelibft $(OBJ)
	@(ar rc $(NAME) $(OBJ) && ranlib $(NAME))
	@(echo "$(NAME) created.")

makelibft:
	@(make -C libft/)

clean:
	@(/bin/rm -f $(OBJ))
	@(echo "srcs/ folder cleaned.")
	@(make -C libft/ clean)


fclean: clean
	@(/bin/rm -f $(NAME))
	@(echo "$(NAME) deleted.")
	@(make -C libft/ fclean)

re: fclean all
