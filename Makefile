# Main Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = main.c test_utils.c magic_sort.c operations.c push_swap.c

# Libraries
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

# Targets
.PHONY: all libs clean fclean re

all: $(LIBFT) $(FT_PRINTF) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) -o push_swap

libs:
	$(MAKE) -C libft
	$(MAKE) -C ft_printf

$(LIBFT):
	$(MAKE) -C libft

$(FT_PRINTF):
	$(MAKE) -C ft_printf

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	rm -f *.o

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	rm -f push_swap

re: fclean all

