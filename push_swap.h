#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct	s_stack
{
	int		*numbers;
	unsigned int	len;
}	t_stack;

typedef	struct	s_recorder
{
	char			**operations;
	unsigned int	len;
	size_t			allocated;
}	t_recorder;

void			print(t_stack *a, t_stack *b);

void			free_recorder(t_recorder *recorder);
int				get_next_unsorted(t_stack *a);
int				validate_input(int argc, char **argv);
void			least_rotations(t_stack *a, t_stack *b, int *rotations);
int				operate(char *operation, t_stack *a, t_stack *b, t_recorder *recorder);
int				record(t_recorder *recorder, char *operation);
t_recorder		*init_recorder(t_recorder *recorder);
t_stack			*init_stack(t_stack *stack, int stack_max);
void			find_simultaneous(t_recorder *recorder);
t_recorder		*push_swap(int argc, char **argv);
int				swap(t_stack *stack);
int				push(t_stack *from, t_stack *to);
int				rotate(t_stack *stack);
int				rotate_reverse(t_stack *stack);
int				magic_sort(t_stack *a, t_stack *b, t_recorder *recorder);
unsigned int	absolute(int i);
int				top(t_stack *stack, int index);
int				is_ascending(t_stack *stack);

#endif
