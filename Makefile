NAME = so_long

SRC = checkers.c checkers2.c create_destroy_map.c hooks_and_rules.c so_long.c utils_linked_lists.c utils.c 

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

all: $(NAME)

$(%.o): $(%.c)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) *.o
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all bonus clean fclean re