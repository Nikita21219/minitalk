NAME = libftprintf.a
LIBFT = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
LIBFT_DIR = libft/
SRC = ft_printf.c print_hexnum.c print_hexnum_p.c \
		ft_print_void_ptr.c print_number.c print_unsigned_number.c
OBJ = $(SRC:.c=.o)
.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
$(NAME):    $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(LIBFT) .
	@mv $(LIBFT) $(NAME)
	@ar -rc $(NAME) $(OBJ)
all:	$(NAME)
clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
	@rm -f $(LIBFT_DIR)$(LIBFT)
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
