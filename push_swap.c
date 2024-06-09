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
	printf("Stack a:\n");
	print_stack(a);
	printf("Stack b:\n");
	print_stack(b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	p(a, b);
	rotate(a);
	p(a,b);
	rotate_reverse(a);
	p(a, b);
}
