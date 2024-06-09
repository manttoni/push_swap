#include "push_swap.h"
#include <stdio.h>

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

void	push_swap(t_stack *a, t_stack *b)
{
	int	ops;

	ops = 0;
	while (!is_ascending(a) || b->len != 0)
	{
		p(a, b);
		if (a->numbers[0] > a->numbers[1])
		{
			ops++;
			swap(a);
		}
		ops++;
		push(a, b);
		if (a->len == 0)
		{
			while (b->len != 0)
			{
				ops++;
				push(b, a);
			}
		}
	}
	p(a,b);
	printf("Ops: %d\n", ops);
}
