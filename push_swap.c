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

void	push_swap(t_stack *a, t_stack *b)
{
	int	ops;

	ops = 0;
	p(a,b);
	while (!is_ascending(a) || b->len != 0)
	{
		if (a->numbers[0] > a->numbers[1] && a->len >= 2)
		{
			ops++;
			swap(a);
			p(a,b);
			continue;
		}
		ops++;
		push(a, b);
		p(a,b);
		if (a->len == 0)
		{
			while (b->len != 0)
			{
				ops++;
				push(b, a);
				p(a,b);
			}
		}
	}
	p(a,b);
	printf("Ops: %d\nTime: %fms\n", ops, 1000 * ((double)clock() / CLOCKS_PER_SEC));
}
