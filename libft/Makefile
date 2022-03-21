CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
NAME	:= libft.a
SRC		:= ft_atoi.c ft_isdigit.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c
OBJ		:= $(patsubst %.c, %.o, $(SRC))
OBJ_BN 	:= $(patsubst %.c, %.o, $(SRC_BN))

.PHONY: all clean fclean re bonus

all: $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BN)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJ_BN)
	@ar rc $(NAME) $(OBJ) $(OBJ_BN)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
