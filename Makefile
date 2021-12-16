SERVER = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTF = ft_printf
HEADER = minitalk.h
HEADER_PRINTF = ft_printf/ft_printf.h
HEADER_LIBFT = ft_printf/libft/libft.h
SRCS = $(SERVER).c $(CLIENT).c
OBJ = $(SRCS:.c=.o)

all:	$(LIB_FT_PRINTF) $(OBJ) $(SERVER) $(CLIENT)

$(SERVER): $(HEADER) $(HEADER_PRINTF) $(HEADER_LIBFT)
	@$(CC) $(CFLAGS) $(SERVER).o $(LIB_FT_PRINTF) -o $(SERVER)

$(CLIENT): $(HEADER) $(HEADER_PRINTF) $(HEADER_LIBFT)
	@$(CC) $(CFLAGS) $(CLIENT).o $(LIB_FT_PRINTF) -o $(CLIENT)

$(LIB_FT_PRINTF):
	@make -C $(FT_PRINTF)

clean:
	@make clean -C $(FT_PRINTF)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(FT_PRINTF)
	@rm -f $(SERVER) $(CLIENT)

re: fclean all
.PHONY: all clean fclean re
