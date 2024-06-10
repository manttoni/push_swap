#include "push_swap.h"

/* Compare top of stacks
 * Return
 * 0 if one is empty
 * + if a is bigger
 * - if b is bigger */
int	compare(t_stack *a, t_stack *b)
{
	if (a->len == 0 || b->len == 0)
		return (0);
	return (a->numbers[0] - b->numbers[0]);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	ops;

	ops = 0;
	while (a->len != 0)
	{
		if (compare(a, b) >= 0)
			ops += push(a, b);
		while (compare(a, b) < 0)
			ops += rotate(a) + push(b, a) + rotate_reverse(a);
	}
	while (b->len != 0)
		ops += push(b, a);
	ft_printf("Ops: %d\n", ops);
}
