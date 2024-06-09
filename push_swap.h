#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int	*numbers;
	int	len;
}	t_stack;


void	push_swap(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);

#endif
