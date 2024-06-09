#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int i = 0;
	printf("Length: %d\n", stack->len);
	while (i < stack->len)
		printf("%d ", stack->numbers[i++]);
	printf("\n");
}

void	p(t_stack *a, t_stack *b)
{
	printf("========\n");
	printf("Stack a:\n");
	print_stack(a);
	printf("Stack b:\n");
	print_stack(b);
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
	while (!is_ascending(a) || !is_ascending(b))
	{
		p(a, b);
		if (a->numbers[0] > a->numbers[1])
			swap(a);
		push(a, b);
		if (a->len == 0)
			while (b->len != 0)
				push(b, a);
	}
	p(a,b);
}
