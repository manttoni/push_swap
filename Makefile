# Main Makefile

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = golden_cut.c ascension.c operations.c operations_utils.c push_swap.c validation.c stack_utils.c recorder_utils.c magic_sort.c magic_sort_utils.c

# Libraries
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

# Targets
.PHONY: all libs clean fclean re

all: $(LIBFT) $(FT_PRINTF) $(SRCS)
	$(CC) -g -O2 $(CFLAGS) main.c $(SRCS) $(LIBFT) $(FT_PRINTF) -o push_swap
	$(CC) -g -O2 $(CFLAGS) test.c $(SRCS) $(LIBFT) $(FT_PRINTF) -o test_swap

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

