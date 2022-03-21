NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_strchr.c ft_strlen.c ft_strrchr.c \
ft_tolower.c ft_toupper.c ft_strlcpy.c ft_strlcat.c ft_atoi.c \
ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c \
ft_putnbr_fd.c ft_strmapi.c ft_strncmp.c ft_split.c ft_striteri.c \
ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstlast.c ft_lstiter.c \
ft_lstdelone.c ft_lstadd_front.c ft_lstadd_back.c get_next_line.c

OBJ := $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all