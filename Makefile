NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

SRC_FILES = ft_printf.c \
			ft_printf_csint_utils.c \
			ft_printf_hex_utils.c \
			ft_printf_uint_utils.c \
			ft_printf_voidp_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
	ar -crs $(NAME) $@

libft:
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f *.o

fclean: clean
	rm -f $(LIBFT_DIR)/libft.a
	rm -f $(NAME)

re: fclean $(NAME)

test: $(NAME) libft
	$(CC) $(FLAGS) -g3 -o test.out *.c -L. -l:libftprintf.a -Llibft -l:libft.a

rmtest:
	rm test.out

.PHONY : libft clean fclean re test rmtest
