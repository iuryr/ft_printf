NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

SRC_FILES = ft_printf.c \
			ft_printf_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $< -o $@
	ar -crs $(NAME) $@

libft:
	make -C $(LIBFT_DIR) libft.a

clean:
	make -C $(LIBFT_DIR) clean
	rm -f *.o

fclean: clean
	rm -f $(LIBFT_DIR)/libft.a
	rm -f $(NAME)

re: fclean $(NAME)

test: $(NAME) libft
	$(CC) $(FLAGS) -o test.out -Ilibft test.c -L. -l:libftprintf.a -Llibft -l:libft.a

rmtest:
	rm test.out

.PHONY : libft clean fclean re test rmtest
