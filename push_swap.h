#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	a_len;
	int	*stack_b;
	int	b_len;
}	t_stacks


void	push_swap(int *stack_a, int *stack_b);
void	swap(int *stack);

#endif
