#include "push_swap.h"
#include <stdio.h>
#include <time.h>

void	p(t_stack *a, t_stack *b)
{
	int i = 0;

	while (i < a->len || i < b->len)
	{
		if (i < a->len)
			printf("%d\t", a->numbers[i]);
		else
			printf("  \t");
		if (i < b->len)
			printf("%d", b->numbers[i]);
		printf("\n");
		i++;
	}
	printf("==========\na\tb\n------------------------\n");
}

int	is_ascending(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
	p(a,b);
	while (a->len != 0)
	{
		if (compare(a, b) >= 0)
			ops += push(a, b);
		while (compare(a, b) < 0)
			ops += rotate(a) + push(b, a) + rotate_reverse(a);
	}
	while (b->len != 0)
		ops += push(b, a);
	printf("Ops: %d\nTime: %fms\n", ops, 1000 * ((double)clock() / CLOCKS_PER_SEC));
}
