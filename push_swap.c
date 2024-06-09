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

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("Stack a:\n");
	print_stack(a);
	printf("Stack b:\n");
	print_stack(b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	print_stacks(a, b);
	swap(a);
	swap(b);
	print_stacks(a, b);
	push(a, b);
	print_stacks(a, b);
}
