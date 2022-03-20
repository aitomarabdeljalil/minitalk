CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
CSRC	:= client.c
SSRC	:= server.c
CBSRC	:= client_bonus.c
SBSRC	:= server_bonus.c
OBJ		:= $(patsubst %.c, %.o, $(CSRC) $(SSRC) $(CBSRC) $(SBSRC))
CNAME	:= client
SNAME	:= server
CBNAME	:= client_bonus
SBNAME	:= server_bonus

.PHONY: all clean fclean re

all: $(CNAME) $(SNAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean:
	make -C libft fclean
	rm -f $(OBJ) $(CNAME) $(CBNAME) $(SNAME) $(SBNAME)

re: fclean all

bonus: $(CBNAME) $(SBNAME)

libft/libft.a:
	make -C libft

$(CNAME): $(CSRC) libft/libft.a minitalk.h
	$(CC) $(CFLAGS) -o $(CNAME) $(CSRC) libft/libft.a

$(SNAME): $(SSRC) libft/libft.a minitalk.h
	$(CC) $(CFLAGS) -o $(SNAME) $(SSRC) libft/libft.a

$(CBNAME): $(CBSRC) libft/libft.a minitalk.h
	$(CC) $(CFLAGS) -o $(CBNAME) $(CBSRC) libft/libft.a

$(SBNAME): $(SBSRC) libft/libft.a minitalk.h
	$(CC) $(CFLAGS) -o $(SBNAME) $(SBSRC) libft/libft.a
