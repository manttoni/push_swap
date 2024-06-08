#include "push_swap.h"

void	swap(t_stacks stacks, char c)
{
	int	tmp;
	int	*stack;

	if (c == 'a')
		stack = stacks.stack_a;
	else if (c == 'b')
		stack = stacks.stack_b;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	push(t_stacks stacks, char c)
{
	
