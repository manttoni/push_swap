#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int	*numbers;
	int	len;
}	t_stack


void	push_swap(int *stack_a, int *stack_b);
void	swap(t_stack stack);

#endif
