NAME = so_long

SRC = so_long.c utils.c get_next_line.c 

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(%.o): $(%.c)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) *.o
	make clean -C mlx/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re