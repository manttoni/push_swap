#include "push_swap.h"

static unsigned int	get_index(t_stack *stack)
{
	unsigned int	index;
	unsigned int	i;

	i = 0;
	index = 0;
	while (i < stack->len)
	{
		if (top(stack, i) < top(stack, 0))
			index++;
		i++;
	}
	return (index);
}

int	golden_cut(t_stack *stack)
{
	int		cut;
	unsigned int	index;

	cut = 70;
	index = get_index(stack);
	return (index < cut * stack->len / 100);
}
