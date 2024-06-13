#include "push_swap.h"

static int	top(t_stack *stack, int index)
{
	if (index < 0)
		return (stack->numbers[stack->len + index]);
	return (stack->numbers[index]);
}

int	dividing_algo(t_stack *a, t_stack *b)
{
	int	ops;

	ops = 0;
	while (a->len > 0)
	{
		if (top(a, 0) > top(a, 1))
		{
			ops += swap(a);
			p(a, b);
		}
		if (top(b, 0) < top(b, 1))
		{
			ops += swap(b);
			p(a, b);
		}
		ops += push(a, b);
		p(a, b);
	}
	return (ops);
}
